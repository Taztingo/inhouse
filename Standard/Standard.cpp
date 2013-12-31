#include "../String/String.h"
#include "Standard.h"
#include <unistd.h>
#include <assert.h>

namespace inhouse
{
	int print(String& string)
	{
		return print(string.toString());
	}
	
	int print(char* string)
	{
		while(*string)
		{
			printChar(*string);
			string++;
		}

		return (sizeof(string) / sizeof(char));
	}

	int println(String& string)
	{
		return println(string.toString());
	}

	int println(char* string)
	{
		int length = print(string);
		printChar('\n');
		return length + 1;
	}

	int printChar(char c)
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

	void error(bool passTest, char* string)
	{
		char errorStatement[] = "An error has occurred: ";
		
		if(!passTest)
		{
			print(errorStatement);
			println(string);
		}

		assert(passTest);
	}

	void error(bool passTest, String& string)
	{
		error(passTest, string.toString());
	}
}
