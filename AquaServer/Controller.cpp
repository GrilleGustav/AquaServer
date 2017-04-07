#include "Controller.h"
#include "TsensorView.h"
#include "TsensorModel.h"
#include <iostream>

using namespace std;

Controller::Controller()
{

}

Controller::~Controller()
{

}

void Controller::controller(TsensorModel *tsensor, TsensorView *tview)
{
	TsensorView view("Aquarium Server");
	switch (view.mainMenue())
	{
	case 1:
		cout << "1";
		break;
	case 2:
		cout << "2";
		break;
	case 3:
		cout << "3";
		break;
	case 4:
		view.~TsensorView();
		break;
	default:
		break;
	}
}
