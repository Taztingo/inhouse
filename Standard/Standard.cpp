#include "../String/String.h"
#include "Standard.h"
#include <unistd.h>
#include <assert.h>

namespace inhouse
{
	int print(const String& string)
	{
		return print(string.toString());
	}
	
	int print(const char* string)
	{
		while(*string)
		{
			printChar(*string);
			string++;
		}

		return (sizeof(string) / sizeof(char));
	}

	int println(const String& string)
	{
		return println(string.toString());
	}

	int println(const char* string)
	{
		int length = print(string);
		printChar('\n');
		return length + 1;
	}

	int printChar(const char c)
	{
		return write(1, &c, 1);
	}

	void* memCopy(void* destination, const void* source, int number)
	{
		char* cDestination = (char*) destination;
		char* cSource = (char*) source;

		for(int i = 0; i < number; i++)
		{
			cDestination[i] = cSource[i];
		}

		return destination;
	}

	void* memMove(void* destination, const void* source, int number)
	{
		char* cDestination = (char*) destination;
		char* cSource = (char*) source;

		for(int i = 0; i < number; i++)
		{
			cDestination[i] = cSource[i];
		}

		return destination;
	}

	void errorIf(bool test, const char* string)
	{
		String errorStatement = "An error has occurred: ";
		
		if(test)
		{
			print(errorStatement);
			println(string);
		}

		assert(!test);
	}

	void errorIf(bool test, const String& string)
	{
		errorIf(test, string.toString());
	}
}
