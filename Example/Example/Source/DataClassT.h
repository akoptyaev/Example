#pragma once

#include <string>
#include <map>
#include <memory>

using namespace std;

template <class ObjectT>
#define ObjectPtrT shared_ptr<ObjectT>

class DataClassT
{
protected:
	string _name = "DEFFAULT";

public:
	DataClassT() {};
	virtual ~DataClassT() {};

	void setName(const string& name) { _name = name; };
	const string name() { return _name; };

private:
	static map<string, ObjectPtrT> _map;
	static ObjectPtrT _defaultPtr;

public:
	static ObjectPtrT& getByName(const string& name);
	static bool hasByName(const string& name);

	static ObjectPtrT add(const string& name);
	static ObjectPtrT add(const string& name, ObjectT* newItem);

	static void remove(const string& name);
	static void clear();
};

template <class ObjectT>
map<string, ObjectPtrT> DataClassT<ObjectT>::_map;

template <class ObjectT>
ObjectPtrT DataClassT<ObjectT>::_defaultPtr;

template <class ObjectT>
ObjectPtrT& DataClassT<ObjectT>::getByName(const string& name)
{
	auto it = _map.find(name);

	if (it != _map.end())
	{
		return it->second;
	}

	if (!_defaultPtr)
	{
		_defaultPtr = make_shared<ObjectT>();
		_defaultPtr->setName("DEFAULT");
	}

	return _defaultPtr;
}

template <class ObjectT>
bool DataClassT<ObjectT>::hasByName(const string& name)
{
	auto it = _map.find(name);
	return it != _map.end() ? true : false;
}

template <class ObjectT>
ObjectPtrT DataClassT<ObjectT>::add(const string& name)
{
	auto it = _map.find(name);

	if (it != _map.end())
	{
		return it->second;
	}

	ObjectPtrT newItemPtr(new ObjectT);
	newItemPtr->setName(name);
	_map[name] = newItemPtr;

	return newItemPtr;
}

template <class ObjectT>
ObjectPtrT DataClassT<ObjectT>::add(const string& name, ObjectT* newItem)
{
	auto it = _map.find(name);

	if (it != _map.end())
	{
		return it->second;
	}

	ObjectPtrT newItemPtr(newItem ? newItem : new ObjectT);
	newItemPtr->setName(name);
	_map[name] = newItemPtr;

	return newItemPtr;
}

template <class ObjectT>
void DataClassT<ObjectT>::remove(const string& name)
{
	auto it = _map.find(name);

	if (it != _map.end())
	{
		_map.erase(it);
	}
}

template <class ObjectT>
void DataClassT<ObjectT>::clear()
{
	_map.clear();
}
