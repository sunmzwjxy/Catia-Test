

// BEGIN OF HEADER CODE
// ----------------------------------------
    
#ifndef CAACreatePoingDlg_h
#define CAACreatePoingDlg_h

#include "CATDlgDialog.h"
class CATDlgLabel;
class CATDlgSpinner;
class CATDlgLabel;
class CATDlgSpinner;
class CATDlgSpinner;
class CATDlgLabel;

// Begin of User Code
#include "CATMathPoint.h"
// End of User Code

class  CAACreatePoingDlg : public CATDlgDialog {
DeclareResource(CAACreatePoingDlg, CATDlgDialog)

public:
	CAACreatePoingDlg(CATDialog * iParent, const CATString& iDialogName);
	
	virtual ~CAACreatePoingDlg();
	void Build();

	// Copy ctor and assignment operators are declared but not defined by infra
	CAACreatePoingDlg(const CAACreatePoingDlg&);
	CAACreatePoingDlg& operator= (const CAACreatePoingDlg&);
	
private:
CATDlgLabel* _Label1;
CATDlgSpinner* _SpinnerX;
CATDlgLabel* _Label2;
CATDlgSpinner* _SpinnerY;
CATDlgSpinner* _SpinnerZ;
CATDlgLabel* _Label3;

// Begin of User Code
	
	// Point valuated in the EnterCB method and returned by the GetValue
	// method
	CATMathPoint  _Point;

	//
	// EnterCB 
	// -------
	// The dialog box is closed and values are assigned from the 
	// dialog box to the current object.
	//
void EnterCB(CATCommand          * iPublisher,
	CATNotification     * iNotification,
	CATCommandClientData  iUsefulData);

public:
	// Returns the 3D Coordinnates
	CATMathPoint & GetValue();

// End of User Code

};

#endif
