#ifndef TSENSORCONTROLLER_H
#define TSENSORCONTROLLER_H

#include "TsensorModel.h"
#include "TsensorView.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Controller
{
public:
	Controller();
	~Controller();
	void controller(TsensorModel *tsensor, TsensorView *tview);

private:
	bool log = true;
	bool exit = true;
};
#endif // !TSENSORCONTROLLER_H

