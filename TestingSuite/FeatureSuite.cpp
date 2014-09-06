#include "../String/String.h"
#include "../Common/Common.h"
#include "UnitTest.h"
#include "../DynamicArray/DynamicArray.h"
#include <ctime>

namespace inhouse
{
	FeatureSuite::FeatureSuite()
	{
	}

	FeatureSuite::FeatureSuite(const String& featureName)
	{
	}

	FeatureSuite::FeatureSuite(const FeatureSuite& feature)
	{
	}

	void FeatureSuite::runTests()
	{
	}

	uint FeatureSuite::getPassed()
	{
		return 0;
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

	void FeatureSuite::addTest(String& testName, UnitTest::FunctionPointer)
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

#endif
