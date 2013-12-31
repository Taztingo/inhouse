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

	String::String(const char* string)
	{
		_length = 0;

		while(string[_length])
		{
			_length++;
		}

		_string = new char[_length + 1];
		memMove(_string, string, sizeof(char) * (_length+1));
	}
	
	String::String(const String& string)
	{
		_length = string.length();

		_string = new char[string.length() + 1];
		memMove(_string, string.toString(), sizeof(char) * (_length+1));
	}

	String::~String()
	{
		if(_string != nullptr)
		{
			_length = 0;
			delete[] _string;
		}
	}

	char& String::charAt(uint index)
	{
		char errorMessage[] = "Index out of bounds";
		errorIf(index > _length, errorMessage);
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
		String tempThis = *this;
		String tempString = string;

		tempString.toLowerCase();
		tempThis.toLowerCase();

		return tempThis.compareTo(tempString);
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
	
	uint String::length() const
	{
		return _length;
	}

	String String::substring(uint begin, uint end)
	{
		char beginErrorMessage[] = "Begin is out of bounds.";
		char endErrorMessage[] = "End is out of bounds.";
		errorIf(begin > _length + 1, beginErrorMessage);
		errorIf(end > _length + 1, endErrorMessage);

		uint length = end - begin;
		char* newArray = new char[length + 1];
		for(uint i = begin; i < end; i++)
		{
			newArray[i - begin] = _string[i];
		}
		newArray[length] = '\0';

		String string(newArray);
		delete[] newArray;
		return string;
	}

	String& String::toLowerCase()
	{
		char distance = 'a' - 'A';

		for(uint i = 0; i < _length; i++)
		{
			if(_string[i] >= 'A' && _string[i] <= 'Z')
			{
				_string[i] = _string[i] + distance;
			}
		}

		return *this;
	}

	char* String::toString() const
	{
		return _string;
	}

	char* String::toString()
	{
		return _string;
	}

	String& String::toUpperCase()
	{
		char distance = 'a' - 'A';

		for(uint i = 0; i < _length; i++)
		{
			if(_string[i] >= 'a' && _string[i] <= 'z')
			{
				_string[i] = _string[i] - distance;
			}
		}

		return *this;
	}

	String String::trim()
	{
		uint start = 0;
		uint end = _length - 1;

		//Get rid of all beginning spaces
		while(_string[start] && _string[start] == ' ')
		{
			start++;
		}
		
		//Get rid of all ending spaces
		while(end > 0 && _string[end] == ' ')
		{
			end--;
		}

		//Nothing to be trimmed
		if(start == 0 && end == _length)
		{
			return *this;
		}

		if(end < start)
		{
			char empty[] = "";
			return String(empty);
		}

		return substring(start, end + 1);
	}

	bool String::operator==(String& string)
	{
		return !compareTo(string);
	}
	
	bool String::operator!=(String& string)
	{
		return compareTo(string);
	}

	String String::operator+(String& string)
	{
		char* charArray = new char[_length + string.length() + 1];
			
		memMove(charArray, _string, _length);
		memMove(&charArray[_length], string.toString(), string.length());
		charArray[_length + string.length() + 1] = '\0';
		String newString(charArray);

		delete[] charArray;
		return newString;
	}
	
	String String::operator+(const char* string)
	{
		String tempString(string);
		char* charArray = new char[_length + tempString.length() + 1];
			
		memMove(charArray, _string, _length);
		memMove(&charArray[_length], tempString.toString(), tempString.length());
		charArray[_length + tempString.length() + 1] = '\0';
		String newString(charArray);

		delete[] charArray;
		return newString;
	}

	String String::operator+(int integer)
	{
		char* charArray = new char[_length + 2];
		
		memMove(charArray, _string, _length);
		charArray[_length] = integer + '0';	
		charArray[_length + 1] = '\0';
		String newString(charArray);

		delete[] charArray;
		return newString;
	}

	String String::operator+(bool boolean)
	{
		char* charArray = new char[_length + 2];
		
		memMove(charArray, _string, _length);
		charArray[_length] = boolean + '0';	
		charArray[_length + 1] = '\0';
		String newString(charArray);

		delete[] charArray;
		return newString;
	}

	char& String::operator[](uint index)
	{
		return charAt(index);
	}

	String& String::operator=(const String& string)
	{
		if(this != &string)
		{

			_length = string.length();
			if(_string != nullptr)
			{
				delete[] _string;
			}
		
			_string = new char[_length + 1];
			memMove(_string, string.toString(), sizeof(char) * (_length+1));
		}

		return *this;
	}
}
