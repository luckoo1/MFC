
// PracMFCDlg.h: 헤더 파일
//

#pragma once


// CPracMFCDlg 대화 상자
class CPracMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CPracMFCDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	//virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedShowMsgBtn();
	afx_msg void OnEnChangeInputMsgEdit();
	afx_msg void OnBnClickedReadBtn();
	afx_msg void OnBnClickedWriteBtn();
	afx_msg void OnEnChangeEdit1();
#if 0
	//1.
protected:
	CString m_my_string;
#endif
public:
	CListBox m_chat_list;
	afx_msg void OnBnClickedAddBtn();
};
