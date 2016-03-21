#pragma once
#include <string>
#include <iostream>
using namespace std;
template <class Tkey,class Tvalue>
class tree
{
private:
	struct Node {
		// конструктор по умолчанию (для структуры)
		Node(const Tkey &key_, const Tvalue value_ = 0):
		left(nullptr), right(nullptr), key(key_), value(value_) {};
		~Node()
		{
			std::cout << value << std::endl;
			delete left;
			delete right;
			
		};
		Node *left;
		Node *right;
		Tvalue value;
		const Tkey key;
	};
	Node *root;

	Tvalue& CheckAndInsert(Node* current, Tkey key)
	{
		if (current == nullptr) 
			current = new Node(key);
			return current->value;
	}

	void show(Node *root_)
	{
		if (!root_) return;
		std::cout << root_->value << std::endl;
		show(root_->left);
		show(root_->right);
	}


public:
	tree() : root(nullptr) {};
	~tree() 
	{
		delete root;
	};

	Tvalue& operator[] (const Tkey &key) {
		Node *current = root;
		Node **pointer = &root;//указатель на место в памяти где лежит current
		while (current!=nullptr) 
		{
			if (key < current->key)
			{
				pointer = &(current->left);
				current = current->left;
			}
			else if (current->key < key)
			{ 
				// идем вправо
				pointer = &(current->right);
				current = current->right;
			}
			else 
			{ 
				// нашли
				return current->value;
			}
			
		}

		*pointer = new Node(key);
		return (*pointer)->value;

	}

	void showshow()
	{
		show(root);
	}

	tree<Tkey, Tvalue>& dell(Tvalue& key)
	{
		Node *current = root;
		Node **pointer = &root;
		while (current->key!=key)
		{
			if (key < current->key)
			{
				current = current->left;
			}
			else if (current->key < key)
			{
				current = current->right;
			}

		}

		*pointer = new Node(key);
		return (*pointer)->value;
	}

};