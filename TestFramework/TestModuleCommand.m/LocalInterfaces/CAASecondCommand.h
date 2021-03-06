//===================================================================
// COPYRIGHT  2022/03/08
//===================================================================
// CAASecondCommand.cpp
// Header definition of class CAASecondCommand
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2022/03/08 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CAASecondCommand_H
#define CAASecondCommand_H

#include "CATStateCommand.h"
#include "CATSysBoolean.h"


//----------------------------------------------------------------------

/**
* Describe your command here.
* <p>
* Using this prefered syntax will enable mkdoc to document your class.
* <p>
* refer to programming resources of Dialog engine framework.
* (consult base class description).
*/
class CAASecondCommand: public CATStateCommand
{
// Allows customization/internationalization of command's messages
// ---------------------------------------------------------------
DeclareResource( CAASecondCommand, CATStateCommand )

public:
	CAASecondCommand();
virtual ~CAASecondCommand();

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

private:

};

//----------------------------------------------------------------------

#endif
