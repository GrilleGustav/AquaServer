#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>
#include "TsensorModel.h"
#include "TsensorView.h"
#include "Controller.h"

using namespace std;

int main()
{
	TsensorModel tsensor("<DS18B20>");
	TsensorView tview;
	int  rc;
	Controller tcontroller;
	tcontroller.controller(&tsensor, &tview);

	return 0;
}