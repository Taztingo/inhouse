#ifndef NODE_H_
	#define NODE_H_
	
	#include "../../Standard/Standard.h"

	namespace inhouse
	{
		template <class T>
		class Node
		{
			private:
				T _element;
				Node<T>* _nextNode;
				Node<T>* _previousNode;

			public:
				Node();
				Node(T element);
				virtual ~Node();

				T& getElement();
				Node<T>& getNextNode();
				Node<T>& getPreviousNode();
				void setElement(T element);
				void setNextNode(Node<T>& nextNode);
				void setPreviousNode(Node<T>& previousNode);
				bool hasPreviousNode();
				bool hasNextNode();
		};

		template <class T>
		Node<T>::Node()
		{
			_nextNode = nullptr;
			_previousNode = nullptr;
		}
	
		template <class T>
		Node<T>::Node(T element)
		{
			_element = element;
			_nextNode = nullptr;
			_previousNode = nullptr;
		}

		template <class T>
		Node<T>::~Node()
		{
		}

		template <class T>
		T& Node<T>::getElement()
		{
			return _element;
		}

		template <class T>
		Node<T>& Node<T>::getNextNode()
		{
			errorIf(_nextNode == nullptr, "The next node is null, use hasNextNode.");
			return *_nextNode;
		}

		template <class T>
		Node<T>& Node<T>::getPreviousNode()
		{
			errorIf(_previousNode == nullptr, "The previous node is null, use hasPreviousNode.");
			return *_previousNode;
		}
	
		template <class T>
		void Node<T>::setElement(T element)
		{
			_element = element;
		}

		template <class T>
		void Node<T>::setNextNode(Node<T>& nextNode)
		{
			_nextNode = &nextNode;
		}
	
		template <class T>
		void Node<T>::setPreviousNode(Node<T>& previousNode)
		{
			_previousNode = &previousNode;
		}
	
		template <class T>
		bool Node<T>::hasPreviousNode()
		{
			return !(_previousNode == nullptr);
		}
	
		template <class T>
		bool Node<T>::hasNextNode()
		{
			return !(_nextNode == nullptr);
		}
	}
#endif
