
// PracMFC.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "PracMFC.h"
#include "PracMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPracMFCApp

BEGIN_MESSAGE_MAP(CPracMFCApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CPracMFCApp 생성

CPracMFCApp::CPracMFCApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CPracMFCApp 개체입니다.

CPracMFCApp theApp;


// CPracMFCApp 초기화

BOOL CPracMFCApp::InitInstance()
{
	CWinApp::InitInstance();

	CPracMFCDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}
