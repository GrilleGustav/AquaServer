#ifndef TSENSORVIEW_H
#define TSENSORVIEW_H

using namespace std;

class TsensorView
{
public:
	TsensorView(const char*);
	TsensorView();
	~TsensorView();
	
	
private:
	void mainMenue(void);
	void temperatureMenue();

};
#endif // !TSENSORVIEW_H

