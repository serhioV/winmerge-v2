/** 
 * @file  LoadSaveCodepageDlg.h
 *
 * @brief Declaration of the dialog used to select codepages
 */
// ID line follows -- this is updated by SVN
// $Id: LoadSaveCodepageDlg.h 5444 2008-06-07 06:48:49Z kimmov $


#if !defined(AFX_LOADSAVECODEPAGEDLG_H__B9A16700_6F1A_4DF1_8EB3_0A1D772DCE91__INCLUDED_)
#define AFX_LOADSAVECODEPAGEDLG_H__B9A16700_6F1A_4DF1_8EB3_0A1D772DCE91__INCLUDED_
#pragma once

#include "CMoveConstraint.h"
#include "UnicodeString.h"

/////////////////////////////////////////////////////////////////////////////
// CLoadSaveCodepageDlg dialog

class CLoadSaveCodepageDlg : public CDialog
{
public:
// Construction
	CLoadSaveCodepageDlg(int nFiles, CWnd* pParent = NULL);   // standard constructor
	void SetLeftRightAffectStrings(const String & sAffectsLeft, const String & sAffectsMiddle, const String & sAffectsRight);
	void EnableSaveCodepage(bool enable) { m_bEnableSaveCodepage = enable; }
	void SetCodepages(int codepage) { m_nLoadCodepage = m_nSaveCodepage = codepage; }

// Reading results
	int GetLoadCodepage() const { return m_nLoadCodepage; }
	int GetSaveCodepage() const { return m_nSaveCodepage; }
	bool DoesAffectLeft() const { return m_bAffectsLeft; }
	bool DoesAffectMiddle() const { return m_bAffectsMiddle; }
	bool DoesAffectRight() const { return m_bAffectsRight; }

// Implementation methods
private:
	void UpdateDataToWindow() { UpdateData(FALSE); }
	void UpdateDataFromWindow() { UpdateData(TRUE); }
	void EnableDlgItem(int item, bool enable);
	void UpdateSaveGroup();

// Implementation data
private:
	prdlg::CMoveConstraint m_constraint; 

// Dialog Data
	//{{AFX_DATA(CLoadSaveCodepageDlg)
	enum { IDD = IDD_LOAD_SAVE_CODEPAGE };
	bool    m_bAffectsLeft;
	bool    m_bAffectsMiddle;
	bool    m_bAffectsRight;
	bool    m_bLoadSaveSameCodepage;
	CButton m_AffectsLeftBtn;
	CButton m_AffectsMiddleBtn;
	CButton m_AffectsRightBtn;
	//}}AFX_DATA
	String m_sAffectsLeftString;
	String m_sAffectsMiddleString;
	String m_sAffectsRightString;
	int m_nLoadCodepage;
	int m_nSaveCodepage;
	bool m_bEnableSaveCodepage;
	int m_nFiles;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoadSaveCodepageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoadSaveCodepageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAffectsLeftBtnClicked();
	afx_msg void OnAffectsMiddleBtnClicked();
	afx_msg void OnAffectsRightBtnClicked();
	afx_msg void OnLoadSaveSameCodepage();
	virtual void OnOK ();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOADSAVECODEPAGEDLG_H__B9A16700_6F1A_4DF1_8EB3_0A1D772DCE91__INCLUDED_)