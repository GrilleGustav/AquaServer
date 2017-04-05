#include "TsensorModel.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>

TsensorModel::TsensorModel(string deviceFamily)
{
	this->dF = deviceFamily;
}

TsensorModel::TsensorModel()
{

}

TsensorModel::~TsensorModel()
{
	cout << "model detroyed" << endl;
}

string TsensorModel::getDeviceFamily()
{
	return this->dF;
}

vector<string> TsensorModel::getSensorIds()
{
	vector<string> sen;
	if (this->sensors.size() != 0)
	{
		for (int i = 0; i < this->sensors.size(); i++)
		{
			sen.push_back(this->sensors[i].first);
		}
	}
	else
	{
		cout << "No senesors" << endl;
	}
	return sen;
}

void TsensorModel::addSensor(string id, string alias)
{
	bool exist = false;
	if (sensors.size() == 0)
	{
		this->sensors.push_back({ id, alias});
		cout << "New sensor added: " << id << endl;
	}
	else
	{
		for (int i = 0; i < sensors.size(); i++)
		{
			if (sensors[i].first == id)
			{
				exist = true;
				cout << "Sensorid aready exist!" << endl;
			}
			if (sensors[i].second == alias)
			{
				exist = true;
				cout << "Alias name already exist" << endl;
			}
		}
		if (exist == false)
		{
			this->sensors.push_back({ id, alias });
			cout << "New sensor added: " << id << endl;
		}
	}
}

void TsensorModel::delSensorById(string id)
{
	for (int i = 0; i < this->sensors.size(); i++)
	{
		if (this->sensors[i].first == id)
		{
			this->sensors.erase(this->sensors.begin() + i);
			cout << "Sensor with id '" << id << "' deleted." << endl;
		}
	}
}
void TsensorModel::delSensorByAlias(string alias)
{
	for (int i = 0; i < this->sensors.size(); i++)
	{
		if (this->sensors[i].second == alias)
		{
			this->sensors.erase(this->sensors.begin() + i);
			cout << "Sensor with id '" << alias << "' deleted." << endl;
		}
	}
}

void TsensorModel::updateSensorById(string oldId, string newId)
{
	bool exist = false;
	for (int i = 0; i < this->sensors.size(); i++)
	{
		if (this->sensors[i].first == newId)
		{
			exist = true;
		}
	}
	if (exist == false)
	{
		for (int i = 0; i < this->sensors.size(); i++)
		{
			if (this->sensors[i].first == oldId)
			{
				this->sensors[i].first = newId;
				exist = true;
				cout << "Sensor id changed to:" << newId << endl;
			}
		}
		if (exist == false)
		{
			cout << "Id to change doesn't exist" << endl;
		}
	}
	else
	{
		cout << "Sensor with id: " << newId << " already exist" << endl;
	}
}

void TsensorModel::updateAliasByAlias(string oldAlias, string newAlias)
{
	bool exist = false;
	for (int i = 0; i < this->sensors.size(); i++)
	{
		if (this->sensors[i].second == newAlias)
		{
			exist = true;
		}
	}
	if (exist == false)
	{
		for (int i = 0; i < this->sensors.size(); i++)
		{
			if (this->sensors[i].second == oldAlias)
			{
				this->sensors[i].second = newAlias;
				exist = true;
				cout << "Sensor Alias name changed to:" << newAlias << endl;
			}
		}
		if (exist == false)
		{
			cout << "Alias to change doesn't exist" << endl;
		}
	}
	else
	{
		cout << "Sensor with id: " << newAlias << " already exist" << endl;
	}
}

vector<pair<string, double>>  TsensorModel::getTemperature()
{
	string path;
	double temp;
	vector<pair<string, double>> temperature;
	if(this->sensors.size() != 0)
	{
		for (int i = 0; i < this->sensors.size(); i++)
		{
			path = this->OWPath;
			path = path + this->sensors[i].first + "/w1_slave";
			temp = this->readSensor(path);
			if (temp == 1000001)
			{
				cout << sensors[i].second << ": CRC Failed" << endl;
			}
			else
			{
				temperature.push_back({ this->sensors[i].first, temp });
			}
		}
	}
	else
	{
		cout << "No Sensors Connected" << endl;
	}
	return temperature;
}

double TsensorModel::readSensor(string path)
{


	fstream  file(path, ios::in);
	string data[3];
	string str;
	stringstream tmp;
	double temp;
	

	if (file)
	{
		for (int i = 0; !file.eof(); i++)
		{
			getline(file, data[i]);
		}
		if (data[0].substr(36, data[0].size()) == "YES")
		{
			tmp << data[1].substr(29, data[1].size()) << ends;
			tmp >> temp;
			temp /= 1000;
		}
		else
		{
			temp = 1000001;
		}
	}
	else
	{
		cout << "Wrong Pfad" << endl;
	}
	file.close();
	return temp;
}

void TsensorModel::searchSensor()
{
	fstream file(this->OWMasterSlaves, ios::in);
	string data;
	for (int i = 0; !file.eof(); i++)
	{
		if (this->dF == "<DS18B20>")
		{
			getline(file, data);
			if (data.substr(0, 3) == "28-")
			{
				this->addSensor(data, "alias_" + data);
			}
		}
	}

}