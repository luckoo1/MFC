#define MAX_ITEM_COUNT    8
// PracMFC2Dlg.h: 헤더 파일
//

#pragma once


// CPracMFC2Dlg 대화 상자
class CPracMFC2Dlg : public CDialogEx
{
private:
	CCheckListBox m_item_list;  /*■이거추가함*/
public:
	CPracMFC2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	void CalcTotalPrice();
	void ChangeText(CListBox* ap_list_box, int a_index, const wchar_t* ap_string);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACMFC2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedShowBtn();
	afx_msg void OnLbnSelchangeItemList();
	CListBox m_count_list;
};
