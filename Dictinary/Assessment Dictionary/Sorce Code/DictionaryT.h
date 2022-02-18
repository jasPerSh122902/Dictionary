#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
	
public:
	Dictionary<TKey, TValue>();
	Dictionary<TKey,TValue>(Dictionary<TKey,TValue>& other );
	~Dictionary<TKey, TValue>();
	void clear();//deletes all items in dictionary
	bool containsKey(const TKey key) const;//checks to see if an item that has the given key is in the dictionary
	bool containsValue(const TValue value) const;//checks to see if an item that has the given value is in the dictionary
	bool tryGetValue(const TKey key,  TValue& value) const;//tries to find the item that matches the given key
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
	 delete[] m_items;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey key) const
{
	//checks if the itms key is the object
	for (int i = 0; i < getCount(); i++) 
	{
		//compares the items key to the taken in key
		if (m_items[i].itemKey == key)
		{
			//makes the items print
			std::cout << "| Key: " << key << std::endl;
			return true;//return true
		}
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue value) const
{
	//iterate through the arry 
	for (int i = 0; i < getCount(); i++) 
	{
		//compared the items value to the value that is taken in
		if (m_items[i].itemValue == value) 
		{
			//makes the items print
			std::cout << "| Value: " << value << std::endl;
			return true;//return true
		}
			
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	//iterates through the array of items.
	for (int i = 0; i < getCount(); i++) 
	{
		//compares the key and key that is taken in
		if (m_items[i].itemKey == key )
		{
			//makds the vlaue equal to the item at teh index of i's value
			value = m_items[i].itemValue;
			//makes the items print
			std::cout << "| Value : " << value << " "<<"Key : "<< key;
			return true;//return true
		}
	}
	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	//Make new item array that is 1 more
	Item* newArrayItem = new Item[m_count + 1];
	//for loop to copy the values in the old to the new
	int j = 0;
	for (int i = 0; i < getCount(); i++)
	{
		//set the new array at teh index of i to the m_items at the index of i
		newArrayItem[j].itemKey = m_items[i].itemKey;
		newArrayItem[j].itemValue = m_items[i].itemValue;
		j++;
	}

	//addes the value one the index of the ocunt
	newArrayItem[m_count].itemValue = value;
	newArrayItem[m_count].itemKey = key;

	//delete old array
	delete[] m_items;
	
	//then make m_ites equal to the new array
	m_items = newArrayItem;
	//increase count
	m_count++;
	//makes the items print
	//std::cout << " " << m_items->itemValue;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	//Make new item array that is 1 less
	Item* newArrayItem = new Item[m_count - 1];
	bool itemRemoved = false;
	//check if the key exists
	if (containsKey(key)) 
	{
		int j = 0;
		//iterate through the array of items...
		for (int i = 0; i < getCount(); i++)
		{
			if (m_items[i].itemKey != key) 
			{
				//iterate with i and makes j increase to copy values
				newArrayItem[j].itemKey = m_items[i].itemKey;//copy key
				newArrayItem[j].itemValue = m_items[i].itemValue;//copy value
				j++;//increase j
			}
			else
			{
				//makes item removed true
				itemRemoved = true;
			}

		}
		if (itemRemoved = true)
		{
			//prints the item to the console
			//std::cout << "| The items key that is removed: " << m_items[j].itemKey << std::endl;
			delete[] m_items;
			//copy all of the values form the new array to the old array
			m_items = newArrayItem;
			//subtracts 1 from count
			m_count--;
		}
		else delete newArrayItem;//just remove the new array

		return itemRemoved;//return the value that is removed
		
	}
	
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	//Make TValue as a holder for value
	TValue valueRemoved;
	//chekc if it was a key and value
	if (containsKey(key) && containsValue(value))
	{
		//check to try and get the key, value is all ready made
		if (tryGetValue(key, valueRemoved))
		{
			remove(key);//removes the key
			//set the value to the value removed
			value = valueRemoved;
			//prints the item to the console
			std::cout << "| The items vlaue that is removed: " << value << std::endl;
			return true;
		}
		else return false;
	}
}

template<typename TKey, typename TValue>
inline int Dictionary<TKey, TValue>::getCount() const
{
	return m_count;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other) const
{
	m_items->itemKey = other.m_items->itemKey;
	m_items->itemValue = other.m_items->itemValue;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	return TValue(key);
}
