//===================================================================
// COPYRIGHT  2022/03/08
//===================================================================
// CAADegCreatePointCmd.cpp
// Header definition of class CAADegCreatePointCmd
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2022/03/08 Creation: Code generated by the 3DS wizard
//===================================================================

// Local Framework
#include "CAADegCreatePointCmd.h"
#include "CAACreatePoingDlg.h"

// STL
#include <iostream>
using namespace std;

//ApplicationFrame Framework
#include "CATFrmEditor.h"    
#include "CATApplicationFrame.h"    


//DialogEngine Framework
#include "CATIndicationAgent.h"
#include "CATDialogTransition.h"
#include "CATPanelState.h"
#include "CATCustomizableTransition.h"

//
#include "CATFrmNavigGraphicWindow.h"
#include "CATNavigBox.h"

#include "CATMathPlane.h"
#include "CATGeoFactory.h"
#include "CATCGMContainerMngt.h"
#include "CATCartesianPoint.h"

#include "CATCreateExternalObject.h"
CATCreateClass( CAADegCreatePointCmd);


//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
CAADegCreatePointCmd::CAADegCreatePointCmd() :
CATStateCommand ("CAADegCreatePointCmd", CATDlgEngOneShot, CATCommandModeShared)
//  Valid states are CATDlgEngOneShot and CATDlgEngRepeat
,_Indication(NULL),
_pPointEditor(NULL),
_pUIActiveObject(NULL), _pContainer(NULL)
{
	// 1- We keep the root object 
	// 
// 	CATFrmEditor * pEditor = GetEditor();
// 	if (NULL != pEditor)
// 	{
// 		CATPathElement path = pEditor->GetUIActiveObject();
// 		if (path.GetSize() > 0)
// 		{
// 			_pUIActiveObject = path[path.GetSize() - 1];
// 			if (NULL != _pUIActiveObject)
// 			{
// 				_pUIActiveObject->AddRef();
// 			}
// 		}
// 	}
// 
// 	if (NULL != _pUIActiveObject)
// 	{
// 		// Point will be created by this container and added inside
// 		CAAISysAccess * piSysAccess = NULL;
// 		HRESULT rc = _pUIActiveObject->QueryInterface(IID_CAAISysAccess, (void**)&piSysAccess);
// 		if (SUCCEEDED(rc))
// 		{
// 			piSysAccess->GetContainer(&_pContainer);
// 			piSysAccess->Release();
// 			piSysAccess = NULL;
// 		}
// 	}
}

//-------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------
CAADegCreatePointCmd::~CAADegCreatePointCmd()
{
	if (_Indication != NULL)
	{
		_Indication->RequestDelayedDestruction();
		_Indication = NULL;
	}


	if (_pPointEditor != NULL)
	{
		_pPointEditor->RequestDelayedDestruction();
		_pPointEditor = NULL;
	}
}


//-------------------------------------------------------------------------
// BuildGraph()
//-------------------------------------------------------------------------
void CAADegCreatePointCmd::BuildGraph()
{
	CATDlgWindow * pParent = CATApplicationFrame::GetFrame()->GetMainWindow();
	_pPointEditor = new CAACreatePoingDlg(pParent, "Point Editor");
	_pPointEditor->Build();
	
	_Indication = new CATIndicationAgent("Indication");

	CATPanelState * stState = new CATPanelState(this, "GetPointID", _pPointEditor);
	SetInitialState(stState);
	stState->AddDialogAgent(_Indication);

	//4-Defines the transition triggered by the Indication Agent
//..........................................................

	CATDialogTransition *pFirstTransition = AddTransition
	(
		stState,
		stState,
		AndCondition(IsOutputSetCondition(_Indication),
			Condition((ConditionMethod)& CAADegCreatePointCmd::CheckPoint)),
		Action((ActionMethod)& CAADegCreatePointCmd::CreatePointByIndication)
	);

	//5- Completes the Apply transition
//..................................

// Sets a condition to the Apply transition
	CATCustomizableTransition * pCustoTransition = stState->GetApplyTransition();
	if (NULL != pCustoTransition)
	{
		CATDialogTransition *pDiaApplyTransition = pCustoTransition;
		pDiaApplyTransition->SetCondition(Condition((ActionMethod)&CAADegCreatePointCmd::CheckPoint));

		// Sets an action to the Apply transition
		pDiaApplyTransition->SetAction(Action((ActionMethod)&CAADegCreatePointCmd::CreatePointByBox));
	}

	//6- Completes the Ok transition
	//..............................

	// Sets a condition to the Ok transition
	CATCustomizableTransition * pOkTransition = stState->GetOkTransition();
	if (NULL != pOkTransition)
	{
		CATDialogTransition *pDiaOkTransition = pOkTransition;

		pDiaOkTransition->SetCondition(Condition((ActionMethod)&CAADegCreatePointCmd::CheckPoint));

		// Sets an action to the Ok transition
		pDiaOkTransition->SetAction(Action((ActionMethod)&CAADegCreatePointCmd::CreatePointByBox));
	}

	// As the state was created explicitely by "new" instead of the 
	// GetInitialState method, it must be released.
	stState->Release();
	stState = NULL;
}


//-------------------------------------------------------------------------
// ActionOne ()
//-------------------------------------------------------------------------
CATBoolean CAADegCreatePointCmd::ActionOne( void *data )
{
// TODO: Define the action associated with the transition
// ------------------------------------------------------

return TRUE;
}

//-------------------------------------------------------------------------
CATStatusChangeRC CAADegCreatePointCmd::Activate(CATCommand *iCmd, CATNotification *iNotif)
{
	cout << " CAADegCreatePointCmd::Activate" << endl;

	if (NULL != _pPointEditor)
	{
		_pPointEditor->SetVisibility(CATDlgShow);
	}

	return CATStatusChangeRCCompleted;
}

//-------------------------------------------------------------------------
CATStatusChangeRC CAADegCreatePointCmd::Cancel(CATCommand * iCmd, CATNotification * iNotif)
{
	cout << " CAADegCreatePointCmd::Cancel" << endl;

	_pPointEditor->SetVisibility(CATDlgHide);

	return CATStatusChangeRCCompleted;
}

//-------------------------------------------------------------------------------

CATStatusChangeRC CAADegCreatePointCmd::Desactivate(CATCommand *iCmd, CATNotification *iNotif)
{
	cout << " CAADegCreatePointCmd::Desactivate" << endl;

	_pPointEditor->SetVisibility(CATDlgHide);

	return (CATStatusChangeRCCompleted);
}

//----------------------Condition methods's PART -----------------------------

CATBoolean CAADegCreatePointCmd::CheckPoint(void *iDummy)
{
	cout << "CAADegCreatePointCmd::CheckPosition" << endl;

	CATBoolean rc = TRUE;

// 	// If no Root Object, it's impossible to create element
// 	if ((NULL == _pUIActiveObject) || (NULL == _pContainer)) rc = FALSE;
	return rc;
}

//----------------------Action methods's PART -----------------------------
CATBoolean CAADegCreatePointCmd::CreatePointByIndication(void *iDummy)
{
	cout << "CAADegCreatePointCmd::CreatePointByIndication" << endl;

	// Computes a CATMathPoint from the dialog agent
	CATMathPoint Point;
	CATMathPoint2D point2D = _Indication->GetValue();

	// Retrieve the plane automatically defined
	CATMathPlane Plane = _Indication->GetMathPlane();
	Plane.EvalPoint(point2D.GetX(), point2D.GetY(), Point);

	// Creates a new point and updates the display
	NewPoint(Point);

	// recycles the agent
	_Indication->InitializeAcquisition();
	return TRUE;
}

//-----------------------------------------------------------------------------

CATBoolean CAADegCreatePointCmd::CreatePointByBox(void *iDummy)
{
	cout << "CAADegCreatePointCmd::CreatePointByIndication" << endl;

	// Creates a new point and updates the display
	NewPoint(_pPointEditor->GetValue());
	return TRUE;
}

//----------------------MODEL 's PART -----------------------------------------------

void CAADegCreatePointCmd::NewPoint(const CATMathPoint &iPoint)
{
	// Retrieves the current window 
	CATFrmLayout * pLayout = CATFrmLayout::GetCurrentLayout();
	if (NULL == pLayout) return;

	CATFrmWindow * pCurrentWindow = pLayout->GetCurrentWindow();
	if (NULL == pCurrentWindow) return;

	// If it is a CATFrmNavigGraphicWindow, it is possible to
	// retrieve a CATNavigBox pointer
	//
	if (1 != pCurrentWindow->IsAKindOf("CATFrmNavigGraphicWindow")) return;

	CATFrmNavigGraphicWindow * pFrmNavigGraphicWindow =
		(CATFrmNavigGraphicWindow*)pCurrentWindow;

	CATNavigBox * pNavigBox = NULL;
	pNavigBox = pFrmNavigGraphicWindow->GetNavigBox();

	if (NULL == pNavigBox) return;


	CATGeoFactory* piGeomFactory = ::CATCreateCGMContainer();
	if (NULL == piGeomFactory) return;

	CATCartesianPoint * pCartP = piGeomFactory->CreateCartesianPoint(iPoint);

	pNavigBox->AddRoot(pCartP);
}
