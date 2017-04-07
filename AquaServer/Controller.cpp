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
}
