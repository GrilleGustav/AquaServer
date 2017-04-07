#ifndef TSENSORVIEW_H
#define TSENSORVIEW_H

using namespace std;

class TsensorView
{
public:
	TsensorView(const char*);
	~TsensorView();

private:
	void mainMenue();
	void temperature();

};
#endif // !TSENSORVIEW_H

