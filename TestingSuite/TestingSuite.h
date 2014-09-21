#ifndef TESTING_SUITE_H_
#define TESTING_SUITE_H_

#include "../String/String.h"
#include "../Common/Type.h"
#include "UnitTest.h"
#include "FeatureSuite.h"
#include "../DataStructures/DynamicArray/DynamicArray.h"
#include <ctime>

namespace inhouse
{
	class TestingSuite
	{
		private:
			DynamicArray<FeatureSuite> _suites;
			String _timestamp;

			void createTimestamp();
			void printResults();
		public:
			TestingSuite();
			TestingSuite(const TestingSuite& testingSuite);
			~TestingSuite();
			void runTests();
			void runTests(const DynamicArray<String>& suiteNames);
			void addFeatureSuite(const String& suiteName);
			void removeFeatureSuite(const String& suiteName);
			TestingSuite& operator=(const TestingSuite& testingSuite);
			bool operator==(TestingSuite& testingSuite);
	};
}

#endif