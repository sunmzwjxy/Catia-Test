
//===================================================================
// COPYRIGHT  2022/03/07
//===================================================================
// CAAComponentAddin.cpp
// Header definition of class CAAComponentAddin
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2022/03/07 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CAAComponentAddin_H
#define CAAComponentAddin_H

#include "CATBaseUnknown.h"
class CATCmdContainer;

#include "CATCreateWorkshop.h"
#include "CATAfrCommandHeader.h"

#include "CATIAfrGeneralWksAddin.h"

//-----------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////
// ****	Addin into CATIAfrGeneralWksAddin (all)
//////////////////////////////////////////////////////////////////////////

class CAAComponentAddin: public CATBaseUnknown

{
CATDeclareClass;

public:

// Standard constructors and destructors
// -------------------------------------
CAAComponentAddin ();
virtual ~CAAComponentAddin ();

//
// TODO: Add your methods for this class here.
//
void CreateCommands();
CATCmdContainer *CreateToolbars();


private:
// Copy constructor and equal operator
// -----------------------------------
CAAComponentAddin (CAAComponentAddin &);
CAAComponentAddin& operator=(CAAComponentAddin&);
};

//-----------------------------------------------------------------------

#endif
