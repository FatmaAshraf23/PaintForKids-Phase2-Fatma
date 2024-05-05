#include "CutAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CutAction::CutAction(ApplicationManager* pApp) : Action(pApp) {}

void CutAction::ReadActionParameters() {}

void CutAction::Execute() {
	CFigure* figure = pManager->GetFigure(p.x, p.y);
	Output* pOut = pManager->GetOutput();
	pManager->SetClipboard();


	if (pManager->GetClipboard() == NULL) {
		pOut->PrintMessage("Cannot excute Action. Clipboard is empty.");
	}
	else {
		pManager->RemoveFigure();
		figure->SetSelected(false);
	}
}
 

