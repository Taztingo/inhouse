#include "../String/String.h"
#include "Standard.h"
#include "../Common/Color.h"
#include <unistd.h>
#include <assert.h>

using namespace inhouse;
using namespace Color;

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
	
	int print(const int& integer)
	{
		return print(itoa(integer));
	}

	int println(const String& string)
	{
		return println(string.toString());
	}
	
	int println(const int& integer)
	{
		return println(itoa(integer));
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
		String color = "red";
		String errorMessage = string;
		
		if(test)
		{
			print(colorText(errorStatement, color));
			println(colorText(errorMessage, color));
		}

		assert(!test);
	}

	void errorIf(bool test, const String& string)
	{
		errorIf(test, string.toString());
	}

	String itoa(int integer)
	{
		uint length = 0;
		int tempInteger = integer;
		char* charArray;
		uint counter = 1;

		if(tempInteger < 0)
		{
			tempInteger *= -1;
		}

		while(tempInteger > 0)
		{
			tempInteger /= 10;
			length++;
		}
		if(integer == 0)
		{
			length = 1;
		}
		if(integer < 0)
		{
			integer *= -1;
			length++;
			charArray = new char[length + 1];
			charArray[0] = '-';
		}
		else
		{
			charArray = new char[length + 1];
		}
		
		charArray[length] = '\0';

		if(integer == 0)
		{
			charArray[0] = '0';
		}
		while(integer > 0)
		{
			int remainder = integer % 10;
			integer /= 10;
			charArray[length - counter] = remainder + '0';
			counter++;	
		}

		String string(charArray);
		delete[] charArray;

		return string;
	}
}
