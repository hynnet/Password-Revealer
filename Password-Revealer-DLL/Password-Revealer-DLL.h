// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 PASSWORDREVEALERDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// PASSWORDREVEALERDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
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

// 此类是从 Password-Revealer-DLL.dll 导出的
class PASSWORDREVEALERDLL_API CPasswordRevealerDLL {
public:
	CPasswordRevealerDLL(void);
	// TODO:  在此添加您的方法。
};

extern PASSWORDREVEALERDLL_API HINSTANCE g_hmod; // 全局句柄

extern PASSWORDREVEALERDLL_API HHOOK g_hHook; // 全局钩子函数句柄

PASSWORDREVEALERDLL_API LRESULT CALLBACK HookProc(int code, WPARAM wParam, LPARAM lParam);

PASSWORDREVEALERDLL_API void InstallHook();

PASSWORDREVEALERDLL_API void UninstallHook();

extern HINSTANCE g_hInstance; // 全局句柄
