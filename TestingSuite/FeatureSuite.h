#ifndef FEATURE_SUITE_H_
#define FEATURE_SUITE_H_

#include "../String/String.h"
#include "../Common/Type.h"
#include "UnitTest.h"
#include "../DataStructures/DynamicArray/DynamicArray.h"
#include <ctime>

namespace inhouse
{
	class FeatureSuite
	{
		private:
			typedef bool(*FunctionPointer)();
			DynamicArray<UnitTest> _tests;
			String _timestamp;
			String _name;
			uint _passedTests;

			void createTimestamp();
		public:
			FeatureSuite();
			FeatureSuite(const String& featureName);
			FeatureSuite(FeatureSuite& feature);
			void runTests();
			uint getPassed();
			uint getFailed();
			String& getTimestamp();
			String& getName();
			void addTest(String& testName, FunctionPointer);
			void removeTest(String& testName);
			FeatureSuite& operator=(FeatureSuite& featureSuite);
			bool operator==(FeatureSuite& featureSuite);
	};
}

#endif
