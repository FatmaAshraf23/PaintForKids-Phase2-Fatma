#include "CopyAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CopyAction::CopyAction(ApplicationManager* pApp) : Action(pApp){}

void CopyAction:: ReadActionParameters(){}

void CopyAction::Execute() {
	pManager->CopyFigureToClipboard();
}

