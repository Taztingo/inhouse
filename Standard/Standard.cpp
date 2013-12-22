#include "../String/String.h"
#include "Standard.h"
#include <unistd.h>

namespace inhouse
{
	int print(String& string)
	{
		print(string.toString());
		return 0;
	}
	
	int print(char* string)
	{
		while(*string)
		{
			printChar(*string);
			string++;
		}

		return 0;
	}

	int printChar(char c)
	{
		return write(1, &c, 1);
	}
}
