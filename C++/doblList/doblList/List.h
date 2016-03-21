#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

template <class T>
class List
{
private:
	struct Node
	{
		T data;
		Node *next;
		Node *prev;
	};
public:

	class iterator {
	private:
		List * host;
		Node* current;
		//List& host;
	public:
		iterator(Node* arg,List *host) : current(arg),host(host){};
		iterator() :iterator(nullptr) host(nullptr){};
		T& operator*() {
			if (current == nullptr) {
				throw invalid_argument(
					"In List::iterator::operator*() : invalid iterator");
			}
			return current->data;
		}
		iterator& operator++() { // префиксный ++
			if (current == nullptr) {
				throw invalid_argument(
					"In List::iterator::operator++() : invalid iterator");
			}
			current = current->next;
			return (*this);
		}

		iterator& operator++(int) { // постфиксный
			if (current == nullptr) {
				throw invalid_argument(
					"In List::iterator::operator++(int) : invalid iterator");
			}
			current = current->next;
			return (*this);
		}

		

		bool operator==(const iterator &i) const{
			return current == i.current;
		}

		bool operator!=(const iterator &i) const{
			return current != i.current;
		}

		friend class List;
	};  // end of List::iterator

	iterator begin() {
		return iterator(Begin,this);
	}
	iterator end() {
		return iterator(nullptr,this);
	}

	Node *Begin;
	Node *End;
	int element_count;
	int element_size;

public:

	size_t ElementCount()
	{
		return element_count;
	}

	
	List &PushFront(const T& element)
	{
		Node *new_element = new Node;
		new_element->data = element;
		new_element->prev = nullptr;
		new_element->next = Begin;
		if (Begin != nullptr)
			Begin->prev = new_element;
		Begin = new_element; 
		if (End == nullptr)
			End = new_element; 
		++element_count;
		return *this;
	}

	List &PopFront(){
		if (element_count == 0)
			throw 0;
		Node *temp = Begin;
		Begin = temp->next;
		//delete temp->data;????????
		delete temp;
		if (element_count == 1)
			End = nullptr;
		else
			Begin->prev = nullptr;
		--element_count;
		return *this;
	}

	List &PushEnd(const T& element)
	{
		Node *new_element = new Node;
		new_element->data = new char[element_size];
		new_element->data = element;
		new_element->next = nullptr;
		new_element->prev = End;
		End->next = new_element;
		End = new_element;
		if (element_count == 0)
			Begin = new_element;
		++element_count;
		return *this;
	}

	List &PopEnd(){
		if (element_count == 0)
			throw 0;
		Node *temp = End;
		End->next = nullptr;
		if (element_count = 1)
		{
			Begin = nullptr;
			End = nullptr;
		}
		else
			End = End->prev;
		//delete temp->data;???????
		delete temp;
		--element_count;
		return *this;
	}

	T &operator[](int index)
	{
		if (index >= element_count)
			throw 1;
		Node *temp;
		if (index <= element_count / 2)
		{
			temp = End;
			for (int i = 0; i < index; i++)
				temp = temp->prev;
		}
		else
		{
			temp = Begin;
			for (int i = element_count - 1; i > index; i--)
				temp = temp->next;
		}
		return temp;

	}
	List &operator=(const List &source){
		while (element_count--)
			PopFront();
		element_count = source.element_count;
		element_size = source.element_size;
		Node *temp = source.Begin;
		for (int i = 0; i < element_count; i++, temp = temp->next)
		{
			PushEnd(temp->data);
		}
		return *this;
	}


	// ctor
	List() : element_count(0), Begin(nullptr), End(nullptr) {};
	List(const List &orig){
		element_size = orig.element_size;
		element_count = orig.element_count;
		Node *temp = Begin;
		for (int i = 0; i < element_count; i++, temp = temp->next)
		{
			PushEnd(temp->data);
		}
	}

	iterator find(const T& value) {
		Node* current;
		current = Begin;
		while (current != nullptr) {
			if (current->data == value) {
				return iterator(current,this);
			}
			current = current->next;
		}
		return iterator(nullptr,this);
	}

	// dtor
	~List(){
		while (element_count)
			PopFront();
	}

	List& erase(iterator& i) {

		if (i.current->next == nullptr)
		{
			End = i.current->prev;
		}
		else
		{
			i.current->next->prev = i.current->prev;
		
		}
		if (i.current->prev == nullptr)
		{
			Begin = i.current->next;
		}
		else
		{
			i.current->prev->next = i.current->next;
		}
		delete i.current;
		i.current = nullptr;
		element_count--;
		return (*this);
		/*
		if (element_count == 0)
			throw 0;
		Node *prev = i.current->prev;
		Node *next = i.current->next;
		if (prev != nullptr) {
			prev->next = next;
		}
		else {
			next->prev = nullptr;
			next = Begin;
		}
		if (next == nullptr) {
			next = End;
		}
		delete i.current;
	   --element_count;
		i.current = next;
		return *this;*/
	}
	

	

};

