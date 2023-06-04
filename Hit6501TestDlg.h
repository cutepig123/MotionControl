// Hit6501TestDlg.h : header file
//

#if !defined(AFX_HIT6501TESTDLG_H__B42E2B9C_2D0A_4085_B2E0_03D4B0CA06AE__INCLUDED_)
#define AFX_HIT6501TESTDLG_H__B42E2B9C_2D0A_4085_B2E0_03D4B0CA06AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHit6501TestDlg dialog

class CHit6501TestDlg : public CDialog
{
// Construction
public:
	void AddText(char *szFormat,...);
	CHit6501TestDlg(CWnd* pParent = NULL);	// standard constructor

	DWORD WINAPI CheckVelProc();	//检查堵转情况
	void StartProc()	;
	HANDLE m_hThread;
// Dialog Data
	//{{AFX_DATA(CHit6501TestDlg)
	enum { IDD = IDD_HIT6501TEST_DIALOG };
	CComboBox	m_MotorCombo;
	CListCtrl	m_MotorList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHit6501TestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHit6501TestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickListMotor(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelendokComboMotor();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIT6501TESTDLG_H__B42E2B9C_2D0A_4085_B2E0_03D4B0CA06AE__INCLUDED_)
