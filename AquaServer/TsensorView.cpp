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
	newtComponent Menue, form;
	void * re;
	int value;

	newtCenteredWindow(40, 30, "AquaServer");
	form = newtForm(NULL, NULL, 0);

	Menue = newtListbox(10, 1, 10, NEWT_FLAG_RETURNEXIT);
	newtListboxAppendEntry(Menue, "Temperature", (void *)1);
	newtListboxAppendEntry(Menue, "Light", (void *)2);
	newtListboxAppendEntry(Menue, "Ph-Wert", (void *)3);
	newtListboxAppendEntry(Menue, "Close", (void *)4);
	newtFormAddComponents(form, Menue, NULL);
	newtRunForm(form);
	re = newtListboxGetCurrent(Menue);
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
	newtComponent Menue, form;
	void * re;
	int value;

	newtCenteredWindow(40, 30, "AquaServer");
	form = newtForm(NULL, NULL, 0);

	Menue = newtListbox(10, 1, 10, NEWT_FLAG_RETURNEXIT);
	newtListboxAppendEntry(Menue, "Show Device Family", (void *)1);
	newtListboxAppendEntry(Menue, "Show SensorIds", (void *)2);
	newtListboxAppendEntry(Menue, "Get temperature", (void *)3);
	newtListboxAppendEntry(Menue, "Set Alias", (void *)4);
	newtListboxAppendEntry(Menue, "Change Sensor Id", (void *)5);
	newtListboxAppendEntry(Menue, "Change Alias", (void *)6);
	newtListboxAppendEntry(Menue, "Close", (void *)7);
	newtFormAddComponents(form, Menue, NULL);
	newtRunForm(form);
	re = newtListboxGetCurrent(Menue);
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