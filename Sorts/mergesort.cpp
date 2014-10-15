#include "Sorts.h"
#include "ISort.h"

namespace inhouse
{
	ISort* mergesort(ISort* array, uint start, uint end)
	{
		return array;
	}

	int* mergesort(int* array, uint start, uint end)
	{
		//Base call of 1 item left
		if(start >= end)
		{
			int* newArray = new int[1];
			newArray[0] = array[start];
			return newArray;
		}

		uint middle = (start + end) / 2;
		int* left = mergesort(array, start, middle);
		int* right = mergesort(array, middle + 1, end);

		//Create new array
		int difference = end - start + 1;
		int* newArray = new int[difference]; 

		//Copy the contents
		uint leftPointer = 0;
		uint leftPointerOffset = start;
		uint rightPointer = 0;
		uint rightPointerOffset = middle + 1;
		uint newArrayIndex = 0;

		while(leftPointer + leftPointerOffset <= middle)
		{
			//Copy the remainder of left array
			if(rightPointer + rightPointerOffset > end)
			{
				newArray[newArrayIndex] = left[leftPointer];
				newArrayIndex++;
				leftPointer++;
			}
			//Left side is smaller
			else if(left[leftPointer] <= right[rightPointer])
			{
				newArray[newArrayIndex] = left[leftPointer];
				newArrayIndex++;
				leftPointer++;
			}
			//Right side is smaller
			else
			{
				newArray[newArrayIndex] = right[rightPointer];
				newArrayIndex++;
				rightPointer++;
			}
		}

		//Copy the remainder of right array
		while(rightPointer + rightPointerOffset <= end)
		{
			newArray[newArrayIndex] = right[rightPointer];
			newArrayIndex++;
			rightPointer++;
		}

		//Clean up memory created
		delete[] left;
		delete[] right;

		return newArray;
	}
}
