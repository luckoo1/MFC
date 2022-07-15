
// PracMFCDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "PracMFC.h"
#include "PracMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPracMFCDlg 대화 상자



CPracMFCDlg::CPracMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRACMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPracMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPracMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CPracMFCDlg 메시지 처리기

BOOL CPracMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPracMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPracMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//1.실제로는 MFC에서는 WindowProc안쓴다
#if 0 
LRESULT CPracMFCDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_LBUTTONDOWN)
	{
		CClientDC dc(this); //dc객체를 생성하면서 권한을 가져옴
							//this를 넘겨서 대화상자의 권한을 가져왔다고 생각하자.

		int x = LOWORD(lParam); //하위 16비트 값 분리
		int y = HIWORD(lParam); //상위 16비트 값 분리
#if 0
		//고정된 위치에 원이나 사각형 누르기0
		if (wParam & MK_CONTROL) //컨트롤이 눌려있으면(비트 if문 참조)
		{
			dc.Ellipse(10, 10, 100, 100);
		}
		else
		{
			dc.Rectangle(10, 10, 100, 100);
		}
#endif
		if (wParam & MK_CONTROL)
		{
			dc.Ellipse(x-30, y-30, x+30, y+30);
		}
		else
		{
			dc.Rectangle(x-30, y-30, x+30, y+30);
		}

	}

	return CDialogEx::WindowProc(message, wParam, lParam);
}
#endif

//2.MFC스타일로 쉽게 변했다.
void CPracMFCDlg::OnLButtonDown(UINT nFlags, CPoint point) // nFlags가 wParam,point 가 x,y좌표담고있는 class다.
{

	CClientDC dc(this);

	if (nFlags & MK_CONTROL)
	{
		dc.Ellipse(point.x - 30, point.y - 30, point.x + 30, point.y + 30);
	}
	else
	{
		dc.Rectangle(point.x - 30, point.y - 30, point.x + 30, point.y + 30);
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}
