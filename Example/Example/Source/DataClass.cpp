#include "DataClass.h"

map<string, DataClass*> DataClass::_map;
DataClass* DataClass::_default = nullptr;

DataClass* DataClass::getByName(const string& name)
{
	auto it = _map.find(name);

	if (it != _map.end())
	{
		return it->second;
	}

	return _default;
}

bool DataClass::hasByName(const string& name)
{
	auto it = _map.find(name);
	return it != _map.end() ? true : false;
}

DataClass* DataClass::add(const string& name, DataClass* newItem)
{
	auto it = _map.find(name);

	if (it != _map.end())
	{
		return it->second;
	}

	if (!newItem)
	{
		newItem = new DataClass();
	}

	newItem->setName(name);
	_map[name] = newItem;

	return newItem;
}

void DataClass::remove(const string& name)
{
	auto it = _map.find(name);

	if (it != _map.end())
	{
		_map.erase(it);
	}
}

void DataClass::clear()
{
	_map.clear();
}
