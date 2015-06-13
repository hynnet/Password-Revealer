// Password-Revealer-DLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Password-Revealer-DLL.h"
#include <tchar.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "advapi32.lib")

PASSWORDREVEALERDLL_API HINSTANCE g_hmod = NULL;

// ȫ�ֵĹ��Ӻ������
PASSWORDREVEALERDLL_API HHOOK g_hHook = NULL;

// ��깳�Ӻ�����
PASSWORDREVEALERDLL_API LRESULT CALLBACK HookProc(int code, WPARAM wParam, LPARAM lParam)
{
	HWND hwnd;
	POINT point;
	LRESULT result;

	result = CallNextHookEx(g_hHook, code, wParam, lParam);

	OutputDebugString(_T("in\t"));
//	MessageBox(NULL, _T("Test"), _T("Debug"), MB_OK);
	GetCursorPos(&point); // �õ����λ��
	hwnd = ::WindowFromPoint(point); // ͨ�������ô��ھ��
	if (hwnd != NULL)
	{
		long nStyle = ::GetWindowLong(hwnd, GWL_STYLE);// ��ô��ڷ��

		if (nStyle & ES_PASSWORD) // �Ƿ�Ϊ���������
		{
			EVENTMSG *event = (EVENTMSG *)lParam;

			::PostMessage(hwnd, EM_SETPASSWORDCHAR, 0, 0); // ȥ����������
			ShowWindow(hwnd, SW_SHOWNORMAL);
			if (event->message == WM_LBUTTONDOWN) // �Ҽ������ʾ������Ϣ
			{
//				::PostMessage(hwnd, EM_SETPASSWORDCHAR, 0, 0);//ȥ���ܴa����
				MessageBox(hwnd, _T("is Password Input"), _T("Debug"), MB_OK);
			}
		}
	}
	return result;
}

PASSWORDREVEALERDLL_API void InstallHook()
{
	DWORD err;
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;

	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return;

	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
		&tkp.Privileges[0].Luid);

	tkp.PrivilegeCount = 1; // one privilege to set  
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,
		(PTOKEN_PRIVILEGES)NULL, 0);

	if (GetLastError() != ERROR_SUCCESS)
		return;

//	g_hHook = SetWindowsHookEx(WH_JOURNALRECORD, HookProc, GetModuleHandle(NULL), 0);
//	g_hHook = (HHOOK)SetWindowsHookEx(WH_JOURNALRECORD, (HOOKPROC)HookProc, g_hInstance, 0);
	g_hHook = (HHOOK)SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)HookProc, g_hInstance, 0);
//	g_hHook = (HHOOK)SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)HookProc, GetModuleHandle(NULL), 0);
	MessageBox(NULL, g_hHook != NULL ? _T("is True") : _T("is False!"), _T("Debug"), MB_OK);
	if (g_hHook == NULL)
	{
		err = GetLastError();
	}
}

PASSWORDREVEALERDLL_API void UninstallHook()
{
	if (g_hHook)
	{
		UnhookWindowsHookEx(g_hHook);//ж�d�^��
		g_hHook = NULL;
	}
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Password-Revealer-DLL.h
CPasswordRevealerDLL::CPasswordRevealerDLL()
{
	return;
}
