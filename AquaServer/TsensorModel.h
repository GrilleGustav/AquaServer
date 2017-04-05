#ifndef TSENSORMODEL_H
#define TSENSORMODEL_H

#include <string>
#include <vector>

using namespace std;

class TsensorModel
{
public:
	TsensorModel(string deviceFamily);
	TsensorModel();
	~TsensorModel();
	string getDeviceFamily();
	vector<string> getSensorIds();
	void addSensor(string id, string alias);
	void delSensorById(string id);
	void delSensorByAlias(string alias);
	void updateSensorById(string oldId, string newId);
	void updateAliasByAlias(string oldAlias, string newAlias);
	vector<pair<string, double>> getTemperature();
	void searchSensor();

private:
	double readSensor(string pfad);
	string dF;
	vector<pair<string, string>> sensors;
	const string OWPath = "/sys/devices/w1_bus_master1/";
	const string OWMasterPath = "/sys/devices/w1_bus_master1/";
	const string OWMasterName = "/sys/devices/w1_bus_master1/w1_master_name";
	const string OWMasterSlaveCount = "/sys/devices/w1_bus_master1/w1_master_slave_count";
	const string OWMasterMaxSlaveCount = "/sys/devices/w1_bus_master1/w1_master_max_slave_count";
	const string OWMasterSlaves = "/sys/devices/w1_bus_master1/w1_master_slaves";
};
#endif // !TSENSORMODEL_H

