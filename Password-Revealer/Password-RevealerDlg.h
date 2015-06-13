
// Password-RevealerDlg.h : 头文件
//

#pragma once


// CPasswordRevealerDlg 对话框
class CPasswordRevealerDlg : public CDialogEx
{
// 构造
public:
	CPasswordRevealerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PASSWORDREVEALER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 是否处于获取密码状态
	BOOL m_isReveal;
	afx_msg void OnBnClickedReveal();
	afx_msg void OnDestroy();
	// 密码演示输入框值
	CString m_demoVal;
};
