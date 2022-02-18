#include <iostream>
#include "DictionaryT.h"
//the commits for the main is the test as the developer of...
//...this data stuctor had to do to see if everything worked
int main()
{
	int m_x = 563;

	//instence of the dictionary
	Dictionary<int, int> m_dictionary;
	//adds items to the array
	//----------------------------
	m_dictionary.addItem(1, 3);
	m_dictionary.addItem(2, 563);
	m_dictionary.addItem(3, 123);
	m_dictionary.addItem(4, 400);
	//----------------------------
	//searches for the value returns a bool
	std::cout << "search for the value" << std::endl;
	m_dictionary.containsValue(123);
	//searches for the key and returns a bool
	std::cout << "tryies to get the key 4" << std::endl;
	m_dictionary.containsKey(4);
	//tries to get the value with a key and a int
	std::cout << "search for the key 2" << std::endl;
	m_dictionary.tryGetValue(2, m_x);
	//--------------------------------
	std::cout << " " << std::endl;
	std::cout << "removed key 2 and spits out that key" << std::endl;
	 m_dictionary.remove(2, m_x);//The remove function takes in a Key and a value
	 std::cout << "serches for 2 that is removed, this should show up blank" << std::endl;
	 m_dictionary.tryGetValue(2, m_x);
	 
	//--------------------------------
	//m_dictionary.remove(4);//removes with only a key
	//--------------------------------
	 system("pause");
}

