#ifndef HASHMAP_H_
#define HASHMAP_H_

#include "../../Common/Type.h"
#include "../DynamicArray/DynamicArray.h"
#include <iostream>
#include "Pair.h"

namespace inhouse
{
	
	template <class K, class V>
	class HashMap
	{
		public:
			HashMap();
			HashMap(uint capacity);
			HashMap(HashMap<K,V>& hashMap);
			~HashMap();
			void clear();
			bool containsKey(K& key);
			bool containsValue(V& value);
			V remove(K& key);
			uint getSize();

			bool operator==(HashMap<K,V>& hashMap);
			HashMap& operator=(HashMap<K,V>& hashMap);
			V& operator[](K& key);

		private:
			DynamicArray<DynamicArray<Pair<K,V> > > _hashMap;
			DynamicArray<K> _keys;

			uint hash(K& key);
	};

	template <class K, class V>
	HashMap<K,V>::HashMap()
	{
		for(uint i = 0; i < _hashMap.getCapacity(); i++)
		{
			DynamicArray<Pair<K,V> > storage;
			_hashMap.add(storage);
		}
	}

	template <class K, class V>
	HashMap<K,V>::HashMap(uint capacity)
	{
		_hashMap.ensureCapacity(capacity);
		
		for(uint i = 0; i < _hashMap.getCapacity(); i++)
		{
			DynamicArray<Pair<K,V> > storage;
			_hashMap.add(storage);
		}
	}

	template <class K, class V>
	HashMap<K,V>::HashMap(HashMap<K,V>& hashMap)
	{
		_hashMap = hashMap._hashMap;
	}

	template <class K, class V>
	HashMap<K,V>::~HashMap()
	{
	}
	
	template <class K, class V>
	void HashMap<K,V>::clear()
	{
		_hashMap.clear();
	}
	
	template <class K, class V>
	bool HashMap<K,V>::containsKey(K& key)
	{
		return _keys.contains(key);
	}
	
	template <class K, class V>
	bool HashMap<K,V>::containsValue(V& value)
	{
		return true;
	}
	
	template <class K, class V>
	V HashMap<K,V>::remove(K& key)
	{
		int hashCode(key);
		DynamicArray<Pair<K,V> > array = _hashMap[hashCode];
		V value;

		for(uint i = 0; i < array.getSize(); i++)
		{
			if(array[i].containsKey(key))
			{
				value = remove.getValue();
				_keys.removeElement(key);
				break;
			}
		}

		return value;
	}
	
	template <class K, class V>
	uint HashMap<K,V>::getSize()
	{
		return _hashMap.getSize();
	}
	
	template <class K, class V>
	bool HashMap<K,V>::operator==(HashMap<K,V>& hashMap)
	{
		return _hashMap == hashMap._hashMap;
	}

	template <class K, class V>
	HashMap<K,V>& HashMap<K,V>::operator=(HashMap<K,V>& hashMap)
	{
		_hashMap = hashMap._hashMap;

		return *this;
	}

	template <class K, class V>
	V& HashMap<K,V>::operator[](K& key)
	{
		int hashIndex = hash(key);
		DynamicArray<Pair<K,V>>& array = _hashMap[hashIndex];

		for(uint i = 0; i < array.getSize(); i++)
		{
			Pair<K,V> pair = array[i];
			if(pair.containsKey(key))
			{
				return array[i].getValue();
			}
		}

		_keys.add(key);
		Pair<K,V> pair(key);
		array.add(pair);

		return array[array.getSize() - 1].getValue();
	}
	
	template <class K, class V>
	uint HashMap<K,V>::hash(K& key)
	{
		return 0;
	}
}

#endif
