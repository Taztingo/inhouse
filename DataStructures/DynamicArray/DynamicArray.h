/* Created by Matt Witkowski
 * DynamicArray.h
 * An array that automatically expands when the user adds more elements than there is capacity.
 * The array will double in size and allocate new memory when this happens.
 */

#ifndef DYNAMICARRAY_H_
	#define DYNAMICARRAY_H_

	#include "../../Common/Type.h"
	#include "../../Standard/Standard.h"
	#include "../../String/String.h"

	namespace inhouse
	{
		template<class T>
		class DynamicArray
		{
			private:
				T* _array;
				uint _size;
				uint _capacity;

				void increaseCapacity(uint newCapacity);
				void shiftElementsLeft(uint index);
				void shiftElementsRight(uint index);

			public:
				DynamicArray();
				DynamicArray(uint capacity);
				virtual ~DynamicArray();

				uint getSize();
				uint getCapacity();
				uint getMemoryUsage();
				void set(uint index, T& value);
				bool add(T& element);
				void insert(uint index, T& element);
				T& remove(uint index);
				bool removeElement(T& element);
				void clear();
				String toString();
				int indexOf(T& element);
				void ensureCapacity(uint minimum);
				bool contains(T& element);
				void trimToSize();
				T& get(uint index);
				T& operator[](uint index);
				DynamicArray<T>& operator=(DynamicArray<T>& array);
		};

		template<class T>
		DynamicArray<T>::DynamicArray()
		{
			_capacity = 10;
			_array = new T[_capacity];
			_size = 0;
		}

		template<class T>
		DynamicArray<T>::DynamicArray(uint capacity)
		{
			_capacity = capacity;
			_size = 0;
			errorIf(capacity <= 0, "Cannot have zero capacity");
			_array = new T[_capacity];
		}

		template<class T>
		DynamicArray<T>::~DynamicArray()
		{
			errorIf(_array == nullptr, "Array is null.");
			delete[] _array;
			_array = nullptr;
		}

		template<class T>
		uint DynamicArray<T>::getSize()
		{
			errorIf(_array == nullptr, "Array is null.");
			return _size;
		}

		template<class T>
		uint DynamicArray<T>::getCapacity()
		{
			errorIf(_array == nullptr, "Array is null.");
			return _capacity;
		}

		template<class T>
		uint DynamicArray<T>::getMemoryUsage()
		{
			errorIf(_array == nullptr, "Array is null.");
			return sizeof(this) + (sizeof(T) * _capacity);
		}

		template<class T>
		void DynamicArray<T>::set(uint index, T& value)
		{
			errorIf(_array == nullptr, "Array is null.");
			errorIf(_array >= _size, "Index out of bounds.");
			_array[index] = value;
		}

		template<class T>
		bool DynamicArray<T>::add(T& element)
		{
			errorIf(_array == nullptr, "Cannot add to null array.");

			if (_size == _capacity)
			{
				increaseCapacity(_capacity * 2);
			}

			_array[_size] = element;
			_size++;

			return true;
		}

		template<class T>
		void DynamicArray<T>::insert(uint index, T& element)
		{
			errorIf(_array == nullptr, "Cannot add to null array.");

			if (_size == _capacity)
			{
				increaseCapacity(_capacity * 2);
			}

			if (index == _size)
			{
				add(element);
			}
			else if (index < _size)
			{
				shiftElementsRight(index);
				_array[index] = element;
				_size++;
			}
			else
			{
				errorIf(true, "Index out of bounds.");
			}
		}

		template<class T>
		T& DynamicArray<T>::remove(uint index)
		{
			errorIf(_array == nullptr, "Cannot remove from null array.");
			errorIf(index >= _size, "Index out of bounds.");

			T& removedElement = _array[index];
			shiftElementsLeft(index);
			_size--;

			return removedElement;
		}

		template<class T>
		bool DynamicArray<T>::removeElement(T& element)
		{
			errorIf(_array == nullptr, "Cannot remove from null array.");

			for (uint i = 0; i < _size; i++)
			{
				if (_array[i] == element)
				{
					remove(i);

					return true;
				}
			}

			return false;
		}

		template<class T>
		void DynamicArray<T>::clear()
		{
			errorIf(_array == nullptr, "Cannot clear null array.");

			while (_size > 0)
			{
				remove(0);
			}
		}

		template<class T>
		int DynamicArray<T>::indexOf(T& element)
		{
			errorIf(_array == nullptr, "Array is null.");

			for (uint i = 0; i < _size; i++)
			{
				if (element == _array[i])
				{
					return i;
				}
			}

			return -1;
		}

		template<class T>
		void DynamicArray<T>::ensureCapacity(uint minimum)
		{
			errorIf(_array == nullptr, "Array is null.");
		
			if (_capacity < minimum)
			{
				increaseCapacity(minimum);
			}
		}

		template<class T>
		bool DynamicArray<T>::contains(T& element)
		{
			errorIf(_array == nullptr, "Array is null.");

			for (uint i = 0; i < _size; i++)
			{
				if (element == _array[i])
				{
					return true;
				}
			}

			return false;
		}

		template<class T>
		void DynamicArray<T>::trimToSize()
		{
			errorIf(_array == nullptr, "Array is null.");
		
			if (_size == 0)
			{
				return;
			}

			if (_size == _capacity)
			{
				return;
			}

			T* newArray = new T[_size];
			_capacity = _size;

			for (uint i = 0; i < _size; i++)
			{
				newArray[i] = _array[i];
			}

			delete[] _array;
			_array = newArray;
		}

		template<class T>
		T& DynamicArray<T>::get(uint index)
		{
			errorIf(_array == nullptr, "Array is null.");
			errorIf(index >= _size, "Index out of bounds.");
			return _array[index];
		}

		template<class T>
		T& DynamicArray<T>::operator[](uint index)
		{
			errorIf(_array == nullptr, "Array is null.");
			errorIf(index >= _size, "Index out of bounds.");
			return _array[index];
		}
		
		template<class T>
		DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>& array)
		{
			if(&array != this)
			{
				clear();
				increaseCapacity(array.getCapacity());
				
				for(uint i = 0; i < array.getSize(); i++)
				{
					add(array.get(i));
				}
			}
	
			return *this;
		}

		template<class T>
		void DynamicArray<T>::increaseCapacity(uint newCapacity)
		{
			errorIf(_array == nullptr, "Array is null.");
		
			T* tempArray = new T[newCapacity];

			for (uint i = 0; i < _size; i++)
			{
				tempArray[i] = _array[i];
			}

			_capacity = newCapacity;
			delete[] _array;
			_array = tempArray;
		}

		template<class T>
		void DynamicArray<T>::shiftElementsLeft(uint index)
		{
			errorIf(_array == nullptr, "Array is null.");
		
			for (uint i = index; i < _size - 1; i++)
			{
				_array[i] = _array[i + 1];
			}
		}

		template<class T>
		void DynamicArray<T>::shiftElementsRight(uint index)
		{
			errorIf(_array == nullptr, "Array is null.");
		
			for (uint i = _size; i > index; i--)
			{
				_array[i] = _array[i - 1];
			}
		}

		template<class T>
		String DynamicArray<T>::toString()
		{
			errorIf(_array == nullptr, "Array is null.");
			String string = "[";
		
			for (uint i = 0; i < _size; i++)
			{
				string += _array[i];
				if(i != _size - 1)
				{
					string += ", ";
				}
			}

			string += "]";

			return string;
		}
	}
#endif
