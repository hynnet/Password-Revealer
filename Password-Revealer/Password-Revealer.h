
// Password-Revealer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPasswordRevealerApp: 
// �йش����ʵ�֣������ Password-Revealer.cpp
//

class CPasswordRevealerApp : public CWinApp
{
public:
	CPasswordRevealerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPasswordRevealerApp theApp;