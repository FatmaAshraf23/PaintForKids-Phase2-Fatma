#include "PasteAction.h"

#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp) {}

void PasteAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Paste: Click on a point to paste the figure.");
	pIn->GetPointClicked(p.x, p.y);
	pOut->ClearStatusBar();
}

void PasteAction::Execute() {
	if (pManager->GetClipboard() != NULL) {
		if (!(p.y >= UI.ToolBarHeight && p.y < UI.height - UI.StatusBarHeight)) {
		if(dynamic_cast<CRectangle*>(pManager->GetClipboard())){
		
		}
		//else if (dynamic_cast<CSquare*>(pManager->GetClipboard())) {}
		//else if (dynamic_cast<CCircle*>(pManager->GetClipboard())) {}
		//else if (dynamic_cast<CTriangle*>(pManager->GetClipboard())) {}
		//else if (dynamic_cast<CHexagon*>(pManager->GetClipboard())) {}
		}

	}
	
}

