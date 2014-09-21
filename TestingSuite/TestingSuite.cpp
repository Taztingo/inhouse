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
	}

	void TestingSuite::printResults()
	{
	}

	TestingSuite::TestingSuite()
	{
	}

	TestingSuite::TestingSuite(const TestingSuite& testingSuite)
	{
	}

	TestingSuite::~TestingSuite()
	{
	}

	void TestingSuite::runTests()
	{
	}

	void TestingSuite::runTests(const DynamicArray<String>& suiteNames)
	{
	}

	void TestingSuite::addFeatureSuite(const String& suiteName)
	{
	}

	void TestingSuite::removeFeatureSuite(const String& suiteName)
	{
	}

	TestingSuite& TestingSuite::operator=(const TestingSuite& testingSuite)
	{
		return *this;
	}

	bool TestingSuite::operator==(TestingSuite& testingSuite)
	{
		return true;
	}
}

