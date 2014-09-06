#include "../String/String.h"
#include "../Common/Type.h"
#include "UnitTest.h"
#include "FeatureSuite.h"
#include "../DataStructures/DynamicArray/DynamicArray.h"
#include <ctime>

namespace inhouse
{
	FeatureSuite::FeatureSuite()
	{
		_name = "";
		_timestamp = "";
		_passedTests = 0;
	}

	FeatureSuite::FeatureSuite(const String& featureName)
	{
		_name = featureName;
		_timestamp = "";
		_passedTests = 0;
	}

	FeatureSuite::FeatureSuite(FeatureSuite& feature)
	{
		_tests = feature._tests;
		_timestamp = feature._timestamp;
		_name = feature._name;
		_passedTests = feature._passedTests;
	}

	void FeatureSuite::runTests()
	{
		createTimestamp();
	}

	uint FeatureSuite::getPassed()
	{
		return _passedTests;
	}

	uint FeatureSuite::getFailed()
	{
		return _tests.getSize() - _passedTests;
	}

	String& FeatureSuite::getTimestamp()
	{
		return _timestamp;
	}

	String& FeatureSuite::getName()
	{
		return _name;
	}

	void FeatureSuite::addTest(String& testName, FunctionPointer functionPointer)
	{
		UnitTest unitTest(testName, functionPointer);
		errorIf(_tests.contains(unitTest), "A test with that name already exists!");
		_tests.add(unitTest);
	}

	void FeatureSuite::removeTest(String& testName)
	{
		UnitTest unitTest(testName);
		errorIf(!_tests.contains(unitTest), "A test with that name doesn't exist!");
		_tests.removeElement(unitTest);
	}

	FeatureSuite& FeatureSuite::operator=(FeatureSuite& featureSuite)
	{
		_tests = featureSuite._tests;
		_timestamp = featureSuite._timestamp;
		_name = featureSuite._name;
		_passedTests = featureSuite._passedTests;
		return *this;
	}

	bool FeatureSuite::operator==(FeatureSuite& featureSuite)
	{
		if(_name != featureSuite._name)
		{
			return false;
		}

		return true;
	}
	
	void FeatureSuite::createTimestamp()
	{
		std::time_t epochTime = std::time(nullptr);
		_timestamp = std::asctime(std::localtime(&epochTime));
	}
}
