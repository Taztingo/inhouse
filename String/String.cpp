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

	String::String(char[] string)
	{
	}

	~String()
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

	String& String::substring(int begin, int end)
	{
		return *_string;
	}

	char[] String::toCharArray()
	{
		char blah[] = "";
		return blah;
	}

	String& String::toString()
	{
		return *_string;
	}

	String& String::toUpperCase()
	{
		return *_string;
	}

	String& String::trim()
	{
		return *_string;
	}

	bool String::operator==(String& string)
	{
		return false;
	}

	String& String::operator=(String& string)
	{
		return string;
	}

	String& String::operator+(String& string)
	{
		return *_string;
	}

	String& String::operator+(int integer)
	{
		return *_string;
	}

	String& String::operator+(bool boolean)
	{
		return *_string;
	}
 }
