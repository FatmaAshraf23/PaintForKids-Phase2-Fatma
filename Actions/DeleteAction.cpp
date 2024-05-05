#include "DeleteAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"


DeleteAction::DeleteAction(ApplicationManager* point) :Action(point) {}

void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Delete Figures");


}

void DeleteAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->RemoveFigure();
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
}