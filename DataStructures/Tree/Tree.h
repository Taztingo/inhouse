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
			private:
				DynamicArray<T> _tree;
				uint _children;
				uint _size;

			public:
				Tree();
				Tree(uint children);
				~Tree();
		};

		template <typename T>
		Tree<T>::Tree()
		{
		}

		template <typename T>
		Tree<T>::Tree(uint children)
		{
		}

		template <typename T>
		Tree<T>::~Tree()
		{
		}
	}

#endif
