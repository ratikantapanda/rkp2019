#include <iostream>

#define TABLE_SIZE 128

struct HashEntry 
{
	int key;
	int value;
	HashEntry *next;
	HashEntry(int key, int value) 
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}

};



struct HashMap 
{
	HashEntry **table;
	HashMap() {
		table = new HashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	int get(int key) 
	{
		int hash = (key % TABLE_SIZE);
		if (table[hash] == nullptr)
			return -1;
		else 
		{
			HashEntry *entry = table[hash];
			while (entry != nullptr && entry->key!= key)
				entry = entry->next;
			if (entry == nullptr)
				return -1;
			else
				return entry->value;
		}
	}

	void put(int key, int value) 
	{
		int hash = (key % TABLE_SIZE);
		if (table[hash] == nullptr)
			table[hash] = new HashEntry(key, value);
		else 
		{
			HashEntry *entry = table[hash];
			while (entry->next != nullptr && entry->key !=key)
				entry = entry->next;
			if (entry->key == key)
				entry->value=value;
			else
				entry->next=new HashEntry(key, value);
		}
	}

	void remove(int key) 
	{
		int hash = (key % TABLE_SIZE);
		if (table[hash] != nullptr) {
			HashEntry *prevEntry = nullptr;
			HashEntry *entry = table[hash];
			while (entry->next!= nullptr && entry->key != key) {
				prevEntry = entry;
				entry = entry->next;
			}
			if (entry->key== key) 
			{
				if (prevEntry == nullptr) 
				{
					HashEntry *nextEntry = entry->next;
					delete entry;
					table[hash] = nextEntry;
				} 
				else 
				{
					HashEntry *next = entry->next;
					delete entry;
					prevEntry->next;
				}
			}
		}
	}

	~HashMap() 
	{
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != nullptr) {
				HashEntry *prevEntry = NULL;
				HashEntry *entry = table[i];
				while (entry != nullptr) {
					prevEntry = entry;
					entry = entry->next;
					delete prevEntry;
				}
			}
		delete[] table;
	}
};

int main()
{
	HashMap  hm;
	hm.put(10,100);
	hm.put(10,100);
	std::cout << hm.get(10) << std::endl;

	return 0;
}











