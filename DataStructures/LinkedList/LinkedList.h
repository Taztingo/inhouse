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

				Node<T>* getNodeAt(uint index);

			public:
				LinkedList();
				virtual ~LinkedList();

				bool add(const T& element);
				bool insert(uint index, const T& element);
				bool append(const T& element);
				void clear();
				bool contains(const T& element);
				T& get(uint index);
				T& getHead();
				T& getTail();
				int indexOf(const T& element);
				int lastIndexOf(const T& element);
				T& remove();
				T& remove(uint index);
				bool remove(T& element);
				T& removeLast();
				bool removeLastOccurrence(T& element);
				T& set(uint index, T& element);
				uint size();
				String toString();

				LinkedList<T>& operator=(LinkedList<T>& newList);
		};

		template <typename T>
		LinkedList<T>::LinkedList()
		{
			_size = 0;
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
		Node<T>* LinkedList<T>::getNodeAt(uint index)
		{
			errorIf(index > _size, "Node index out of bounds.");
			Node<T>* node = _head;

			for(uint i = 0; i < index; i++)
			{
				node = node->getNextNode();
			}

			return node;
		}
		
		template <typename T>
		bool LinkedList<T>::add(const T& element)
		{
			Node<T>* newNode = new Node<T>(element);

			if(newNode)
			{
				if(_head == nullptr)
				{
					_head = newNode;
				}
				else
				{
					newNode->setNextNode(*_head);
					_head = newNode;
					_head->getNextNode()->setPreviousNode(*_head);
				}
			
				_tail = getNodeAt(_size);
				_size++;
				return true;
			}

			return false;
		}

		template <typename T>
		bool LinkedList<T>::insert(uint index, const T& element)
		{
			errorIf(index > _size, "Index out of bounds.");
			Node<T>* newNode;

			if(index == 0)
			{
				return add(element);
			}
			else if(index == _size)
			{
				return append(element);
			}
			else
			{
				newNode = new Node<T>(element);
				if(newNode)
				{
					Node<T>* nodeAtIndex = getNodeAt(index);
					Node<T>* previousNode = nodeAtIndex->getPreviousNode();

					if(previousNode)
					{
						previousNode->setNextNode(*newNode);
					}

					newNode->setNextNode(*nodeAtIndex);
					newNode->setPreviousNode(*previousNode);

					nodeAtIndex->setPreviousNode(*newNode);
					
					_size++;
					return true;
				}
			}

			return false;
		}

		template <typename T>
		bool LinkedList<T>::append(const T& element)
		{
			if(_size == 0)
			{
				return add(element);
			}
			else
			{
				Node<T>* nodeAtIndex = getNodeAt(_size - 1);
				Node<T>* newNode = new Node<T>(element);
				
				nodeAtIndex->setNextNode(*newNode);
				newNode->setPreviousNode(*nodeAtIndex);
				_tail = newNode;

				_size++;
				return true;
			}

			return false;
		}

		template <typename T>
		void LinkedList<T>::clear()
		{
		}

		template <typename T>
		bool LinkedList<T>::contains(const T& element)
		{
			Node<T>* node = _head;

			for(uint i = 0; i < _size; i++)
			{
				if(node->getElement() == element)
				{
					return true;
				}

				node = node->getNextNode();
			}

			return false;
		}

		template <typename T>
		T& LinkedList<T>::get(uint index)
		{
			return getNodeAt(index)->getElement();
		}

		template <typename T>
		T& LinkedList<T>::getHead()
		{
			return _head->getElement();
		}

		template <typename T>
		T& LinkedList<T>::getTail()
		{
			return _tail->getElement();
		}

		template <typename T>
		int LinkedList<T>::indexOf(const T& element)
		{
			Node<T>* node = _head;

			for(uint i = 0; i < _size; i++)
			{
				if(node->getElement() == element)
				{
					return i;
				}

				node = node->getNextNode();
			}

			return -1;
		}
		
		template <typename T>
		int LinkedList<T>::lastIndexOf(const T& element)
		{
			Node<T>* node = _tail;

			for(int i = _size - 1; i >= 0; i--)
			{
				if(node->getElement() == element)
				{
					return i;
				}
				
				node = node->getPreviousNode();
			}

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
		String LinkedList<T>::toString()
		{
			String string = "";
			Node<T>* currentNode = _head;

			while(currentNode)
			{
				string += currentNode->getElement();
				if(currentNode->getNextNode())
				{
					string += ", ";
				}

				currentNode = currentNode->getNextNode();
			}

			return string;
		}

		template <typename T>
		LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& newList)
		{
			return *this;
		}
	}

#endif
