#pragma once

#include <iostream>

template <typename K, typename V>
class Dictionary
{
private:
	K* keys;
	V* values;
	int maxsize;
	int currentpos;
public:
	Dictionary();
	Dictionary(const Dictionary&);
	Dictionary& operator=(const Dictionary&);
	void addEntry(K, V);
	void resize();
	void sort();
	void print();
	V* findValue(K);
	~Dictionary();
};

template <typename K, typename V>
Dictionary<K, V>::Dictionary()
{
	keys = new K[2];
	values = new V[2];
	maxsize = 2;
	currentpos = 0;
}

template <typename K, typename V>
Dictionary<K, V>::Dictionary(const Dictionary& other)
{
	keys = new K[2];
	values = new V[2];
	*this = other;
}

template <typename K, typename V>
Dictionary<K, V>& Dictionary<K, V>::operator=(const Dictionary& other)
{
	if (keys != NULL) delete[] keys;
	if (values != NULL) delete[] values;
	keys = new K[other.maxsize];
	values = new V[other.maxsize];
	maxsize = other.maxsize;
	currentpos = other.currentpos;
	for (int i = 0; i < currentpos; i++)
	{
		keys[i] = other.keys[i];
		values[i] = other.values[i];
	}
	return *this;
}

template <typename K, typename V>
void Dictionary<K, V>::addEntry(K key, V value)
{
	if (currentpos == maxsize) resize();
	keys[currentpos] = key;
	values[currentpos] = value;
	currentpos++;
}

template <typename K, typename V>
void Dictionary<K, V>::resize()
{
	K* newKeys = new K[maxsize * 2];
	V* newValues = new V[maxsize * 2];
	maxsize *= 2;
	for (int i = 0; i < currentpos; i++)
	{
		newKeys[i] = keys[i];
		newValues[i] = values[i];
	}
	K* tempK = keys;
	keys = newKeys;
	delete[] tempK;
	V* tempV = values;
	values = newValues;
	delete[] tempV;
}

template <typename K, typename V>
void Dictionary<K, V>::sort()
{
	for (int i = 0; i < currentpos - 1; i++)
	{
		for (int j = i + 1; j < currentpos; j++)
		{
			if (keys[i] > keys[j])
			{
				std::swap(keys[i], keys[j]);
				std::swap(values[i], values[j]);
			}
		}
	}
}

template <typename K, typename V>
void Dictionary<K, V>::print()
{
	sort();
	for (int i = 0; i < currentpos; i++)
	{
		//std::cout << keys[i] << ':' << values[i] << std::endl;
		std::cout << values[i];
	}
}

template <typename K, typename V>
V* Dictionary<K, V>::findValue(K key)
{
	for (int i = 0; i < currentpos; i++)
	{
		if (keys[i] == key) return &values[i];
	}
	return NULL;
}

template <typename K, typename V>
Dictionary<K, V>::~Dictionary()
{
	delete[] keys;
	delete[] values;
}