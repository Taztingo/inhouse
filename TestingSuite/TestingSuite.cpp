#include "../String/String.h"
#include "../Common/Type.h"
#include "FeatureSuite.h"
#include "TestingSuite.h"
#include "../DataStructures/DynamicArray/DynamicArray.h"
#include <ctime>

namespace inhouse
{
	void TestingSuite::createTimestamp()
	{
		std::time_t epochTime = std::time(nullptr);
		_timestamp = std::asctime(std::localtime(&epochTime));
	}

	void TestingSuite::printResults()
	{
	}

	TestingSuite::TestingSuite()
	{
		_timestamp = "";
	}

	TestingSuite::TestingSuite(TestingSuite& testingSuite)
	{
		_timestamp = testingSuite._timestamp;
		_suites = testingSuite._suites;
	}

	TestingSuite::~TestingSuite()
	{
	}

	void TestingSuite::runTests()
	{
		createTimestamp();
		for(uint i = 0; i < _suites.getSize(); i++)
		{
			_suites[i].runTests();
		}
	}

	void TestingSuite::runTests(DynamicArray<String>& suiteNames)
	{
		createTimestamp();
		for(uint i = 0; i < suiteNames.getSize(); i++)
		{
			FeatureSuite tempSuite(suiteNames[i]);
			for(uint i2 = 0; i2 < _suites.getSize(); i++)
			{
				if(tempSuite == _suites[i2])
				{
					_suites[i2].runTests();
				}
			} 
		}
	}

	void TestingSuite::addFeatureSuite(String& suiteName)
	{
		FeatureSuite newSuite(suiteName);
		errorIf(_suites.contains(newSuite), "A suite with that name already exists.");
		_suites.add(newSuite);
	}

	void TestingSuite::removeFeatureSuite(String& suiteName)
	{
		FeatureSuite newSuite(suiteName);
		errorIf(!_suites.contains(newSuite), "A suite with that name doesn't exist.");
		_suites.removeElement(newSuite);
	}

	TestingSuite& TestingSuite::operator=(TestingSuite& testingSuite)
	{
		_timestamp = testingSuite._timestamp;
		_suites = testingSuite._suites;
		return *this;
	}

	bool TestingSuite::operator==(TestingSuite& testingSuite)
	{
		return true;
	}
}

