// hit405Dlg.h : header file
//

#if !defined(AFX_HIT405DLG_H__A9CB4D65_ED9E_468C_8228_DCFF7B549DD5__INCLUDED_)
#define AFX_HIT405DLG_H__A9CB4D65_ED9E_468C_8228_DCFF7B549DD5__INCLUDED_
#include "Resource.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHit405Dlg dialog

class CHit405Dlg : public CDialog
{
// Construction
public:
	double W_Velocity[6];
	void SetWheelVelocity();
	int motorv[6];
	int motor1;
	int motor2;
	int motor3;
	int direction1;
	int direction2;
	int direction3;
	int motor4,motor5,motor6;
	int direction4,direction5,direction6;

	//Pmac
	double originone,overone,origintwo,overtwo,originthree,overthree,originfour,overfour,originfive,overfive,originsix,oversix;
	unsigned int FlagOne,FlagTwo,FlagThree,FlagFour,FlagFive,FlagSix;
	BOOL m_bDriverOpen;
	int m_nDevName;
	CString m_strDev;
	void close();

	CHit405Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHit405Dlg)
	enum { IDD = IDD_HIT405_DIALOG };
	CButton	m_motorsix_right;
	CButton	m_motorfour_right;
	CButton	m_motorfive_right;
	CButton	m_MOTORSIX;
	CButton	m_MOTORFIVE;
	CButton	m_MOTORFOUR;
	CButton	m_motortwo_right;
	CButton	m_motorthree_right;
	CButton	m_motorone_right;
	CButton	m_motortwo;
	CButton	m_motorthree;
	CButton	m_motorone;
	int		m_motor_v;
	double	m_radius;
	UINT	m_io;
	int		m_nbase;
	CString	m_strYBPosFive;
	CString	m_strYBPosFour;
	CString	m_strYBPosOne;
	CString	m_strYBPosSix;
	CString	m_strYBPosThree;
	CString	m_strYBPosTwo;
	double	m_dDegOne;
	double	m_dDegFive;
	double	m_dDegFour;
	double	m_dDegTwo;
	double	m_dDegSix;
	double	m_dDegThree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHit405Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHit405Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMotoroneChoose();
	afx_msg void OnMotoroneRight();
	afx_msg void OnMotoroneLeft();
	afx_msg void OnMotortwoChoose();
	afx_msg void OnMotortwoRight();
	afx_msg void OnMotortwoLeft();
	afx_msg void OnMotorthreeChoose();
	afx_msg void OnMotorthreeRight();
	afx_msg void OnMotorthreeLeft();
	afx_msg void OnMotorStart();
	afx_msg void OnMotorStop();
	afx_msg void OnMotorfourChoose();
	afx_msg void OnMotorfiveChoose();
	afx_msg void OnMotorsixChoose();
	afx_msg void OnMotorfourRight();
	afx_msg void OnMotorfourLeft();
	afx_msg void OnMotorfiveRight();
	afx_msg void OnMotorfiveLeft();
	afx_msg void OnMotorsixRight();
	afx_msg void OnMotorsixLeft();
	afx_msg void OnEnable();
	afx_msg void OnTest();
	afx_msg BOOL OnSelectpmac();
	afx_msg BOOL OnPmacTest();
	afx_msg void OnYaobiOneU();
	afx_msg void OnYaobiOneD();
	afx_msg void OnYaobiOneS();
	afx_msg void OnYaobiTwoU();
	afx_msg void OnYaobiTwoD();
	afx_msg void OnYaobiTwoS();
	afx_msg void OnYaobiThreeU();
	afx_msg void OnYaobiThreeD();
	afx_msg void OnYaobiThreeS();
	afx_msg void OnYaobiFourU();
	afx_msg void OnYaobiFourD();
	afx_msg void OnYaobiFourS();
	afx_msg void OnYaobiFiveU();
	afx_msg void OnYaobiFiveD();
	afx_msg void OnYaobiFiveS();
	afx_msg void OnYaobiSixU();
	afx_msg void OnYaobiSixD();
	afx_msg void OnYaobiSixS();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIT405DLG_H__A9CB4D65_ED9E_468C_8228_DCFF7B549DD5__INCLUDED_)
