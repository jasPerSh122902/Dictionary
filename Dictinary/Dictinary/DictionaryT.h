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
	bool  tryGetValue(const TKey key,  TValue& value) const;//tries to find the item that matches the given key
	void addItem(const TKey& key, const TValue& value);//creates a new item with the given key and value and adds it to the dictionary
	bool remove(const TKey key);//removes the item that has the given key
	bool remove(const TKey key, TValue& value);//removes the item that has the given key and gives back the value of the item that was removed
	int  getCount() const;//gets the number of items in the dictionary
	const Dictionary<TKey, TValue>& operator=(const Dictionary<TKey, TValue> other)const;
	TValue operator[](const TKey key);
private:

	struct Item
	{
	public:
		TKey itemKey;
		TValue itemValue;
	};
	Item* m_items;
	int m_count;
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary()
{
	m_count = 0;
	m_items = nullptr;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(Dictionary<TKey, TValue>& other)
{
	m_count = other.m_count;
	m_items = other.m_items;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary()
{
	m_items = nullptr;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	//makes i equal to m_ocunt and if i is less than m_count or equal to...
	
	for (int i = m_count; i <= getCount(); i++) 
	{
		//makes sure if i is 0
		if (i == 0)
			break;//break out of the loop
		//check to see if the i value dos exist and if it is itemValue
		if (containsValue(i) == m_items->itemValue)
		{
			if (true)//if yes
			{
				delete m_items;//delete m_items
				m_count--;
			}
		}
	}
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	//checks if the itms key is the object
	if (m_items->itemKey = object)
	{
		return true;//if so return true
	}
	//otherwise false
	else return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	//checks if the item value is the object
	if (m_items->itemValue = object)
	{
		return true;//if so return true
	}
	//otherwise false
	else return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	//checks if key is not 0 and if the key is greater than the count
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
	Item* m_newItem = new Item();
	m_newItem->itemKey = key;
	m_newItem->itemValue = value;

	m_count++;
	m_items = m_newItem;
	std::cout << " "<< m_items->itemValue;
	
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	//if it is not the key return false
	if (!key) return key;

	//check it the items key is the key that is given
	if (m_items->itemKey = key)
	{
		//this is a pointer to the key
		//probebly will not work
		delete &key;
		m_count--;//decrement the count
		return true;//return the value
	}
	else return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	//if it is not the key return false
	if (!key) return false;

	//check it the items key is the key that is given
	if (m_items->itemKey = key)
	{
		//checks if the items value is the value
		if (m_items->itemValue = value)
		{
			//this is a pointer to the key
			//probebly will not work
			delete &key;
			m_count--;//decrement the count
			return value;//return the value
		}
		return false;
	}
	else return false;
}

template<typename TKey, typename TValue>
inline int Dictionary<TKey, TValue>::getCount() const
{
	if (m_count != NULL) return m_count;
	else return NULL;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other) const
{
	//
	*m_items = *other.m_items;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	return TValue(key);
}
