/* Created by Matt Witkowski
 * LinkedList.h
 * A basic LinkedList for my inhouse code. The head and tail are tracked for constant access time.
 */

#ifndef LINKEDLIST_H_
	#define LINKEDLIST_H_

	#include "../../Common/Type.h"
	#include "../../Standard/Standard.h"
	#include "../../String/String.h"
	#include "../Node/Node.h"

	namespace inhouse
	{
		template <class T>
		class LinkedList
		{
			private:
				Node<T>* _head;
				Node<T>* _tail;
				uint _size;

			public:
				LinkedList();
				virtual ~LinkedList();

				bool add(T& element);
				void insert(uint index, T& element);
				void append(T& element);
				void clear();
				bool contains(T& element);
				T& element();
				T& get(uint index);
				T& getFirst();
				T& getLast();
				int indexOf(T& element);
				int lastIndexOf(T& element);
				T& remove();
				T& remove(uint index);
				bool remove(T& element);
				T& removeLast();
				bool removeLastOccurrence(T& element);
				T& set(uint index, T& element);
				uint size();

				LinkedList<T>& operator=(LinkedList<T>& newList);
		};

		template <typename T>
		LinkedList<T>::LinkedList()
		{
			_head = nullptr;
			_tail = nullptr;
		}

		template <typename T>
		LinkedList<T>::~LinkedList()
		{
			clear();
			_head = nullptr;
			_tail = nullptr;
		}
		
		template <typename T>
		bool LinkedList<T>::add(T& element)
		{
			return true;
		}

		template <typename T>
		void LinkedList<T>::insert(uint index, T& element)
		{
		}

		template <typename T>
		void LinkedList<T>::append(T& element)
		{
		}

		template <typename T>
		void LinkedList<T>::clear()
		{
		}

		template <typename T>
		bool LinkedList<T>::contains(T& element)
		{
			return false;
		}

		template <typename T>
		T& LinkedList<T>::element()
		{
			return *_head;
		}

		template <typename T>
		T& LinkedList<T>::get(uint index)
		{
			return *_head;
		}

		template <typename T>
		T& LinkedList<T>::getFirst()
		{
			return *_head;
		}

		template <typename T>
		T& LinkedList<T>::getLast()
		{
			return _tail;
		}

		template <typename T>
		int LinkedList<T>::indexOf(T& element)
		{
			return -1;
		}
		
		template <typename T>
		int LinkedList<T>::lastIndexOf(T& element)
		{
			return -1;
		}
		
		template <typename T>
		T& LinkedList<T>::remove()
		{
			return *_head;
		}
		
		template <typename T>
		T& LinkedList<T>::remove(uint index)
		{
			return *_head;
		}
		
		template <typename T>
		bool LinkedList<T>::remove(T& element)
		{
			return false;
		}
		
		template <typename T>
		T& LinkedList<T>::removeLast()
		{
			return *_head;
		}
		
		template <typename T>
		bool LinkedList<T>::removeLastOccurrence(T& element)
		{
			return false;
		}
		
		template <typename T>
		T& LinkedList<T>::set(uint index, T& element)
		{
			return *_head;
		}
		
		template <typename T>
		uint LinkedList<T>::size()
		{
			return _size;
		}

		template <typename T>
		LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& newList)
		{
			return *this;
		}
	}

#endif
