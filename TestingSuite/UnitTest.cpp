#include "UnitTest.h"
#include <ctime>

namespace inhouse
{
	UnitTest::UnitTest()
	{
		_name = "";
		_timestamp = "";
		_result = false;

	}

	UnitTest::UnitTest(const String& testName, FunctionPointer functionPointer)
	{
		_name = testName;
		_functionPointer = functionPointer;
		_timestamp = "";
		_result = false;
	}

	UnitTest::UnitTest(const UnitTest& unitTest)
	{
		_functionPointer = unitTest._functionPointer;
		_timestamp = unitTest._timestamp;
		_name = unitTest._name;
		_result = unitTest._result;
	}
	
	UnitTest::UnitTest(const String& testName)
	{
		_timestamp = "";
		_name = testName;
		_result = false;
	}

	void UnitTest::runTest()
	{
		createTimestamp();
		_result = _functionPointer();
	}

	bool UnitTest::getResult()
	{
		return _result;
	}

	String& UnitTest::getTimestamp()
	{
		return _timestamp;
	}

	String& UnitTest::getName()
	{
		return _name;
	}

	UnitTest& UnitTest::operator=(const UnitTest& unitTest)
	{
		_functionPointer = unitTest._functionPointer;
		_timestamp = unitTest._timestamp;
		_name = unitTest._name;
		_result = unitTest._result;
		return *(this);
	}

	bool UnitTest::operator==(UnitTest& unitTest)
	{
		if(_name != unitTest._name)
		{
			return false;
		}

		return true;
	}

	void UnitTest::createTimestamp()
	{
		std::time_t epochTime = std::time(nullptr);
		_timestamp = std::asctime(std::localtime(&epochTime));
	}
}
