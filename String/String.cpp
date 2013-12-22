/* Created by Matt Witkowski
 * String.cpp
 * My own version of the string class.
 */

#include "String.h"

 namespace inhouse
 {
 	String::String()
	{
	}

	String::String(char string[])
	{
	}

	String::~String()
	{
	}

	char String::charAt(uint index)
	{
		return 0;
	}

	int String::compareTo(String& string)
	{
		return 0;
	}

	int String::compareToIgnoreCase(String& string)
	{
		return 0;
	}

	bool String::contains(String& string)
	{
		return false;
	}

	int String::indexOf(char character)
	{
		return -1;
	}

	int String::indexOf(String& string)
	{
		return -1;
	}

	bool String::isEmpty()
	{
		return _length > 0;
	}

	int String::lastIndexOf(char character)
	{
		return -1;
	}

	int String::lastIndexOf(String& string)
	{
		return -1;
	}

	int String::length()
	{
		return _length;
	}

	char* String::substring(uint begin, uint end)
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
 }
