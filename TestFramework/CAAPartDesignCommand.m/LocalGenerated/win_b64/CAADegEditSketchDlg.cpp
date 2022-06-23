

// ----------------------------------------
// BEGIN OF IMPLEMENTATION CODE
// ----------------------------------------
#include "CAADegEditSketchDlg.h"
#include "CATDlgGridConstraints.h"
#include "CATDlgFrame.h"
#include "CATDlgLabel.h"
#include "CATDlgFrame.h"
#include "CATDlgLabel.h"
#include "CATDlgPushButton.h"

// Begin of User Code
#include <iostream>
using namespace std;
// End of User Code

CAADegEditSketchDlg::CAADegEditSketchDlg(CATDialog* iParent, const CATString& iName)
    :CATDlgDialog(iParent,iName,0
|CATDlgWndOK
|CATDlgWndCANCEL
| CATDlgGridLayout
)
{

_Frame1 = NULL;
_Label1 = NULL;
_Frame2 = NULL;
_Label2 = NULL;
_pEditSketchPB = NULL;

// Begin of User Code

// End of User Code

}

CAADegEditSketchDlg::~CAADegEditSketchDlg()
{

// Begin of User Code

// End of User Code
_Frame1 = NULL;
_Label1 = NULL;
_Frame2 = NULL;
_Label2 = NULL;
_pEditSketchPB = NULL;

}



void CAADegEditSketchDlg::Build() 
{
int style=0;

// Begin of User Code

// End of User Code
_Frame1=new CATDlgFrame(this,(const char*)"Frame1",0|CATDlgGridLayout);
_Label1=new CATDlgLabel(_Frame1,(const char*)"Label1",0);
_Frame2=new CATDlgFrame(this,(const char*)"Frame2",0|CATDlgGridLayout);
_Label2=new CATDlgLabel(_Frame2,(const char*)"Label2",0);
_pEditSketchPB=new CATDlgPushButton(_Frame2,(const char*)"pEditSketchPB",0);
this->SetGridColumnResizable(0,1);
this->SetGridColumnResizable(2,1);
_Frame1->SetGridConstraints(0,0,3,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
_Frame1->SetGridColumnResizable(0,1);
_Label1->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_Frame2->SetGridConstraints(1,0,3,1,0|CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM);
_Frame2->SetGridColumnResizable(1,1);
_Label2->SetGridConstraints(0,0,1,1,0|CATGRID_LEFT|CATGRID_TOP);
_pEditSketchPB->SetGridConstraints(0,1,1,1,0|CATGRID_LEFT|CATGRID_TOP);

// Begin of User Code
   // Callbacks to edit the sketch
AddAnalyseNotificationCB(_pEditSketchPB,
	_pEditSketchPB->GetPushBActivateNotification(),
	(CATCommandMethod)&CAADegEditSketchDlg::EditSketch,
	NULL);
// End of User Code

}


// You can put here the implementation of class methods

// Begin of User Code
//--------------------------------------------------------------------------------------

void CAADegEditSketchDlg::EditSketch(CATCommand* cmd,
	CATNotification* iNotification,
	CATCommandClientData data)
{
	cout << " CAADegEditSketchDlg::EditSketch" << endl;

	// No need to delete the notification
// 	CAADegEditSketchNotification * pNotif = new CAADegEditSketchNotification();
	SendNotification(GetFather(), iNotification);
// 	pNotif = NULL;
}
// End of User Code


// End of implementation of class methods
