#include "List.h"
#include <iostream>
#include <new>

using namespace std;

List::~List()
{
}

List& List::push_front(const int& info)
{
	NodeList *data= new NodeList;
	data->info = info;
	data->next = nullptr;
	if (!size)
		last =data;
	data->link = first;
	if (first)
		first->next = data;
	first = data;
	size ++;
	data = nullptr;
	return *this;
}

List& List::push_back(const int& info)
{
	NodeList *data = new NodeList;
	data->info = info;
	data->link = nullptr;
	if (!size)
		first = data;
	data->next = last;
	if (last)
		last->link = data;
	last = data;
	size++;
	data = nullptr;
	return *this;
}

List& List::pop_front()
{
	if (!size){
		NodeList *temp = new NodeList;
		temp = first;
		if (first->link)
		{
			first = first->link;
			first->next = nullptr;
		}
		else
		{
			first = nullptr;
			last = nullptr;
		}
		delete temp;
		size--;
		return *this;
	}
	else throw	exception("ListNode::pop_front: list is empty\n");
}

List& List::pop_back()
{
	if (!size){
		NodeList *temp = new NodeList;
		temp = last;
		if (last->next)
		{
			last = last->next;
			last->link = nullptr;
		}
		else
		{
			first = nullptr;
			last = nullptr;
		}
		delete temp;
		size--;
		return *this;
	}
	else throw	exception("ListNode::pop_back: list is empty\n");
}

void List::insert(const size_t index, const int data)
{
	if (index>size)
	{
		exception("ListNode::insert: index  is not in range");
	}
	else if (!index || index==size)
	{
		push_front(data);
	}
	else 
	{
		NodeList *temp = last;
		for (size_t i = 0; i < (index-1); i++)
		{
			temp = temp->next;
		}

		NodeList *tempNode = new NodeList;
		tempNode->info = data;
		tempNode->link = temp;
		tempNode->next = temp->next;
		temp->next->link = tempNode;
		temp->next = tempNode;

	}
};

void List::dell(const size_t index)
{
	if (index>size)
	{
		exception("ListNode::insert: index  is not in range");
	}
	else if (!index)
	{
		pop_back();
	}
	else if (index == size)
	{
		pop_front();
		size--;
	}
	else
	{
		NodeList *temp = last;
		for (size_t i = 0; i < index ; i++)
		{
			temp = temp->next;
		}

		temp->next->link = temp->link;
		temp->link->next = temp->next;
		size--;
	}
};