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
	}

	uint FeatureSuite::getPassed()
	{
		return _passedTests;
	}

	uint FeatureSuite::getFailed()
	{
		return 0;
	}

	String& FeatureSuite::getTimestamp()
	{
		return _timestamp;
	}

	String& FeatureSuite::getName()
	{
		return _name;
	}

	void FeatureSuite::addTest(String& testName, FunctionPointer)
	{
	}

	void FeatureSuite::removeTest(String& testName)
	{
	}

	FeatureSuite& FeatureSuite::operator=(const FeatureSuite& featureSuite)
	{
		return *this;
	}

	bool FeatureSuite::operator==(FeatureSuite& featureSuite)
	{
		return true;
	}
	
	void FeatureSuite::createTimestamp()
	{
	}
}
