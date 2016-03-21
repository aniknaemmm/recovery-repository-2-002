#pragma once

#include "Digest.h"
#include "Unordered_Map.h"
#include <exception>


template <class Tkey, class Tvalue>
class ordered_map {
private:

	Unordered_map<Tkey, Tvalue>** array;
	size_t size;
	
public:

	ordered_map(size_t size_)
	{
		size = 3 * size_;
		array = new Unordered_map<Tkey, Tvalue> *[size];
		for (size_t i = 0; i < size; i++)
			array[i] = nullptr;
	}

	~ordered_map() { delete[] array; }
	
	Tvalue& operator[](Tkey key) 
	{
		int dig = digest(key);
		if (!array[dig%size])
		{
			array[dig%size] = new Unordered_map<Tkey, Tvalue>;
		}
		return (*array[dig%size])[key];
	}

	void show()
	{
		for (size_t i = 0; i < size; i++)
		{
			if (array[i])
				(array[i])->show();
		}
	}
	
	const Tkey& search(const Tvalue &val)
	{
		Unordered_map<Tkey, Tvalue> *temp; //I can not be used directly
		for (size_t i = 0; i < size; i++)
		{
			temp = array[i];
			if (temp){
				for (auto i = temp->pairs.begin(); (i != temp->pairs.end()); i++)
				{
					if (i->value == val)
						return i->key;
				}
			}
		}throw exception("Ordered_Map<Tkey, Tvalue>::search(Tvalue& val): value is not found");
	}
	
	ordered_map<Tkey, Tvalue>& dell(const Tkey &key)
	{
		int dig = digest(key);
		if (array[dig % size]){
			for (auto i = array[dig % size]->pairs.begin(); i != array[dig % size]->pairs.end(); ++i) {

				if (i->key == key) {
					array[dig % size]->pairs.erase(i);
					(*array[dig % size]).element--;
					break;
				}
			}
			return *this;
		}throw exception("Ordered_Map<Tkey, Tvalue>::dell(Tvalue& val): element for key is not found");		
	}

	 int statistics() {

		int elementtt = 0;
		for (size_t i = 0; i < size; ++i) {
			
			if (array[i])
				elementtt += array[i]->pairs.size() - 1;
		}
		return elementtt;
	}



};