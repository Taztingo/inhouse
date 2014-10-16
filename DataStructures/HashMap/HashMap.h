#ifndef HASHMAP_H_
#define HASHMAP_H_

#include "../../Common/Type.h"
#include "../DynamicArray/DynamicArray.h"
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
			V& remove(K& key);
			uint size();

			bool operator==(HashMap<K,V>& hashMap);
			HashMap& operator=(HashMap<K,V>& hashMap);
			V& operator[](K& key);

		private:
			DynamicArray<DynamicArray<Pair<K,V> > > _hashMap;
	};

	template <class K, class V>
	HashMap<K,V>::HashMap()
	{
	}

	template <class K, class V>
	HashMap<K,V>::HashMap(uint capacity)
	{
		_hashMap.ensureCapacity(capacity);
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
		return true;
	}
	
	template <class K, class V>
	bool HashMap<K,V>::containsValue(V& value)
	{
		return true;
	}
	
	template <class K, class V>
	V& HashMap<K,V>::remove(K& key)
	{
		V v;
		return v;
	}
	
	template <class K, class V>
	uint HashMap<K,V>::size()
	{
		return _hashMap.getSize();
	}
	
	template <class K, class V>
	bool HashMap<K,V>::operator==(HashMap<K,V>& hashMap)
	{
		return true;
	}

	template <class K, class V>
	HashMap<K,V>& HashMap<K,V>::operator=(HashMap<K,V>& hashMap)
	{
		return *this;
	}

	template <class K, class V>
	V& HashMap<K,V>::operator[](K& key)
	{
		V v;
		return v;
	}
}

#endif
