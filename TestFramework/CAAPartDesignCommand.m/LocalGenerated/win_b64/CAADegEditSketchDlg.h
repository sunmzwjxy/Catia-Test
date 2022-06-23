

// BEGIN OF HEADER CODE
// ----------------------------------------
    
#ifndef CAADegEditSketchDlg_h
#define CAADegEditSketchDlg_h

#include "CATDlgDialog.h"
class CATDlgFrame;
class CATDlgLabel;
class CATDlgFrame;
class CATDlgLabel;
class CATDlgPushButton;

// Begin of User Code

// End of User Code

class  CAADegEditSketchDlg : public CATDlgDialog {
DeclareResource(CAADegEditSketchDlg, CATDlgDialog)

public:
	CAADegEditSketchDlg(CATDialog * iParent, const CATString& iDialogName);
	
	virtual ~CAADegEditSketchDlg();
	void Build();

	// Copy ctor and assignment operators are declared but not defined by infra
	CAADegEditSketchDlg(const CAADegEditSketchDlg&);
	CAADegEditSketchDlg& operator= (const CAADegEditSketchDlg&);
	
private:
CATDlgFrame* _Frame1;
CATDlgLabel* _Label1;
CATDlgFrame* _Frame2;
CATDlgLabel* _Label2;
CATDlgPushButton* _pEditSketchPB;

// Begin of User Code
	// Callback method to send an event 
void EditSketch(CATCommand* cmd,
	CATNotification* iNotification,
	CATCommandClientData data);
// End of User Code

};

#endif
