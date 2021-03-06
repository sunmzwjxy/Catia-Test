//===================================================================
// COPYRIGHT  2022/03/11
//===================================================================
// CAADegEditSketchCmd.cpp
// Header definition of class CAADegEditSketchCmd
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2022/03/11 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CAADegEditSketchCmd_H
#define CAADegEditSketchCmd_H

#include "CATStateCommand.h"
#include "CATSysBoolean.h"

// DialogEngine framework
class CATDialogAgent;
class CATEditAgent;
class CATFeatureImportAgent;

// VisualizationInterfaces framework
class CATPathElement;

class CAADegEditSketchDlg;

// CATMecModLiveUseItf framework
class CATIMmiMechanicalFeature;

//----------------------------------------------------------------------

/**
* Describe your command here.
* <p>
* Using this prefered syntax will enable mkdoc to document your class.
* <p>
* refer to programming resources of Dialog engine framework.
* (consult base class description).
*/
class CAADegEditSketchCmd: public CATStateCommand
{
// Allows customization/internationalization of command's messages
// ---------------------------------------------------------------
DeclareResource( CAADegEditSketchCmd, CATStateCommand )

public:
	CAADegEditSketchCmd();
virtual ~CAADegEditSketchCmd();

/**
* Defines the command automata.
* <br>
* <i>(states, transitions and agents)</i>
*/
virtual void     BuildGraph();

/**
* Action associated to state transitions.
*/
virtual CATBoolean  ActionOne(void * data);

// Filter method
// ----------------
// Filter to test that the Pad has a sketch has profile
//
CATBoolean   TestProfile(CATDialogAgent * iAgent, void *iUsefulData);

// SelectPad : called when a Pad has been selected
CATBoolean SelectPad(void * iUsefuldata);
CATBoolean UndoSelectPad(void * iUsefuldata);
CATBoolean RedoSelectPad(void * iUsefuldata);
CATPathElement * ProvideProfileToEdit(CATClassId iDummy);

// TriggerEditSketch: called when the end user has clicked on the Sketch button
CATBoolean TriggerEditSketch(void *iUsefuldata);

// EditSketch: called when the end user leaves the stacked workbench (the sketcher)
CATBoolean EditSketch(void *iUsefuldata);

/**
 * @param oMecFeatOnProfile [out, IUnknown#Release]
 */
HRESULT FindProfile(CATBaseUnknown  * iSelectedPad,
	CATIMmiMechanicalFeature ** oMecFeatOnProfile);

private:

	// The dialog box associated with the command
	CAADegEditSketchDlg      * _pDialogBox;

	// Agent to enter the Pad
	CATFeatureImportAgent    * _pFeatureAgent;

	// Agent to ask the profile edition 
	CATDialogAgent           * _pTriggerAgent;

	// Agent to execute the workbench's stack.
	CATEditAgent             * _pEditAgent;

};

//----------------------------------------------------------------------

#endif
