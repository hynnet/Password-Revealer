// Password-Revealer-DLL.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Password-Revealer-DLL.h"
#include <tchar.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "advapi32.lib")

PASSWORDREVEALERDLL_API HINSTANCE g_hmod = NULL;

// 全局的钩子函数句柄
PASSWORDREVEALERDLL_API HHOOK g_hHook = NULL;

// 鼠标钩子函数。
PASSWORDREVEALERDLL_API LRESULT CALLBACK HookProc(int code, WPARAM wParam, LPARAM lParam)
{
	HWND hwnd;
	POINT point;
	LRESULT result;

	result = CallNextHookEx(g_hHook, code, wParam, lParam);

	OutputDebugString(_T("in\t"));
//	MessageBox(NULL, _T("Test"), _T("Debug"), MB_OK);
	GetCursorPos(&point); // 得到鼠标位置
	hwnd = ::WindowFromPoint(point); // 通过坐标获得窗口句柄
	if (hwnd != NULL)
	{
		long nStyle = ::GetWindowLong(hwnd, GWL_STYLE);// 获得窗口风格

		if (nStyle & ES_PASSWORD) // 是否为密码输入框
		{
			EVENTMSG *event = (EVENTMSG *)lParam;

			::PostMessage(hwnd, EM_SETPASSWORDCHAR, 0, 0); // 去掉密码属性
			ShowWindow(hwnd, SW_SHOWNORMAL);
			if (event->message == WM_LBUTTONDOWN) // 右键点击显示调试信息
			{
//				::PostMessage(hwnd, EM_SETPASSWORDCHAR, 0, 0);//去掉密碼屬性
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
		UnhookWindowsHookEx(g_hHook);//卸載鉤子
		g_hHook = NULL;
	}
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 Password-Revealer-DLL.h
CPasswordRevealerDLL::CPasswordRevealerDLL()
{
	return;
}
