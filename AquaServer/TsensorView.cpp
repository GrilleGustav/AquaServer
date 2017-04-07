#include "TsensorView.h"
#include <iostream>
#include <newt.h>

TsensorView::TsensorView(const char*)
{
	newtInit();
	newtCls();
	this->mainMenue();
}

TsensorView::TsensorView()
{

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
	newtListboxAppendEntry(mainMenue, "Close AquaServer", (void *)4);
	newtFormAddComponents(form, mainMenue, NULL);
	newtRunForm(form);
	re = newtListboxGetCurrent(mainMenue);
	value = reinterpret_cast<int>(re);
	newtPopWindow();
	newtFormDestroy(form);
	
	switch (value)
	{
	case 1:
		cout << value;
		break;
	case 2:
		cout << value;
		break;
	case 3:
		cout << value;
		break;
	case 4:
		newtFinished();
		break;
	default:
		cout << "Error";
	}
}