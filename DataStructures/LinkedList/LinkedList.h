/* Created by Matt Witkowski
 * LinkedList.h
 * A basic LinkedList for my inhouse code. The head and tail are tracked for constant access time.
 */

#ifndef LINKEDLIST_H_
	#define LINKEDLIST_H_

	#include "../../Common/Type.h"
	#include "../../Standard/Standard.h"
	#include "../../String/String.h"
	#include "../Node.h"

	namespace inhouse
	{
		template <class T>
		class LinkedList
		{
			private:
				Node<T> _head;
				Node<T> _tail;
				uint _size;

			public:
				bool add(T& element);
				void insert(uint index, T& element);
				void append(T& element);
				void clear();
				bool contains(T& element);
				T& element();
				T& get(uint index);
				T& getFirst();
				T& getLast();
				uint indexOf(T& element);
				uint lastIndexOf(T& element);
				T& remove();
				T& remove(uint index);
				bool remove(T& element);
				T& removeLast();
				bool removeLastOccurrence(T& element);
				T& set(uint index, T& element);
				uint size()

				operator=(LinkedList<T>& newList);
		};
	}

#endif
