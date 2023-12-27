#include "ActionResize.h"
/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionResize::ActionResize(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
//Omar
void ActionResize::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Type the multiplication number");
	float factor = pGUI->GetNumber(); //get a user input number
	bool selected = pManager->ResizeSelectedObjects(factor);//if no object is selected return false

	if (!selected)
	{
		pGUI->PrintMessage("You must select any figure first");
		return;
	}

	pGUI->ClearDrawArea();
	pManager->UpdateInterface();
	pGUI->PrintMessage("Resized successfully");

	/*color BGColors[] = {GREY, WHITE, LIGHTYELLOW}; */
	//Get a Pointer to the Interface
}
