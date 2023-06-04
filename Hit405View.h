#if !defined(AFX_HIT405VIEW_H__EFDA397F_2BCB_46C4_B0E6_7E669FE3BFB9__INCLUDED_)
#define AFX_HIT405VIEW_H__EFDA397F_2BCB_46C4_B0E6_7E669FE3BFB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Hit405View.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHit405View form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CHit405View : public CFormView
{
protected:
	CHit405View();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CHit405View)
	DWORD WINAPI CheckVelProc();	//检查堵转情况
	void StartProc()	;
	HANDLE m_hThread;
// Form Data
public:


	//{{AFX_DATA(CHit405View)
	enum { IDD = IDD_HIT405VIEW_FORM };
	
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

// Attributes
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
// Operations
public:
	//bool m_bMoving;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHit405View)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CHit405View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CHit405View)
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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnButtonDir();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIT405VIEW_H__EFDA397F_2BCB_46C4_B0E6_7E669FE3BFB9__INCLUDED_)
