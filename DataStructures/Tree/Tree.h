/* Created by Matt Witkowski
 * Tree.h
 * A Tree that can have n children, and 2 being the default.
 *
 */

#ifndef TREE_H_
	#define TREE_H
	
	#include "../../Common/Type.h"
	#include "../DynamicArray/DynamicArray.h"

	namespace inhouse
	{
		template <class T>
		class Tree
		{
			protected:
				DynamicArray<T> _tree;
				uint _children;


			public:
				Tree();
				Tree(uint children);
				~Tree();
				T& getChild(uint nodeIndex, uint child);
				void setChild(uint nodeIndex, uint child, T& element);
				String toString();
				uint getSize(uint nodeIndex);
				String traverseInOrder();
				String traversePreOrder();
				String traversePostOrder();
				T& removeChild(uint nodeIndex, uint child);
				bool isLeaf();
				
				Tree& operator=(Tree& tree);
				bool operator==(Tree& tree);
				bool operator!=(Tree& tree);
		};

		template <typename T>
		Tree<T>::Tree()
		{
			_children = 2;
		}

		template <typename T>
		Tree<T>::Tree(uint children)
		{
			_children = children;
		}

		template <typename T>
		Tree<T>::~Tree()
		{
		}
		
		template <typename T>
		T& Tree<T>::getChild(uint nodeIndex, uint child)
		{
		}

		template <typename T>
		void Tree<T>::setChild(uint nodeIndex, uint child, T& element)
		{
		}

		template <typename T>
		String Tree<T>::toString()
		{
		}

		template <typename T>
		uint Tree<T>::getSize(uint nodeIndex)
		{
		}

		template <typename T>
		String Tree<T>::traverseInOrder()
		{
		}

		template <typename T>
		String Tree<T>::traversePreOrder()
		{
		}

		template <typename T>
		String Tree<T>::traversePostOrder()
		{
		}

		template <typename T>
		T& Tree<T>::removeChild(uint nodeIndex, uint child);
		{
		}
		
		template <typename T>
		bool Tree<T>::isLeaf()
		{
		}

		template <typename T>
		bool Tree<T>::operator=(Tree& tree)
		{
		}

		template <typename T>
		bool Tree<T>::operator==(Tree& tree)
		{
		}

		template <typename T>
		bool Tree<T>::operator!=(Tree& tree)
		{
		}
	}

#endif
