//��  ��  ��: DirectPort.h
//��      ��: eBitWen
//e-Mail    : eBitWen@163.net
//�� ���� ��: 2003-5-20 
//��      ��: 1.0.0.0
//�ں�  �汾: 1.0.0.0
//˵      ��: ����һ���ṩ��nt/win2000/xp��ֱ�Ӷ�д�˿ڽӿڵĿ�
//			  �������һ��������,���κ�����,�������κγ���ʹ��,������֤���.
//            ����Bug��mail��eBitWen@163.net
#ifndef _DIRECTPORT_1856D21A_B15D_4a69_86A5_FE6CD4D69E30_INCLUDE
#define _DIRECTPORT_1856D21A_B15D_4a69_86A5_FE6CD4D69E30_INCLUDE

#ifdef  DIRECTPORTDLL_EXPORTS  
#define DIRECTPORTAPI  __declspec(dllexport) 
#else
#define DIRECTPORTAPI  __declspec(dllimport) 
#endif

#ifndef WINAPI
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

//����: 
//		�Ӷ˿ڶ���һ���ֽ�
//����:
//����:
//		lPort: �˿ں�
//����:
//      ��
DWORD  DIRECTPORTAPI DP_InpB(long lPort);

//����: 
//		�Ӷ˿ڶ���һ����
//����:
//����:
//		lPort: �˿ں�
//����:
//      ��
DWORD  DIRECTPORTAPI DP_InpW(long lPort);

//����: 
//		�Ӷ˿ڶ���һ��˫��
//����:
//����:
//		lPort: �˿ں�
//����:
//      ��
DWORD  DIRECTPORTAPI DP_InpD(long lPort);

//����: 
//		��˿����һ���ֽ�
//����:
//����:
//		lPort: �˿ں�
//		cData: Ҫ������ֽ�
//����:
//      ��
void   DIRECTPORTAPI DP_OutpB(long lPort,BYTE cData);

//����: 
//		��˿����һ����
//����:
//����:
//		lPort: �˿ں�
//		cData: Ҫ�������
//����:
//      ��
void DIRECTPORTAPI DP_OutpW(long lPort,WORD wData);

//����: 
//		��˿����һ��˫��
//����:
//����:
//		lPort: �˿ں�
//		cData: Ҫ�����˫��
//����:
//      ��
void DIRECTPORTAPI DP_OutpD(long lPort,DWORD dData);


//����: 
//		�� NT/Win2000/XP ���Ƿ�ʹ��ֱ�Ӷ˿�ģʽ
//����:
//		����ʹ���ں˶˿�ģʽʱ:
//		�����ڳ�����ֱ��ʹ��__inp,__inpw,__inpd,__outp,__outw,__outd�� c ���� ,
//		����һЩ��������ļ���ʹ��
//		��������������ֱ��ʹ�ö˿��������ָ��,����ͨ���ں˴����ת��,���Ч�ʸ���.
//		��ʹ���ں˶˿�ģʽʱ:
//		��������������Ҫͨ���ں˴����д�˿�
//����
//		bDirect: TRUE ��ʹ���ں˶˿�ģʽ
//				FALSE ʹ���ں˶˿�ģʽ
//����:
//     �ɹ����� TRUE
//     ʧ�ܷ��� FALSE     
BOOL DIRECTPORTAPI DP_UseDirectPortMode(BOOL bDirect);

//��������ϵͳ�Ƿ��� NT/Win2000/XP
//����
//    TRUE: os �� NT/Win2000/XP
//   FALSE: os �� 9x
BOOL DIRECTPORTAPI DP_IsNTOS();

//�汾��Ϣ
//���� 
//     �ɹ�: ��ǰϵͳ��װ��DirectPort �ں˰汾 eg 1.0.0.0
//     ʧ��: 0
//     �����ǰϵͳ����NT/win2000/xp,���Ƿ��� 0
DWORD DIRECTPORTAPI DP_GetKernelVer();


//�汾��Ϣ
//dwDllVer   : ��ǰϵͳ��װ��DirectPort  DLL�汾
//���� �汾 eg 1.0.0.0
DWORD DIRECTPORTAPI DP_GetVer();


#ifdef __cplusplus
}
#endif

#endif //_DIRECTPORT_1856D21A_B15D_4a69_86A5_FE6CD4D69E30_INCLUDE