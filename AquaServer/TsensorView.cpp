#include "TsensorView.h"
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

void TsensorView::mainMenue(void)
{
	newtComponent menue1, form, listValue;
	void * re;
	int  value;

	newtCenteredWindow(40, 30, "Game Server Manager");
	form = newtForm(NULL, NULL, 0);


	menue1 = newtListbox(10, 1, 10, NEWT_FLAG_RETURNEXIT);
	newtListboxAppendEntry(menue1, "Install Game", (void *)1);
	newtListboxAppendEntry(menue1, "Deinstall Game", (void *)2);
	newtListboxAppendEntry(menue1, "Installed Games", (void *)3);
	newtListboxAppendEntry(menue1, "Game Option", (void *)4);
	newtListboxAppendEntry(menue1, "Kompatible Games", (void *)5);
	newtListboxAppendEntry(menue1, "Admin", (void *)6);
	newtListboxAppendEntry(menue1, "Close", (void *)7);
	newtFormAddComponents(form, menue1, NULL);
	newtRunForm(form);
	re = newtListboxGetCurrent(menue1);
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
		cout << value;
		break;
	case 5:
		cout << value;
		break;
	case 6:
		cout << value;
		this->admin();
		break;
	case 7:
		newtFinished();
		break;
	default:
		cout << "Error";
	}
}