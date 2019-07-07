#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include<iostream>
#include<string>

using namespace std;

template<class T>
class LinkedList
{
public:
	class Node
	{
	public:
		T value;
		Node* next;
		//Constructors.
		Node();
		Node(const T&);
		Node(const T&, Node*);
	};

private:
	Node* head;

public:
	string delimeter; // optional: just for printing.
	//Constructor.
	LinkedList();
	//Add the element in the suitable location.
	Node* addSorted(const T&);
	//return the Node* corresponding to the value(Search).
	Node* get(const T&);
	// operator overloading for printing
	friend ostream& operator<< <>(ostream& o, LinkedList<T> c);
};

//Inner Class.
template<class T>
LinkedList<T>::Node::Node()
	:value(0), next(NULL)
{}
template<class T>
LinkedList<T>::Node::Node(const T& v)
	: value(v), next(NULL)
{}
template<class T>
LinkedList<T>::Node::Node(const T& v, typename LinkedList<T>::Node* n)
	: value(v), next(n)
{}

//Outer Class.
template<class T>
LinkedList<T>::LinkedList()
	: head(NULL), delimeter("")
{}
template<class T>
typename LinkedList<T>::Node* LinkedList<T>::addSorted(const T& c)
{
	if (head == NULL)
	{
		head = new LinkedList<T>::Node(c, NULL);
		return head;
	}
	LinkedList<T>::Node* new_node = new Node(c);
	LinkedList<T>::Node* pre_current = NULL;
	LinkedList<T>::Node* current = head;
	while (true)
	{
		if (current == NULL)
		{
			new_node->next = NULL;
			pre_current->next = new_node;
			break;
		}
		else if (new_node->value < current->value)
		{
			if (current == head)
			{
				new_node->next = current;
				head = new_node;
			}
			else
			{
				new_node->next = current;
				pre_current->next = new_node;
			}
			break;
		}
		else
		{
			pre_current = current;
			current = current->next;
		}
	}
	return new_node;
}
template<class T>
typename LinkedList<T>::Node* LinkedList<T>::get(const T& v)
{
	LinkedList<T>::Node* current = head;
	while (current != NULL)
	{
		if (current->value == v)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}
template<class T>
ostream& operator<< <>(ostream& o, LinkedList<T> c)
{
	if (c.head == NULL)
	{
		return o;
	}
	LinkedList<T>::Node* current = c.head;
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			o << current->value;
		}
		else
		{
			o << current->value << c.delimeter;
		}
		current = current->next;
	}
	return o;
}

#endif  /* LINKED_LIST_H_ */