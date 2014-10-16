#ifndef PAIR_H_
#define PAIR_H_

namespace inhouse
{
	template <class K, class V>
	struct Pair
	{
		public:
			Pair(K& key, V& value);
			~Pair();

			K& getKey();
			V& getValue();

		private:
			K _key;
			V _value;
	};

	template <class K, class V>
	Pair<K,V>::Pair(K& key, V& value)
	{
		_key = key;
		_value = value;
	}

	template <class K, class V>
	Pair<K,V>::~Pair()
	{
	}
	
	template <class K, class V>
	K& Pair<K,V>::getKey()
	{
		return _key;
	}
	
	template <class K, class V>
	V& Pair<K,V>::getValue()
	{
		return _value;
	}
}
#endif
