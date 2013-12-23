/* Created by Matt Witkowski
 * String.cpp
 * My own version of the string class.
 */

#include "String.h"
#include "../Standard/Standard.h"

namespace inhouse
{
	String::String()
	{
		_length = 0;

	}

	String::String(char string[])
	{
		_length = 0;

		while(string[_length])
		{
			_length++;
		}

		_string = new char[_length + 1];
		memMove(_string, string, sizeof(char) * (_length+1));
	}

	String::~String()
	{
		if(_string != nullptr)
		{
			_length = 0;
			delete _string;
		}
	}

	char& String::charAt(uint index)
	{
		char errorMessage[] = "Index out of bounds";
		error(index <= _length, errorMessage);
		return _string[index];
	}

	int String::compareTo(String& string)
	{
		int i = 0;

		while(_string[i] && string[i])
		{
			if(_string[i] < string[i])
			{
				return -1;
			}
			else if(string[i] < _string[i])
			{
				return 1;
			}

			i++;
		}

		if(!_string[i] && string[i])
		{
			return -1;
		}

		if(!string[i] && _string[i])
		{
			return 1;
		}

		return 0;
	}

	int String::compareToIgnoreCase(String& string)
	{
		return 0;
	}

	bool String::contains(String& string)
	{
		if(indexOf(string) >= 0)
		{
			return true;
		}

		return false;
	}

	int String::indexOf(char character)
	{
		for(uint i = 0; i < _length; i++)
		{
			if(_string[i] == character)
			{
				return i;
			}
		}

		return -1;
	}

	int String::indexOf(String& string)
	{
		int length = string.length();

		for(uint i = 0; (i + length - 1) < _length && _string[i]; i++)
		{
			if(_string[i] == string[0])
			{
				bool totalMatch = true;
				for(uint j = 1; j < string.length(); j++)
				{
					if(_string[i + j] != string[j])
					{
						totalMatch = false;
					}
				}

				if(totalMatch)
				{
					return i;
				}
			}
		}

		return -1;
	}

	bool String::isEmpty()
	{
		return _length > 0;
	}

	int String::lastIndexOf(char character)
	{
		for(int i = _length - 1; i >= 0; i--)
		{
			if(_string[i] == character)
			{
				return i;
			}
		}

		return -1;
	}

	int String::lastIndexOf(String& string)
	{
		int length = string.length();
		int lastIndex = -1;

		for(uint i = 0; (i + length - 1) < _length && _string[i]; i++)
		{
			if(_string[i] == string[0])
			{
				bool totalMatch = true;
				for(uint j = 1; j < string.length(); j++)
				{
					if(_string[i + j] != string[j])
					{
						totalMatch = false;
					}
				}

				if(totalMatch)
				{
					lastIndex = i;
				}
			}
		}

		return lastIndex;
	}

	uint String::length()
	{
		return _length;
	}

	char* String::substring(uint begin, uint end)
	{
		return _string;
	}

	char* String::toLowerCase()
	{
		return _string;
	}

	char* String::toString()
	{
		return _string;
	}

	char* String::toUpperCase()
	{
		return _string;
	}

	char* String::trim()
	{
		return _string;
	}

	bool String::operator==(String& string)
	{
		return false;
	}

	String& String::operator=(String& string)
	{
		return string;
	}

	char* String::operator+(String& string)
	{
		return _string;
	}

	char* String::operator+(int integer)
	{
		return _string;
	}

	char* String::operator+(bool boolean)
	{
		return _string;
	}

	char& String::operator[](uint index)
	{
		return charAt(index);
	}
}
