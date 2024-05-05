#ifndef COPY_ACTION_H
#define COPY_ACTION_H

#include "Action.h"

class CopyAction : public Action
{

public:
	CopyAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif