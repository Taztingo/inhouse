#ifndef UNIT_TEST_H_
#define UNIT_TEST_H_

#include "../String/String.h"
#include <ctime>

namespace inhouse
{
	class UnitTest
	{
		private:
			typedef bool(*FunctionPointer)();
			FunctionPointer _functionPointer;
			String _timestamp;
			String _name;
			bool _result;

			void createTimestamp();
		public:
			UnitTest();
			UnitTest(const String& testName, FunctionPointer functionPointer);
			UnitTest(const UnitTest& unitTest);
			void runTest();
			bool getResult();
			String& getTimestamp();
			String& getName();
			UnitTest& operator=(const UnitTest& unitTest);
			bool operator==(UnitTest& unitTest);
	};
}



#endif
