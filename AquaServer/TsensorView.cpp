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
	newtFinished();
}

TsensorView::~TsensorView()
{
	
}

int TsensorView::mainMenue()
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
	return value;
}