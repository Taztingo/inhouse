#ifndef FEATURE_SUITE_H_
#define FEATURE_SUITE_H_

#include "../String/String.h"
#include "../Common/Common.h"
#include "UnitTest.h"
#include "../DynamicArray/DynamicArray.h"
#include <ctime>

namespace inhouse
{
	class FeatureSuite
	{
		private:
			DynamicArray<UnitTest> _tests;
			String _timestamp;
			String _name;
			uint _passedTests;

			void createTimestamp();
		public:
			FeatureSuite();
			FeatureSuite(const String& featureName);
			FeatureSuite(const FeatureSuite& feature);
			void runTests();
			uint getPassed();
			uint getFailed();
			String& getTimestamp();
			String& getName();
			void addTest(String& testName, UnitTest::FunctionPointer);
			void removeTest(String& testName);
			FeatureSuite& operator=(const FeatureSuite& featureSuite);
			bool operator==(FeatureSuite& featureSuite);
	};
}

#endif
