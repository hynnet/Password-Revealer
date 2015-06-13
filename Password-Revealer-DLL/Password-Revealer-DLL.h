// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� PASSWORDREVEALERDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// PASSWORDREVEALERDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef PASSWORDREVEALERDLL_EXPORTS
#define PASSWORDREVEALERDLL_API __declspec(dllexport)
#else
#define PASSWORDREVEALERDLL_API __declspec(dllimport)
#ifndef _USRDLL
	#ifndef WIN64
		#ifdef _DEBUG
			#define _DLL_LIBNAME_ "Password-RevealerD.lib"
		#else
			#define _DLL_LIBNAME_ "Password-Revealer.lib"
		#endif	// _DEBUG
	#else
		#ifdef _DEBUG
			#define _DLL_LIBNAME_ "Password-RevealerD-x64.lib"
		#else
			#define _DLL_LIBNAME_ "Password-Revealer-x64.lib"
		#endif	// _DEBUG
	#endif	// WIN64
	#pragma comment(lib, _DLL_LIBNAME_)
	#pragma message("Automatically linking with " _DLL_LIBNAME_)
#endif	// _USRDLL
#endif

// �����Ǵ� Password-Revealer-DLL.dll ������
class PASSWORDREVEALERDLL_API CPasswordRevealerDLL {
public:
	CPasswordRevealerDLL(void);
	// TODO:  �ڴ�������ķ�����
};

extern PASSWORDREVEALERDLL_API HINSTANCE g_hmod; // ȫ�־��

extern PASSWORDREVEALERDLL_API HHOOK g_hHook; // ȫ�ֹ��Ӻ������

PASSWORDREVEALERDLL_API LRESULT CALLBACK HookProc(int code, WPARAM wParam, LPARAM lParam);

PASSWORDREVEALERDLL_API void InstallHook();

PASSWORDREVEALERDLL_API void UninstallHook();

extern HINSTANCE g_hInstance; // ȫ�־��
