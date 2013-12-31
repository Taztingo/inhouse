#ifndef STANDARD_H_
	#define STANDARD_H_

	namespace inhouse
	{
		class String;
		int print(const String& string);
		int print(const char* string);
		int println(const String& string);
		int println(const char* string);
		int printChar(const char c);

		void* memCopy(void* destination, const void* source, int number);
		void* memMove(void* destination, const void* source, int number);

		void errorIf(bool test, const char* string);
		void errorIf(bool test, const String& string);
	}

#endif
