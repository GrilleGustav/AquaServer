#include "TsensorView.h"
#include <iostream>
#include <newt.h>

TsensorView::TsensorView(const char*)
{
	newtInit();
	newtCls();
}

TsensorView::TsensorView()
{
	this->mainMenue();
}

TsensorView::~TsensorView()
{
	
}

void TsensorView::mainMenue()
{
	newtComponent mainMenue, form;
	void * re;
	int value;

	newtCenteredWindow(40, 30, "AquaServer");
	form = newtForm(NULL, NULL, 0);

	mainMenue = newtListbox(10, 1, 10, NEWT_FLAG_RETURNEXIT);
	newtListboxAppendEntry(mainMenue, "Temperature", (void *)1);
	newtListboxAppendEntry(mainMenue, "Light", (void *)2);
	newtListboxAppendEntry(mainMenue, "Ph-Wert", (void *)3);
	newtListboxAppendEntry(mainMenue, "Close", (void *)4);
	newtFormAddComponents(form, mainMenue, NULL);
	newtRunForm(form);
	re = newtListboxGetCurrent(mainMenue);
	value = reinterpret_cast<int>(re);
	newtPopWindow();
	newtFormDestroy(form);
	switch (value)
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
		newtFinished();
		break;
	default:
		break;
	}
}
void TsensorView::temperatureMenue()
{
	newtComponent temperatureMenue, form;
	void * re;
	int value;

	newtCenteredWindow(40, 30, "AquaServer");
	form = newtForm(NULL, NULL, 0);

	temperatureMenue = newtListbox(10, 1, 10, NEWT_FLAG_RETURNEXIT);
	newtListboxAppendEntry(temperatureMenue, "Show Device Family", (void *)1);
	newtListboxAppendEntry(temperatureMenue, "Show SensorIds", (void *)2);
	newtListboxAppendEntry(temperatureMenue, "Get temperature", (void *)3);
	newtListboxAppendEntry(temperatureMenue, "Set Alias", (void *)4);
	newtListboxAppendEntry(temperatureMenue, "Change Sensor Id", (void *)5);
	newtListboxAppendEntry(temperatureMenue, "Change Alias", (void *)6);
	newtListboxAppendEntry(temperatureMenue, "Close", (void *)7);
	newtFormAddComponents(form, temperatureMenue, NULL);
	newtRunForm(form);
	re = newtListboxGetCurrent(temperatureMenue);
	value = reinterpret_cast<int>(re);
	newtPopWindow();
	newtFormDestroy(form);
	switch (value)
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
		cout << "3";
		break;
	case 5:
		cout << "3";
		break;
	case 6:
		cout << "3";
		break;
	case 7:
		this->mainMenue();
		break;
	default:
		break;
	}
}