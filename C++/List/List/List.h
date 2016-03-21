#pragma once
#include <iostream>
#include <exception>
#include <new>
class List
{
private:
	struct NodeList
	{
		int info;
		NodeList *next;
		NodeList *link;

	};

	NodeList *first;
	NodeList *last;
	size_t size;

	class ListHelper
	{
	private:
		NodeList *element;
	public:
		ListHelper() :element(nullptr){};
		ListHelper(NodeList *element){ element = this->element ; };
		~ListHelper();
	};


public:
	List() :first(nullptr),last(nullptr), size(0){};
	~List();
	List &push_front(const int& info);
	List &push_back(const int& info);
	List &pop_front();
	List &pop_back();
	void insert(const size_t index, const int data);
	void dell(const size_t index);
	bool revers();
	
};
