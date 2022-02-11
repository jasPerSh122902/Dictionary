#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
	
public:
	Dictionary<TKey, TValue>();
	Dictionary<TKey,TValue>(Dictionary<TKey,TValue>& other );
	~Dictionary<TKey, TValue>();
	void clear();//deletes all items in dictionary
	bool containsKey(const TKey object) const;//checks to see if an item that has the given key is in the dictionary
	bool containsValue(const TValue object) const;//checks to see if an item that has the given value is in the dictionary
	bool  tryGetValue(const TKey key, const TValue& value) const;//creates a new item with the given key and value and adds it to the dictionary
	void addItem(const TKey& key, const TValue& value);//tries to find the item that matches the given key
	bool remove(const TKey key);//removes the item that has the given key
	bool remove(const TKey key, TValue& value);//removes the item that has the given key and gives back the value of the item that was removed
	int  getCount() const;//gets the number of items in the dictionary
	Dictionary<TKey, TValue>& operator=(const Dictionary<TKey, TValue> other)const;
	TValue operator[](const TKey key);
private:

	struct Item
	{
	public:
		TKey itemKey;
		TValue itemValue;
	};
	Item* m_items = nullptr;
	int m_count;
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary()
{
	m_count = 0;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(Dictionary<TKey, TValue>& other)
{
	Dictionary::Dictionary() = other;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary()
{
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	Dictionary().~Dictionary();
	//remove();
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	TValue key = 0;
	if (tryGetValue(object, key))
	{
		if (object != 0)
			return true;
	}

	else return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	TKey key = 0;
	if (tryGetValue(key, object))
	{
		if (object != 0)
			return true;
	}

	else return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, const TValue& value) const
{
	//checks if key is not 0
	if (key != 0 || key > m_count) {
		//checks if this (this is key) contains a value
		if (this->containsValue(value)) 
		{
			//return that value
			return value;
		}
	}
	//if not
	else return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	return false;
}

template<typename TKey, typename TValue>
inline int Dictionary<TKey, TValue>::getCount() const
{
	return m_count;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other) const
{
	// TODO: insert return statement here
	m_items = other.m_items;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	return TValue();
}
