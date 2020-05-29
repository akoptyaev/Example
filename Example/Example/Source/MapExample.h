
#pragma once

#include "TestClass.h"

#include <map>
#include <algorithm>

// Нет std::sort(...)

using namespace std;

void funMap()
{
	TestClass::line("funMap");

	{
		map<int, TestClass> testMap;
		testMap[1] = "dfgdf";
	}
	{
		TestClass::lineShort("&");

		map<string, TestClass> testMap;

		testMap.insert(pair<string, TestClass>("third", TestClass("thisrdItem")));
		
		testMap.emplace(pair<string, TestClass>("first", TestClass("thisrdItem ++++++++++ ____")));
		testMap.emplace(pair<string, TestClass>("first_", TestClass("thisrdItem ++++++++++ ____")));

		testMap["second"] = "Second_0";
		testMap["second"] = "Second_02";
		testMap["first"] = TestClass("First_0");
		
		pair<string, TestClass> pairS = pair<string, TestClass>("four", "four_0");
		testMap.insert(pairS);

		TestClass::line("funMap show BEFORE");
					for (auto& it : testMap)
					{
						const string key = it.first;
						TestClass& item = it.second;

						std::string showText = '[' + key + "] - " + item._text;
						cout << "\t\t\t map" << showText << endl;
					}

		// Запись значений
		for (auto& it : testMap)
		{
			const string key = it.first;
			TestClass& item = it.second;

			item = '[' + key + "] - " + item._text;
		}

		TestClass::line("funMap show AFTER");
		for (auto& it : testMap)
		{
			const string key = it.first;
			TestClass& item = it.second;

			std::string showText = '[' + key + "] - " + item._text;
			cout << "\t\t\t map" << showText << endl;
		}

		TestClass::lineShort();
		
		for (map<string, TestClass>::iterator it = testMap.begin(); it != testMap.end(); ++it)
		{
			const string key = (*it).first;
			TestClass& item = testMap[key];
			item.action();

			//it->second.action(); // Работает, временно закоментированно
		}
	}

	{
		TestClass::line("without &, not change _text");

		map<string, TestClass> testMap;
		testMap["first"] = TestClass("First_1");
		testMap["second"] = "Second_1";
		testMap["third"] = "Third_1";

		for (auto it : testMap)
		{
			const string key = it.first;
			TestClass& item = it.second;

			item = '[' + key + "] - " + item._text;
		}

		for (map<string, TestClass>::iterator it = testMap.begin(); it != testMap.end(); ++it)
		{
			const string key = (*it).first;
			TestClass item = testMap[key];
			item.action();

			it->second.action();
		}

		{
			TestClass::lineShort("erase");
			map<string, TestClass>::iterator it = testMap.find("second");
			testMap.erase(it);

			for (auto it : testMap)
			{
				it.second.action();
			}
		}
	}
}

void funMultiMap()
{
	TestClass::line("funMultiMap");

	{
		TestClass::lineShort("&");

		multimap<string, TestClass> testMap;
		
		testMap.insert(pair<string, TestClass>("first", TestClass("First_0")));
		
		testMap.emplace(pair<string, TestClass>("first", TestClass("First_0 ____")));

		pair<string, TestClass> pairS = pair<string, TestClass>("second", "Second_0");
		testMap.insert(pairS);
		testMap.insert(pairS);

		pair<string, TestClass> pairS2 = pair<string, TestClass>("second", "Second_0000000");
		testMap.insert(pairS2);

		for (auto& it : testMap)
		{
			const string key = it.first;
			TestClass& item = it.second;

			item = '[' + key + "] - " + item._text;
		}

		for (multimap<string, TestClass>::iterator it = testMap.begin(); it != testMap.end(); ++it)
		{
			const string key = (*it).first;
			TestClass& item = it->second;;
			item.action();

			it->second.action();
		}

		TestClass::lineShort("key");

		{
			multimap<string, TestClass>::iterator it = testMap.find("second");

			if (it != testMap.end())
			{
				it->second.action();
			}
		}

		{
			multimap<string, TestClass>::iterator it = testMap.find("Afirst");

			if (it != testMap.end())
			{
				it->second.action();
			}
			else
			{
				TestClass::message("nullptr");
			}
		}

	}
}

void functionsMap()
{
	funMap();
	funMultiMap();
}

// vetor, map ... http://proginfo.ru/vector/
//	map	http://proginfo.ru/set/