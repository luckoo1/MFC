
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
#if 0
	//1.
	, m_my_string(_T("")) /*m_my_string 초기화 코드*/
#endif
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPracMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
#if 0
	//1.
	DDX_Text(pDX, IDC_EDIT1, m_my_string);  /*IDC_EDIT1와 m_my_string을 연결*/
#endif
	DDX_Control(pDX, IDC_CHAT_LIST, m_chat_list);
}

BEGIN_MESSAGE_MAP(CPracMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_SHOW_MSG_BTN, &CPracMFCDlg::OnBnClickedShowMsgBtn)
	ON_EN_CHANGE(IDC_INPUT_MSG_EDIT, &CPracMFCDlg::OnEnChangeInputMsgEdit)
	ON_BN_CLICKED(IDC_READ_BTN, &CPracMFCDlg::OnBnClickedReadBtn)
	ON_BN_CLICKED(IDC_WRITE_BTN, &CPracMFCDlg::OnBnClickedWriteBtn)
	ON_EN_CHANGE(IDC_EDIT1, &CPracMFCDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_ADD_BTN, &CPracMFCDlg::OnBnClickedAddBtn)
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



void CPracMFCDlg::OnBnClickedShowMsgBtn()
{
#if 0
	wchar_t str[64];/*128Byte*/

	GetDlgItemText(IDC_INPUT_MSG_EDIT,str,64);
	/*
	"대화상자(dlg)의 item(도구)의 text를 얻겠다"라는 함수
	IDC_INPUT_MSG_EDIT의 값을 str로 복사하겠다.
	(주소,주소,크기)순으로 적었다.
	"IDC_INPUT_MSG_EDIT"대신 1000적어도 된다.
	*/
	AfxMessageBox(str);
	/*
	str이 메세지 박스로 출력됨
	*/
#endif
	/*CString써서 길이제한 없애자*/
	CString str,show_str;
	GetDlgItemText(IDC_INPUT_MSG_EDIT, str);
	/*GetDlgItemText가 호출되는데 오버라이딩으로 길이를 안받는 함수가 호출된다.*/

	show_str= L"사용자가 입력한 문자열 : %s" + str;
	/*
	show_str.Format(L"사용자가 입력한 문자열 : %s", str);
	Format써서 printf처럼 받음,L쓴건 유니코드를 위해서 사용
	*/
	AfxMessageBox(show_str);

}


void CPracMFCDlg::OnEnChangeInputMsgEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void CPracMFCDlg::OnBnClickedReadBtn()
{
#if 0
	//1.
	UpdateData(TRUE); //컨트롤 -> 변수
	/*컨트롤에 있는값을 m_my_string에 내려오겠다는 명령 */
	AfxMessageBox(m_my_string);//m_my_string값 출력해보겠다.
	/*
	DDX_Text(pDX, IDC_EDIT1, m_my_string);이 코드에서
	IDC_EDIT1와 m_my_string을 연결

	UpdateData(TRUE);쓰면
	IDC_EDIT1값이 m_my_string로 복사됨
	*/
#endif
/*이전에 if0 endif처리했던 방법보다 아래의 방법이 좋다.*/
	CString str;
	GetDlgItemText(IDC_EDIT1,str); 
	/*
	IDC_EDIT1에 있는 문자열을 읽어서 str에 저장
	반환값은 크기다.
	int len = GetDlgItemText(IDC_EDIT1,str);써도됨

	int형 쓰고싶으면 
	GetDlgItemInt(IDC_EDIT1);
	*/
	AfxMessageBox(str);
#if 0
	//2.
	//wchar기반의 배열로 받으려면 아래처럼 쓰면된다.
	//단 배열로 쓸려면 크기가 중요하겠지!
	wchar_t str[24];
	GetDlgItemText(IDC_EDIT1, str, 24);
#endif
#if 0
	//3.
	CWnd* p = GetDlgItem(IDC_EDIT1);
	/*
	GetDlgItem의 반환값은 CWnd포인터
	IDC_EDIT1클래스가 다형성에 의해서 부모클래스인 CWnd포인터를 반환하는 것
	사실은 CWnd지만 내부적으로 보면 Edit_control
	*/
	CEdit* p_edit = (CEdit*)p;
#endif

#if 0
	//4.
	/*
	이렇게 바로 쓸수도 있다.
	CEdit클래스 고유 성격을 유지(CEdit클래스가 제공하는 함수 사용가능)
	*/
	CEdit* p_edit= (CEdit*)GetDlgItem(IDC_EDIT1);
#endif
#if 0
	//5.
	/*
	이렇게 크기를 설정할수 있다.
	*/
	CWnd* p = GetDlgItem(IDC_EDIT1);
	int len = p->SendMessage(WM_GETTEXTLENGTH);
	if (len > 3)
	{
		AfxMessageBox(L"너무 길게 입력했습니다.");
	}
	else
	{
		GetDlgItemText(IDC_EDIT1, str, 24);
		AfxMessageBox(str);
	}
#endif
#if 0
	//6.
	/*
	이렇게도 가능하다.
	*/
	CWnd* p = GetDlgItem(IDC_EDIT1);
	int len = p->GetWindowTextLength();
	if (len > 3)
	{
		AfxMessageBox(L"너무 길게 입력했습니다.");
	}
	else
	{
		GetDlgItemText(IDC_EDIT1, str, 24);
		AfxMessageBox(str);
	}
#endif
#if 0
	//7.
	/*
	이렇게도 가능하다.
	*/
	int len = GetDlgItem(IDC_EDIT1)->GetWindowTextLength();
	if (len > 3)
	{
		AfxMessageBox(L"너무 길게 입력했습니다.");
	}
	else
	{
		GetDlgItemText(IDC_EDIT1, str, 24);
		AfxMessageBox(str);
	}
#endif
}


void CPracMFCDlg::OnBnClickedWriteBtn()
{
#if 0
	//1.
	m_my_string = L"tipsware";
	UpdateData(false);
	/*
	UpdateData(FALSE);쓰면
	m_my_string값이 IDC_EDIT1로 복사됨
	*/
#endif
	SetDlgItemText(IDC_EDIT1, L"tipsware");
}


void CPracMFCDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPracMFCDlg::OnBnClickedAddBtn()
{
#if 0
	CString str;
	GetDlgItemText(IDC_CHAT_EDIT, str);
	m_chat_list.AddString(str);//listbox에 추가한다.
#endif
#if 0
	CString str;
	GetDlgItemText(IDC_CHAT_EDIT, str);
	m_chat_list.InsertString(0, str);
	/*
	0번(위쪽)에 추가
	m_chat_list.InsertString(-1, str);
	-1번은 마지막에 추가
	int index = m_chat_list.InsertString(-1, str);
	반환값은 index
	*/
#endif
	CString str;
	GetDlgItemText(IDC_CHAT_EDIT, str);
	SetDlgItemText(IDC_CHAT_EDIT, L"");//추가하면 Edit내용 사라짐
	int index = m_chat_list.InsertString(-1, str);
	m_chat_list.SetCurSel(index); //추가될때 파란블럭(커서)가 index위치로 감
}
