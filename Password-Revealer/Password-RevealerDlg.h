
// Password-RevealerDlg.h : ͷ�ļ�
//

#pragma once


// CPasswordRevealerDlg �Ի���
class CPasswordRevealerDlg : public CDialogEx
{
// ����
public:
	CPasswordRevealerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PASSWORDREVEALER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// �Ƿ��ڻ�ȡ����״̬
	BOOL m_isReveal;
	afx_msg void OnBnClickedReveal();
	afx_msg void OnDestroy();
	// ������ʾ�����ֵ
	CString m_demoVal;
};
