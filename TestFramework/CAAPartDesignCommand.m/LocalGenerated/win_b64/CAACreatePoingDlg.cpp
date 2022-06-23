

// ----------------------------------------
// BEGIN OF IMPLEMENTATION CODE
// ----------------------------------------
#include "CAACreatePoingDlg.h"
#include "CATDlgGridConstraints.h"
#include "CATDlgLabel.h"
#include "CATDlgSpinner.h"
#include "CATDlgLabel.h"
#include "CATDlgSpinner.h"
#include "CATDlgSpinner.h"
#include "CATDlgLabel.h"

// Begin of User Code
#include <iostream>
using namespace std;
// End of User Code

CAACreatePoingDlg::CAACreatePoingDlg(CATDialog* iParent, const CATString& iName)
    :CATDlgDialog(iParent,iName,0
|CATDlgWndOK
|CATDlgWndCANCEL
| CATDlgGridLayout
)
{

_Label1 = NULL;
_SpinnerX = NULL;
_Label2 = NULL;
_SpinnerY = NULL;
_SpinnerZ = NULL;
_Label3 = NULL;

// Begin of User Code

// End of User Code

}

CAACreatePoingDlg::~CAACreatePoingDlg()
{

// Begin of User Code

// End of User Code
_Label1 = NULL;
_SpinnerX = NULL;
_Label2 = NULL;
_SpinnerY = NULL;
_SpinnerZ = NULL;
_Label3 = NULL;

}



void CAACreatePoingDlg::Build() 
{
int style=0;

// Begin of User Code

// End of User Code
_Label1=new CATDlgLabel(this,(const char*)"Label1",0);
_SpinnerX=new CATDlgSpinner(this,(const char*)"SpinnerX",0);
_Label2=new CATDlgLabel(this,(const char*)"Label2",0);
_SpinnerY=new CATDlgSpinner(this,(const char*)"SpinnerY",0);
_SpinnerZ=new CATDlgSpinner(this,(const char*)"SpinnerZ",0);
_Label3=new CATDlgLabel(this,(const char*)"Label3",0);
this->SetGridColumnResizable(1,1);
this->SetGridColumnResizable(2,1);
this->SetGridColumnResizable(4,1);
_Label1->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_SpinnerX->SetGridConstraints(0,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_SpinnerX->SetRange(-10000.f,10000.f,20000);
_Label2->SetGridConstraints(2,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_SpinnerY->SetGridConstraints(2,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_SpinnerY->SetRange(-10000.f,10000.f,20000);
_SpinnerZ->SetGridConstraints(4,1,1,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP);
_SpinnerZ->SetRange(-10000.f,10000.f,20000);
_Label3->SetGridConstraints(4,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);

// Begin of User Code
AddAnalyseNotificationCB(this, this->GetDiaOKNotification(),
(CATCommandMethod)&CAACreatePoingDlg::EnterCB,
NULL);
AddAnalyseNotificationCB(this, this->GetDiaAPPLYNotification(),
(CATCommandMethod)&CAACreatePoingDlg::EnterCB,
NULL);
// End of User Code

}


// You can put here the implementation of class methods

// Begin of User Code
CATMathPoint & CAACreatePoingDlg::GetValue()
{
	return _Point;
}

void CAACreatePoingDlg::EnterCB(CATCommand           * iPublisher,
	CATNotification      * iNotification,
	CATCommandClientData   iUsefulData)
{
	cout << "CAADegPointEditor::EnterCB" << endl;

	_Point.SetCoord(_SpinnerX->GetCurrentValue(),
		_SpinnerY->GetCurrentValue(),
		_SpinnerZ->GetCurrentValue());

	// This notification enables the state command to receive it and 
	// to value its dialog agent. 
	SendNotification(GetFather(), iNotification);

}
// End of User Code


// End of implementation of class methods
