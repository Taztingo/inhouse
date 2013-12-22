/* Created by Matt Witkowski
 * String.h
 * My own version of the string class.
 */

#ifndef STRING_H_
	#define STRING_H_

	class String
	{
		private:
			unsigned int _length;
			char* _string;

		public:
			String();
			String(char[] string);
			
			char charAt(int index);
			int compareTo(String& string);
			int compareToIgnoreCase(String& string);
			bool contains(String& string);
			int indexOf(char character);
			int indexOf(String& string);
			bool isEmpty();
			int lastIndexOf(char character);
			int lastIndexOf(String& string);
			int length();
			String& substring(int begin, int end);
			char[] toCharArray();
			String& toLowerCase();
			String& toString();
			String& toUpperCase();
			String& trim();

			bool operator==(String& string);
			String& operator=(String& string);
			String& operator+(String& string);
			String& operator+(String& integer);
			String& operator+(bool boolean);
	};

#endif
