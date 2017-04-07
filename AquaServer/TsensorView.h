#ifndef TSENSORVIEW_H
#define TSENSORVIEW_H

using namespace std;

class TsensorView
{
public:
	TsensorView(const char*);
	TsensorView();
	~TsensorView();
	int mainMenue(void);
	
private:
	
	int temperature();

};
#endif // !TSENSORVIEW_H

