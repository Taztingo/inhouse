#include "../String/String.h"
#include "Standard.h"
#include <unistd.h>

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
}
