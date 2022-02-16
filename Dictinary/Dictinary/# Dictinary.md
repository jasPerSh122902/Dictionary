# Dictinary

$File$ : _DictionaryT.h_ 

$Type$ : Tempate T

The dictinary is a class that takes in a key and gives a value. This can be compared to a dictinary for works were you search for a word and get its definition.


$Name$ : Dictionary<TKey, TValue>()
+ Description : A basic constructor for the dictionary class.
* Visualibility : public

$Name$ : Dictionary<TKey, TValue>(Dictionary<TKey, TValue>& other)
+ Description : A basic constructor for the dictionary class that takes in a dictionary.
* Visualibility : public

$Name$ : ~Dictionary<TKey, TValue>()
+ Description : A basic deconstructor for the dictionary class.
* Visualibility : public

$Name$ : clear()
+ Description : deletes all items in dictionary
* Visualibility : public
* Type : void

$Name$ : containsKey(const TKey key) const
+ Description : checks to see if there is that key
* Visualibility : public
* Type : bool

$Name$ : containsValue(const TValue value) const
+ Description : checks to see if there is that value
* Visualibility : public
* Type : bool

$Name$ : tryGetValue(const TKey key, TValue& value) const
+ Description : checks to see if it can find a key and value
* Visualibility : public
* Type : bool

$Name$ : addItem(const TKey key, TValue& value) const
+ Description : addes a item that gets a key and value. 
* Visualibility : public
* Type : void

$Name$ : remove(const TKey key) const
+ Description : removes the key
* Visualibility : public
* Type : bool

$Name$ : remove(const TKey key, TValue& value) const
+ Description : removes the key and spits out a value that the key contained
* Visualibility : public
* Type : bool

$Name$ : getCount() const
+ Description : gets the m_count
* Visualibility : public
* Type : int

$Name$ :operator=(const Dictionary<TKey, TValue> other)
+ Description : This operator gets the ability to assign values of a dictionary to a other dictionary.
* Visualibility : public
* Type :  Dictionary<TKey, TValue>& 

$Name$ :operator[](const TKey key)
+ Description : returns a key as a value
* Visualibility : public
* Type :  TValue

$Name$ :Item
+ Description : is a struct that is the basic information of a item
* Visualibility : private
* Type :  struct

$Name$ : itemKey
+ Description : Is the items key or name
* Visualibility : private
* Type :  TKey

$Name$ : itemValue
+ Description : Is the items Value or definition
* Visualibility : private
* Type :  TValue


$Name$ : m_items
+ Description : is a pointer to the item struct
* Visualibility : private
* Type :  Item*

$Name$ : m_count
+ Description : is a int that holds the amount of definitions I have
* Visualibility : private
* Type :  int