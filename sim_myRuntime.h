//#include <windows.h>

#ifndef SIM_MYRUNTIME_H
#define SIM_MYRUNTIME_H
#define CTS_PER_ANGLE (4800/360)
// Communication return codes that appear in COMM_BUFFER status
#define COMM_EOT               0x80000000
#define COMM_TIMEOUT           0xC0000000
#define COMM_ERROR             0xE0000000
#define COMM_FAIL              0xF0000000
#define COMM_ANYERR            0x70000000

// Masks for determining what return codes are in COMM_BUFFER status
#define COMM_CHARS(c)          (c & 0x0FFFFFFF)
#define COMM_STATUS(c)         (c & 0xF0000000)
#define COMM_OK                1
#define COMM_UNSOLICITED       0x10000000
#define IS_COMM_MORE(c)        ((c & 0xF0000000) == 0)
#define IS_COMM_EOT(c)         ((c & 0xF0000000) == COMM_EOT)
#define IS_COMM_TIMEOUT(c)     ((c & 0xF0000000) == COMM_TIMEOUT)
#define IS_COMM_ERROR(c)       ((c & 0xF0000000) == COMM_ERROR)
#define IS_COMM_FAIL(c)        ((c & 0xF0000000) == COMM_FAIL)
#define IS_COMM_ANYERROR(c)    ((c & 0x70000000) == COMM_ANYERR)
#define IS_COMM_UNSOLICITED(c) ((c & 0xF0000000) == COMM_UNSOLICITED)
// Maximum length of a response
#define MAX_COMM_BUFFER        256
#define MAX_DPRBUFFER          160
#define MAX_DPRREADBUFFER      256

// **************************************************************************
// COMM Type Defines
// **************************************************************************
 BOOL    (CALLBACK OpenPmacDevice)(DWORD dwDevice);
 BOOL    (CALLBACK ClosePmacDevice)(DWORD dwDevice);
 long    (CALLBACK PmacSelect)( HWND hwnd );

PCHAR   (CALLBACK PmacGetRomVersion) ( DWORD dwDevice, LPSTR s, int maxchar ){return 0;}
PCHAR CALLBACK PmacGetRomDate ( DWORD dwDevice, LPSTR s, int maxchar ){return 0;}

 BOOL    (CALLBACK PmacReadReady)(DWORD dwDevice);
 int     (CALLBACK PmacSendLine)(DWORD dwDevice, LPCTSTR outstr);
 int		(CALLBACK PmacSendCommandA)(DWORD dwDevice, PCHAR command);
 int     (CALLBACK PmacSendChar)(DWORD dwDevice, CHAR outch);
 int     (CALLBACK PmacGetLine)(DWORD dwDevice, LPTSTR s,
                                UINT maxchar);
 int     (CALLBACK PmacGetResponse)(DWORD dwDevice, LPTSTR s,
                                UINT maxchar, LPCTSTR outstr );
 int     (CALLBACK PmacGetControlResponse)(DWORD dwDevice,LPTSTR s,UINT maxchar,CHAR outchar);

 void    (CALLBACK PmacDownloadFile)(DWORD dwDevice, char *fname);

typedef int     (FAR WINAPI *DOWNLOADMSGPROC)(LPSTR str, BOOL newline);
typedef int     (FAR WINAPI *DOWNLOADGETPROC)(int nIndex, LPSTR lpszBuffer,
                                int nMaxLength);
typedef void    (FAR WINAPI *DOWNLOADPROGRESS)(int nPercent);
typedef int     (CALLBACK *PMACDOWNLOADA)(DWORD dwDevice, DOWNLOADMSGPROC msgp,
                                DOWNLOADGETPROC getp, DOWNLOADPROGRESS ppgr,
                                PCHAR filename, BOOL macro, BOOL map, BOOL log,
                                BOOL dnld );
typedef int     (CALLBACK *DOWNLOAD_SHOWPROGRESS)(BOOL bDoChecksums,
                                BOOL bAlwaysShow, HWND hWnd, DWORD dwDevice,
                                PCHAR filename, BOOL macro, BOOL map, BOOL log,
                                BOOL dnld );
typedef void    (CALLBACK *PMACDOWNLOAD)(DWORD dwDevice,DWORD/*DOWNLOADMSGPROC*/ msgp,/*DOWNLOADGETPROC*/DWORD getp,
                                DWORD/*DOWNLOADPROGRESS*/ ppgr,PCHAR filename,BOOL macro,BOOL map,BOOL log,BOOL dnld);
typedef void    (CALLBACK *PMACDPRGETGLOBALSTATUS)(DWORD dwDevice,DWORD gsPmac[2]);
typedef long    (CALLBACK *DRVNUMBEROFDEVICES)();
typedef int     (CALLBACK *PMACGETPMACTYPE)(DWORD dwDevice);
typedef int     (CALLBACK *PMACGETVARIABLE)(DWORD dwDevice,char ch,UINT num,short int def);


// DPR Calls
typedef PVOID   (CALLBACK *PMACDPRSETMEM)(DWORD dwDevice, DWORD offset,
                                size_t count, PVOID val);
typedef PVOID   (CALLBACK *PMACDPRGETMEM)(DWORD dwDevice, DWORD offset,
                                size_t count, PVOID val);
typedef BOOL    (CALLBACK *PMACDPRAVAILABLE)( DWORD dwDevice );
typedef float   (CALLBACK *PMACDPRGETFLOAT)( DWORD dwDevice, UINT offset );
typedef void    (CALLBACK *PMACDPRSETFLOAT)( DWORD dwDevice, UINT offset, double val );
typedef double  (CALLBACK *PMACDPRFLOAT)( long d[], double scale );
typedef double  (CALLBACK *PMACDPRLFIXED)( long d[], double scale );
//typedef void	  (CALLBACK *PMACDPRGETGLOBALSTATUS)(DWORD dwDevice,VOID *gstatus);
typedef void	  (CALLBACK *PMACDPRGETGLOBALSTATUSTURBO)(DWORD dwDevice,struct gsTURBO *turbogstatus);
typedef PCHAR   (CALLBACK *GETROMDATEA) ( DWORD dwDevice, LPSTR s, int maxchar );
typedef PCHAR   (CALLBACK *GETROMVERSIONA) ( DWORD dwDevice, LPSTR s, int maxchar );
typedef BOOL    (CALLBACK *PMACDPRREALTIMEEX) ( DWORD dwDevice, long mask_range, UINT period, int on );
typedef BOOL    (CALLBACK *PMACDPRBACKGROUNDEX) ( DWORD dwDevice, int on, UINT period, UINT crd );
typedef double  (CALLBACK *PMACDPRPOSITION)( DWORD dwDevice, int mtr, double units );

typedef struct _INTRBUFFER { // pointer to reserved buffer data area
  PCH     lpData;            // pointer to reserved length of buffer
  ULONG   dwBufferLength;  
  DWORD   dwInterruptType; // Identifies PMAC Interrupt number that       
                                           // triggered callback function.
} INTRBUFFER, * PINTRBUFFER;

typedef void    (CALLBACK * PMACINTRPROC) ( DWORD msg, PINTRBUFFER pBuffer );
typedef BOOL    (CALLBACK * PMACINTRFUNCINIT)(DWORD dwDevice,PMACINTRPROC pFunc,DWORD msg,ULONG ulMask);
typedef BOOL    (CALLBACK * PMACINTRTERMINAGE)( DWORD dwDevice );


//------- Functions ---------------------------------------------------------

HINSTANCE OpenRuntimeLink();
void      CloseRuntimeLink();

void SetText(HWND hWnd,int IDOfText,char *szFormat,...);
void AddText(HWND hWnd,int IDOfText,char *szFormat,...);
void LoadInfo(char *szViewName,CWnd *pFrame);
void SaveInfo(char *szViewName,CWnd *pFrame);

void Select();
void PMACSendCmd(char *buf,char *szFormat,...);
void MoveAt(int num,double d_angle);
#endif

