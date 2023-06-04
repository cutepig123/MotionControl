/***************************************************************************/
/*  File: runtime.cpp - Dynamic link functions.                            */
/*                                                                         */
/***************************************************************************/

#include "StdAfx.h"
#include "windows.h"
#include "myRuntime.h"

//************************************************************************
// Function instants for runtime linking
//************************************************************************
void SetSim();

OPENPMACDEVICE                  OpenPmacDevice;
CLOSEPMACDEVICE                 ClosePmacDevice;
PMACDOWNLOADFILE                PmacDownloadFile;
PMACDOWNLOADA                   PmacDownload;
PMACSENDLINEA                   PmacSendLine;
PMACSENDCOMMANDA				PmacSendCommandA;
PMACGETLINEA                    PmacGetLine;
PMACSENDCHARA                   PmacSendChar;
PMACGETRESPONSEA                PmacGetResponse;
DOWNLOAD_SHOWPROGRESS           PmacDownloadProgress;
PMACSELECT                      PmacSelect;
DRVNUMBEROFDEVICES              DrvNumberOfDevices;
PMACGETPMACTYPE                 PmacGetPmacType;
GETROMDATEA                     PmacGetRomDate;
GETROMVERSIONA                  PmacGetRomVersion;
PMACGETCONTROLRESPONSEA         PmacGetControlResponse;
PMACGETVARIABLE                 PmacGetVariable;

// DPR Functions
PMACDPRSETMEM                   PmacDPRSetMem;
PMACDPRGETMEM                   PmacDPRGetMem;
PMACDPRAVAILABLE		            PmacDPRAvailable;
PMACDPRGETFLOAT			            PmacDPRGetFloat;
PMACDPRSETFLOAT			            PmacDPRSetFloat;
PMACDPRFLOAT			              PmacDPRFloat;
PMACDPRLFIXED			              PmacDPRLFixed;
PMACDPRGETGLOBALSTATUS	        PmacDPRGetGlobalStatus;
PMACDPRGETGLOBALSTATUSTURBO	    PmacDPRGetGlobalStatusTurbo;
PMACDPRREALTIMEEX               PmacDPRRealTimeEx;
PMACDPRBACKGROUNDEX             PmacDPRBackgroundEx;
PMACDPRPOSITION                 PmacDPRPosition;
// Interrupt Functions
PMACINTRTERMINAGE      PmacINTRTerminate;
PMACINTRFUNCINIT       PmacINTRFuncCallInit;


static HINSTANCE hLib;
HINSTANCE OpenRuntimeLink()
{
  int i;

  // Get handle to PComm32.DLL
  hLib = LoadLibrary("PComm32");
  if ( hLib != NULL ) 
  {
    for (i = 0 ; i < 1 ; i++)
    {
      OpenPmacDevice = (OPENPMACDEVICE)GetProcAddress(
                           hLib,"OpenPmacDevice");
      if (OpenPmacDevice == NULL) break;
      ClosePmacDevice = (CLOSEPMACDEVICE)GetProcAddress(
                           hLib,"ClosePmacDevice");
      if (ClosePmacDevice == NULL) break;
      PmacDownloadFile = (PMACDOWNLOADFILE)GetProcAddress(
                           hLib,"PmacDownloadFile");
      if (PmacDownloadFile == NULL) break;
      PmacDownload = (PMACDOWNLOADA)GetProcAddress(
                           hLib,"PmacDownloadA");
      if (PmacDownload == NULL) break;
      PmacSendLine = (PMACSENDLINEA)GetProcAddress(
                           hLib,"PmacSendLineA");
	  if (PmacDownload == NULL) break;
	  PmacSendCommandA = (PMACSENDCOMMANDA)GetProcAddress(
						   hLib,"PmacSendCommandA");
      if (PmacSendLine == NULL) break;
      PmacGetLine = (PMACGETLINEA)GetProcAddress(
                           hLib,"PmacGetLineA");
      if (PmacGetLine == NULL) break;
      PmacGetResponse = (PMACGETRESPONSEA)GetProcAddress(
                           hLib,"PmacGetResponseA");
      if (PmacGetResponse == NULL) break;
      PmacGetControlResponse = (PMACGETCONTROLRESPONSEA)GetProcAddress(hLib,"PmacGetControlResponseA");
    	if(PmacGetControlResponse == NULL) break;  
      PmacDownloadProgress = (DOWNLOAD_SHOWPROGRESS)GetProcAddress(
                           hLib,"PmacDownloadProgress");
      if (PmacDownloadProgress == NULL) break;
      PmacSelect = (PMACSELECT)GetProcAddress(hLib,"PmacSelect");
      if (PmacSelect == NULL) break;
      DrvNumberOfDevices = (DRVNUMBEROFDEVICES)GetProcAddress(
                           hLib,"DrvNumberOfDevices");
      if (DrvNumberOfDevices == NULL) break;
      PmacGetPmacType = (PMACGETPMACTYPE)GetProcAddress(
                           hLib,"PmacGetPmacType");
      if (PmacGetPmacType == NULL) break;
      PmacGetRomDate = (GETROMDATEA)GetProcAddress(
                           hLib,"PmacGetRomDateA");
      if (PmacGetRomDate == NULL) break;
      PmacGetRomVersion = (GETROMVERSIONA)GetProcAddress(
                           hLib,"PmacGetRomVersionA");
      if (PmacGetRomVersion == NULL) break;

      //DPR Stuff
      PmacDPRSetMem = (PMACDPRSETMEM)GetProcAddress(
                           hLib,"PmacDPRSetMem");
      if (PmacDPRSetMem == NULL) break;
      PmacDPRGetMem = (PMACDPRGETMEM)GetProcAddress(
                           hLib,"PmacDPRGetMem");
      if (PmacDPRGetMem == NULL) break;
	    PmacDPRAvailable = (PMACDPRAVAILABLE)GetProcAddress(
						   hLib, "PmacDPRAvailable");
	    if (PmacDPRAvailable == NULL) break;
	    PmacDPRGetFloat = (PMACDPRGETFLOAT)GetProcAddress(
						   hLib,"PmacDPRGetFloat");
	    if (PmacDPRGetFloat == NULL) break;
	    PmacDPRSetFloat = (PMACDPRSETFLOAT)GetProcAddress(
						   hLib,"PmacDPRSetFloat");
	    if (PmacDPRSetFloat == NULL) break;
      PmacDPRFloat = (PMACDPRFLOAT)GetProcAddress(
						   hLib,"PmacDPRFloat");
	    if (PmacDPRFloat == NULL) break;
	    PmacDPRLFixed = (PMACDPRLFIXED)GetProcAddress(
						   hLib,"PmacDPRLFixed");
	    if (PmacDPRLFixed == NULL) break;
	    PmacDPRGetGlobalStatus = (PMACDPRGETGLOBALSTATUS)GetProcAddress(
						   hLib,"PmacDPRGetGlobalStatus");
	    if (PmacDPRGetGlobalStatus == NULL) break;
	    PmacDPRGetGlobalStatusTurbo = (PMACDPRGETGLOBALSTATUSTURBO)GetProcAddress(
						   hLib,"PmacDPRGetGlobalStatusTurbo");
	    if (PmacDPRGetGlobalStatusTurbo == NULL) break;
      PmacDPRRealTimeEx = (PMACDPRREALTIMEEX)GetProcAddress(
						   hLib,"PmacDPRRealTimeEx");
	    if (PmacDPRRealTimeEx == NULL) break;
      PmacDPRBackgroundEx = (PMACDPRBACKGROUNDEX)GetProcAddress(
						   hLib,"PmacDPRBackgroundEx");
	    if (PmacDPRBackgroundEx == NULL) break;
      PmacDPRPosition = (PMACDPRPOSITION)GetProcAddress(
               hLib,"PmacDPRPosition");
      if (PmacDPRPosition == NULL) break;


	  }
    if(i==0)                         // Check validity of procedure addresses
    {
      FreeLibrary(hLib);
      hLib = NULL;
    }
  }

#ifdef _SIMULATE_
  SetSim();
#endif
  return hLib;
}
//---------------------------------------------------------------------------

void CloseRuntimeLink()
{
  if(hLib)
    FreeLibrary(hLib);
}

void SetText(HWND hWnd,int IDOfText,char *szFormat,...)
{
	char s[2000];
	va_list l;
	va_start(l,szFormat);
	vsprintf(s,szFormat,l);

	SetDlgItemText(hWnd,IDOfText,s);
}

void AddText(HWND hWnd,int IDOfText,char *szFormat,...)
{
	char s[3000],ss[1000];
	va_list l;
	va_start(l,szFormat);
	vsprintf(ss,szFormat,l);
	
	GetDlgItemText(hWnd,IDOfText,s,2500);
	strcat(s,ss);
	SetDlgItemText(hWnd,IDOfText,s);
}

void Select()
{
#ifndef _SIMULATE

	int m_nDevName = PmacSelect(NULL);
	
	if (m_nDevName < 0 || m_nDevName > 7 || !OpenPmacDevice(m_nDevName))
	{
		AfxMessageBox("Connected Pmac Failed...\n");
	}
	else
		AfxMessageBox("Connected Pmac OK!\n");
	#endif
}

void PMACSendCmd(char *buf,char *szFormat,...)
{
#ifndef _SIMULATE

	va_list l;
	char cmd[1000];
	va_start(l,szFormat);
	vsprintf(cmd,szFormat,l);
	printf("命令 %s :",cmd);
	
	PmacGetResponse(0,buf,255,cmd);
	printf("%s\n",buf);
#else
	strcpy(buf,"OK");
	#endif
}

//把指定的悬臂axis移动某一角度delta_angle
void MoveAt(int num,double d_angle)
{
	char buf[256];
	//初始化运动模式
	PMACSendCmd(buf,"i%d00=1",num);
	PMACSendCmd(buf,"i%d24=$20000",num);
	//得到当前位置,计算目标位置
	PMACSendCmd(buf,"#%dp",num);
	
	long pos1=atof(buf),
		pos2=pos1+d_angle* CTS_PER_ANGLE,
		pos=pos1;
	printf("Pos:%s(%d) --> %d\n",buf,pos1,pos2);
	//让电机运动，并循环判断位置
	PMACSendCmd(buf,"#%dJ%c",num,d_angle >0?'+':'-');
	while (d_angle*(pos2-pos)>0) {
		PMACSendCmd(buf,"#%dp",num);	//CurrPos
		pos=atof(buf),
		printf("-currpos %d,",pos);
		if(abs(pos)>450)
		{
			printf("超限，退出\n");
			PMACSendCmd(buf,"#%dK",num);	
		}
		Sleep(100);
	}
	printf("到达指定位置\n");
	//停止
	PMACSendCmd(buf,"#%dK",num);
	PMACSendCmd(buf,"i%d00=0",num);
}

void LoadInfo(char *szViewName,CWnd *pFrame)
{
	RECT rect;
	char path[1000];
	GetModuleFileName(0,path,1000);
	strcat(path,".ini");
	TRACE("GetFile:%s",path);
	//GetPrivateProfileInt(szViewName,"RECT",&rect,sizeof(RECT),path);
	UINT x1= GetPrivateProfileInt(szViewName,"x1",0,path);
	UINT y1= GetPrivateProfileInt(szViewName,"y1",0,path);
	UINT x2= GetPrivateProfileInt(szViewName,"x2",600,path);
	UINT y2= GetPrivateProfileInt(szViewName,"y2",600,path);
	
	rect.left=x1;
	rect.top=y1-25;
	rect.right=x2;
	rect.bottom=y2-25;

	pFrame->MoveWindow(&rect);
}

void SaveInfo(char *szViewName,CWnd *pFrame)
{
	RECT rect;
	pFrame->GetWindowRect(&rect);
	
	AfxGetMainWnd()->ScreenToClient(&rect);
	char path[1000];
	GetModuleFileName(0,path,1000);
	strcat(path,".ini");
	TRACE("WriteFile:%s",path);
	char s[100];
	sprintf(s,"%d",rect.left);
	WritePrivateProfileStringA(szViewName,"x1",s,path);
	
	sprintf(s,"%d",rect.top);
	WritePrivateProfileStringA(szViewName,"y1",s,path);
	
	sprintf(s,"%d",rect.right);
	WritePrivateProfileStringA(szViewName,"x2",s,path);
	
	sprintf(s,"%d",rect.bottom);
	WritePrivateProfileStringA(szViewName,"y2",s,path);
}

int     (CALLBACK GetResp)(DWORD dwDevice, LPTSTR s,
                                UINT maxchar, LPCTSTR outstr )
{
	strcpy(s,"OK");
	return 0;
}

void SetSim()
{
	PmacGetResponse=GetResp;
}