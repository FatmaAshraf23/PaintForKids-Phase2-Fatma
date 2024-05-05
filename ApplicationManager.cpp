#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"



//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	SelectedFigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;

	for (int i = 0; i < MaxFigCount; i++)
		SelectedFig[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case SELECT: //select
		pAct = new SelectAction(this);
		break;

	case DELETE_ITMS:
		pAct = new DeleteAction(this);

	case COPY:
		pAct = new CopyAction(this);
		break;

		case PASTE:
		pAct = new PasteAction(this);

	case EXIT:
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}

CFigure*ApplicationManager::GetClipboard() {
		return Clipboard;
}

void ApplicationManager::SetClipboard() {
	Clipboard = SelectedFig[0];
	pOut->PrintMessage("Figure is copied to clipboard");
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->WithinFigure(x, y))
		{
			return FigList[i];
		}
	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}

void ApplicationManager::SelectedFigSetter(CFigure* pSelected)
{
	SelectedFig[SelectedFigCount] = pSelected;
	SelectedFigCount++;
}

void ApplicationManager::DeselectFigures()
{
	for (int i = 0; i < SelectedFigCount; i++)
	{
		SelectedFig[i]->SetSelected(false);
		SelectedFig[i] = NULL;
	}
	SelectedFigCount = 0;
}

void ApplicationManager::DeselectFigure(CFigure* pFig)
{
	for (int i = SelectedFigCount - 1; i > 0; i--)
	{
		if (SelectedFig[i] == pFig)
		{
			SelectedFig[i] = SelectedFig[SelectedFigCount - 1];
			SelectedFig[SelectedFigCount - 1] = NULL;
			SelectedFigCount--;
		}
	}
}

void ApplicationManager::RemoveFigure()
{
	if (SelectedFigCount != 0)
	{
		if (SelectedFigCount != FigCount)
		{
			for (int i = 0; i < SelectedFigCount; i++) {
				for (int j = 0; j < FigCount; j++) {
					if (SelectedFig[i] == FigList[j]) {
						SelectedFig[i] = SelectedFig[SelectedFigCount - 1];
						SelectedFig[SelectedFigCount - 1] = NULL;
						FigList[j] = FigList[FigCount - 1];
						FigList[FigCount - 1] = NULL;
						SelectedFigCount--;
						FigCount--;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < SelectedFigCount; i++)
			{
				SelectedFig[i] = NULL;
				SelectedFigCount--;
			}
			for (int i = 0; i < FigCount; i++)
			{
				FigList[i] = NULL;
				FigCount--;
			}
		}
	}
	else
		pOut->PrintMessage("Please select figures to delete. ");

}

void ApplicationManager::CopyFigureToClipboard() {
	if (SelectedFigCount == 1)
	{
		SetClipboard();
	}
	else if (SelectedFigCount>1) {
		pOut->PrintMessage("Cannot copy more than one  figure.");
	}
	else if (SelectedFigCount == 00) {
		pOut->PrintMessage("No figure is selected. Please select a figure and try again.");
	}


}

CFigure* ApplicationManager::PasteFigureFromClipboard() const {
	return Clipboard;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}