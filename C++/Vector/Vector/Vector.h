#pragma once
#include <cstdlib>
#include <cstring>

using namespace std;

template <class T>
class Vector
{
private:
	T *vector;
	int size_vector;
	int memory;
public:
	class iterator
	{
	private:
		T* current;
		Vector* host;
	public:
		
		iterator(T* arg, Vector *host) : current(arg), host(host){};
		iterator() :current(nullptr), host(nullptr){};
		T& operator*() {
			if (current == nullptr) {
				throw invalid_argument(
					"In List::iterator::operator*() : invalid iterator");
			}
			return *current;
		}
		
		iterator& operator++() { // префиксный ++
			if (current == nullptr) {
				throw invalid_argument(
					"In List::iterator::operator++() : invalid iterator");
			}
			current += 1;
			return (*this);
		}



		bool operator==(const iterator &i) const{
			return current == i.current;
		}

		bool operator!=(const iterator &i) const{
			return current != i.current;
		}

		friend class Vector;
		
	};

	iterator begin() {
		return iterator(vector, this);
	}
	iterator end() {
		return iterator(vector+size_vector, this);
	}

	Vector()
	{
		size_vector = 0;
		vector = nullptr;
		memory = 1;
	}


	~Vector()
	{
		free(vector);
	}

	Vector(int sizeVector)
	{
		memory = sizeVector * 2;
		vector = (T *)malloc(memory*sizeof(T));
		size_vector = 0;
	}

	Vector& setValue(int position, T value)
	{
		if (size_vector >= position)
			vector[position - 1] = value;
		return (*this);
	}

	T& getValue(int position)
	{
		if (position > size_vector)
			exit(-1);
		return vector[position - 1];
	}

	Vector& pushBack(T value)
	{
		++size_vector;
		if (size_vector == memory)
		{
			memory *= 2;
			vector = (T*)realloc(vector, memory * sizeof(T));
		}
		vector[size_vector - 1] = value;
		return (*this);
	}

	T& popBack()
	{
		if (size_vector == 0)
			exit(1);
		if ((memory / size_vector) == 2)
		{
			memory /= 2;
			vector = (T*)realloc(vector, memory * sizeof(T));
		}
		T temp = vector[size_vector - 1];
		size_vector--;
		return temp;
	}

	Vector& pushFront(T value)
	{
		size_vector++;
		if (size_vector == memory)
		{
			memory *= 2;
			vector = (int*)realloc(vector, memory * sizeof(int));
		}
		memmove(vector + 1, vector, (size_vector - 1) * sizeof(int));
		vector[0] = value;
		return (*this);
	}

	T& popFront()
	{
		if (size_vector == 0)
			exit(1);
		if (memory / size_vector == 2)
		{
			memory /= 2;
			vector = (T*)realloc(vector, memory * sizeof(T));
		}
		T temp = vector[0];
		size_vector--;

		memmove(vector, vector + 1, memory*sizeof(T));
		return temp;
	}
	T& operator[](size_t position)
	{
		if (position > size_vector)
			exit(-1);
		return  vector[position];
	}

	const T& operator[](size_t position)const
	{
		if (position > size_vector)
			exit(-1);
		return  (const T&)vector[position];
	}

	iterator find(const T& value) {
		T* current_;
		current_ = vector;
		while (current_ != nullptr) {
			if (*current_ == value) {
				return iterator(current_, this);
			}
			current_++;
		}
		return iterator(nullptr, this);
	}

	Vector& erase(iterator &i)
	{
		if (i.current==nullptr)
			exit(1);
		if (memory / size_vector == 2)
		{
			memory /= 2;
			vector = (T*)realloc(vector, memory * sizeof(T));
		}
		size_vector--;
		memmove(i.current, i.current++,(vector + size_vector - i.current)*sizeof(T));
		return (*this);
	}
	
};
