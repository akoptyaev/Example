#pragma once

#include <string>
#include <map>

using namespace std;

class DataClass
{
protected:
	string _name = "DEFFAULT";

public:
	string _data = "NONE";

public:
	DataClass(const string& data) { _data = data; };
	DataClass() {};
	virtual ~DataClass() {};

	void setName(const string& name) { _name = name; };
	const string name() { return _name; };

public:
	static map<string, DataClass*> _map;
	static DataClass* _default;

public:
	static DataClass* getByName(const string& name);
	static bool hasByName(const string& name);

	static DataClass* add(const string& name, DataClass* newItem = nullptr);

	static void remove(const string& name);
	static void clear();
};
