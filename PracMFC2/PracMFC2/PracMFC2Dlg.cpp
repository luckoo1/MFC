
// PracMFC2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "PracMFC2.h"
#include "PracMFC2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPracMFC2Dlg 대화 상자



CPracMFC2Dlg::CPracMFC2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRACMFC2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPracMFC2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPracMFC2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW_BTN, &CPracMFC2Dlg::OnBnClickedShowBtn)
	ON_LBN_SELCHANGE(IDC_ITEM_LIST, &CPracMFC2Dlg::OnLbnSelchangeItemList)
END_MESSAGE_MAP()


// CPracMFC2Dlg 메시지 처리기

BOOL CPracMFC2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*■*/
	wchar_t *p_item_name[MAX_ITEM_COUNT] ={
		L"아메리카노  1900원", L"카페라떼         2500원",
		L"카페모카    2800원", L"카라멜마끼아또   3200원",
		L"에스프레소  1800원", L"바닐라라떼       3500원",
		L"카푸치노    3300원", L"비엔나           3500원"
	};

	int price[8] = { 1900,2500,2800,3200,1800,3500,3300,3500 };

	m_item_list.SubclassDlgItem(IDC_ITEM_LIST, this);  /*■IDC_ITEM_LIST와 m_item_list객체를 연결*/
	m_item_list.SetItemHeight(0, 24); /*■체크박스끼리 거리 조절*/
	for (int i = 0; i < MAX_ITEM_COUNT; i++)
	{
		m_item_list.InsertString(i, p_item_name[i]);/*■리스트박스에 추가*/
		m_item_list.SetItemData(i, price[i]);/*■4바이트 확장공간에 값을 쓴다. GetItemData(i)로 바로 값 얻을 수 있다.*/

	}

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPracMFC2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPracMFC2Dlg::OnPaint()
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
HCURSOR CPracMFC2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPracMFC2Dlg::OnBnClickedShowBtn()
{
	int num[11];
#if 0
	num[0] = GetDlgItemInt(IDC_EDIT1);
	num[1] = GetDlgItemInt(IDC_EDIT2);
	num[2] = GetDlgItemInt(IDC_EDIT3);
	num[3] = GetDlgItemInt(IDC_EDIT4);
	num[4] = GetDlgItemInt(IDC_EDIT5);
#endif

#if 0
	for (int i = 0; i < 5; i++)
	{
		num[i]= GetDlgItemInt(IDC_EDIT1+i);
	}

	CComboBox* p_combo;
	CString str,total_str;
	int index;

	for (int i = 0; i < 5; i++)
	{
		p_combo = (CComboBox*)GetDlgItem(IDC_COMBO1+i);
		index = p_combo->GetCurSel();
		if (index != CB_ERR)
		{
			p_combo->GetLBText(index,str); //콤보박스 index의 문자열을 str로 가져옴
			num[5 + i] = _wtoi(str); //문자열을 정수로 변환해서 넣는다.
		}
		else
		{
			num[5 + i] = 0; //사용자가 선택안했으면 0넣기
		}
	}
#endif
	for (int i = 0; i < 10; i++)
	{
		num[i] = GetDlgItemInt(IDC_EDIT1 + i);
	}

	CString str, total_str;
	for (int i = 0; i < 10; i++)
	{
		str.Format(L"%d ", num[i]);
		total_str = total_str + str;
	}

	SetDlgItemText(IDC_NUM_LIST_EDIT, total_str);
}

/*■리스트박스 오른쪽클릭해서 이벤트 처리기 추가로 만들었다.
이 항목을 선택할때마다 메세지 발생한다*/
void CPracMFC2Dlg::OnLbnSelchangeItemList()
{
	int count = m_item_list.GetCount();
	int total_price = 0;
	for (int i = 0; i < count; i++)
	{
		if (m_item_list.GetCheck(i))
		{
			total_price += total_price+= m_item_list.GetItemData(i);
		}
	}
	SetDlgItemInt(IDC_TOTAL_PRICE_EDIT, total_price);
}
