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
	string input;
	
	while (this->exit)
	{
		input = this->console();
		if (input == "exit" || input == "quit")
		{
			this->exit = false;
		}
		else if (input == "get_temp_all")
		{

		}
	}
}
string Controller::console()
{
	cin >> ">>>:";
}