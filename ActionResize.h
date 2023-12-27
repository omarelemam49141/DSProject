#ifndef ACTION_RESIZE_H
#define ACTION_RESIZE_H_H

#include "Actions/Action.h"

//Add ActionChngFillClr Action class
class ActionResize : public Action
{
public:
	class ActionResize(ApplicationManager* pApp);

	//Change the fikking color
	void Execute();
};

#endif

