#pragma once

template <typename T> 
class myList
{
private:
	int maxIndex;
	T* item;
	int allocSize;
public:
	myList()
	{
		maxIndex = 0;
		allocSize = 256;
		item = new T[allocSize];
	}

	~myList()
	{
		delete[] item;
	}

	void insert(const T newItem)
	{
		if (maxIndex == allocSize)
		{
			allocSize *= 2;
			T* newT = new T[allocSize];
			for (int i = 0; i < allocSize/2; i++)
			{
				newT[i] = item[i];
			}
			delete[] item;
			item = newT;
		}
		item[maxIndex] = newItem;
		maxIndex++;
	}

	T find(const int index)
	{
		if (index < maxIndex)
			return item[index];
	}
	
};

