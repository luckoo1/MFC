
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_my_string(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_my_string);
	DDX_Control(pDX, IDC_CHAT_LIST, m_chat_list);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW_MSG_BTN, &CMFCApplication1Dlg::OnBnClickedShowMsgBtn)
	ON_BN_CLICKED(IDC_READ_BTN, &CMFCApplication1Dlg::OnBnClickedReadBtn)
	ON_BN_CLICKED(IDC_WRITE_BTN, &CMFCApplication1Dlg::OnBnClickedWriteBtn)
	ON_BN_CLICKED(IDC_ADD_BTN, &CMFCApplication1Dlg::OnBnClickedAddBtn)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*★EDIT에 적힌 값을 팝업창에 띄우는 방법*/
void CMFCApplication1Dlg::OnBnClickedShowMsgBtn()
{
#if 0
	/*
	★1
	IDC_INPUT_MSG_EDIT 컨트롤에서 문자열을 읽어와서
	str에 저장
	*/
	wchar_t str[64];
	GetDlgItemText(IDC_INPUT_MSG_EDIT, str, 64);
	AfxMessageBox(str);//★2 이 문자열을 화면에 출력
#endif
#if 0
	//★3 CString 클래스 사용해서 문자열길이 안적어도 되게 만들었다.
	CString str;
	GetDlgItemText(IDC_INPUT_MSG_EDIT, str);
	AfxMessageBox(str);
#endif
#if 0
	//★4 "사용자가 입력한 문자열 : + 글자"이런형식으로 출력되게 만들었다.
	CString  str, show_str;
	GetDlgItemText(IDC_INPUT_MSG_EDIT, str);
	show_str.Format(L"사용자가 입력한 문자열 : %s", str);
	AfxMessageBox(show_str);
#endif
	//★5 "사용자가 입력한 문자열 : + 글자"이런형식으로 출력되게 만들었다.
	CString  str, show_str;
	GetDlgItemText(IDC_INPUT_MSG_EDIT, str);
	show_str = L"사용자가 입력한 문자열 : " + str;
	AfxMessageBox(show_str);
}
/*
읽기 버튼과 쓰기버튼 추가
★6블로그 edit에 값으로 연결하기 확인해보기
*/
void CMFCApplication1Dlg::OnBnClickedReadBtn()
{
#if 0	//★9 방법1
	UpdateData(TRUE); //★7컨트롤->변수로 옮겨간다.
	/*★8위의 코드가 실행되면 "DDX_Text(pDX, IDC_EDIT1, m_my_string);"가 실행됨*/
	AfxMessageBox(m_my_string);
	int value = _wtoi(m_my_string);//정수값 바꾸는법
#endif
#if 0//★12 방법2
	//★10 클래스 위저드 없이 사용하는법
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	AfxMessageBox(str);
	/*★11 
	IDC_EDIT1에 있는 값을 읽어서 str에 저장
	반환값은 str의 길이라서
	int len = GetDlgItemText(IDC_EDIT1, str); 써도됨

	GetDlgItemInt쓰면 정수값 쓴다.

	GetDlgItemInt(IDC_EDIT1);
	str.Format*(L"%d", value);
	AfxMessageBox(str);
	이렇게하면 잘 읽어온다.
	*/
#endif
	//★13 기존에는 그냥 가져왔다면 이번에는 길이를 보고 판단해보자.
	
	CWnd * p = GetDlgItem(IDC_EDIT1); //★14 GetDlgItem()은 IDC_EDIT1의 컨트롤의 포인터 반환
	int len = p->SendMessage(WM_GETTEXTLENGTH);
	//int len = p->GetWindowTextLenth(); 이거 써도 된다.
	if (len > 3)
	{
		AfxMessageBox(L"너무 길게 입력했습니다.");
	}
	else
	{
		wchar_t str[4];
		GetDlgItemText(IDC_EDIT1, str, 4);
		AfxMessageBox(str);
	}
	/*
	CWnd * p = GetDlgItem(IDC_EDIT1); //★13 GetDlgItem()은 IDC_EDIT1의 컨트롤의 포인터 반환
	CEdit* p_edit = (CEdit*)p;

	CEdit* p_edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	위 두줄과 같은표현
	*/

}

void CMFCApplication1Dlg::OnBnClickedWriteBtn()
{
#if 0
	//★9 방법1
	m_my_string = L"tipsware";
	UpdateData(FALSE); //변수 -> 컨트롤에 쓰여짐
#endif
#if 0
	// ★12 방법2
	SetDlgItemText(IDC_EDIT1, L"tipsware");
	//SetDlgItemInt(IDC_EDIT1,5);
#endif

}

/*★15 리스트박스 추가*/
void CMFCApplication1Dlg::OnBnClickedAddBtn()
{
	CString str1;
	GetDlgItemText(IDC_CHAT_EDIT,str1);
	//m_chat_list.AddString(str1);//str1을 list box에 추가
	//m_chat_list.InsertString(0,str1);//str1을 list box 0번째에 추가

	SetDlgItemText(IDC_CHAT_EDIT, L"");//글자추가하고 내용지우기

	int index = m_chat_list.InsertString(-1,str1);//str1을 list box 마지막에 추가
	//AddString과 InsertString은 추가된 위치가 반환값임

	m_chat_list.SetCurSel(index); //추가된 위치가 자동으로 설정되어 커서를 내릴필요가 없다.



}
