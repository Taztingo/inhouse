#ifndef SORTS_H_
	#define SORTS_H_
	
	#include "ISort.h"
	#include "../Common/Type.h"

	namespace inhouse
	{
		ISort* quicksort(ISort* array, uint start, uint end);
		ISort* mergesort(ISort* array, uint start, uint end);

		//Temporary sorts for practice
		int* quicksort(int* array, uint start, uint end);
		int* mergesort(int* array, uint start, uint end);
	}

#endif
