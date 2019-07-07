#ifndef CONTACT_MANAGER_H_
#define CONTACT_MANAGER_H_

#include "LinkedList.h"
#include "Contact.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Treap.h"

using namespace std;

class ContactManager
{
private:
	LinkedList<Contact> contacts;
	Treap<string, Contact*> tree;

public:
	ContactManager();
	bool loadFromFile(const string& fileName);
	void add(const string& name, const string& phone_number);
	void displayNumber(const string& phone_number) const;
	friend ostream& operator<<(ostream& o, const ContactManager & c);
};

ContactManager::ContactManager()
	:contacts()
{
	contacts.delimeter = '\n';
}
bool ContactManager::loadFromFile(const string& filename)
{
	ifstream read_data;
	read_data.open(filename.c_str());
	if (read_data.fail())
	{
		return false;
	}
	else
	{
		char next_character = 0;
		string number;
		string name;
		LinkedList<Contact>::Node* contact_node = NULL;

		while (true)
		{
			next_character = read_data.peek();
			if (next_character == EOF)
			{
				break;
			}
			read_data >> number;
			read_data.ignore();
			getline(read_data, name, '\n');
			Contact temp_contact(name);
			contact_node = contacts.get(temp_contact);
			if (contact_node == NULL)
			{
				temp_contact.addPhoneNumber(number);
				contacts.addSorted(temp_contact);
			}
			else
			{
				contact_node->value.addPhoneNumber(number);
			}
		}
	}
	return true;
}
void ContactManager::add(const string& name, const string& phone_number)
{
	Contact temp_contact(name);
	LinkedList<Contact>::Node* contact_node = contacts.get(temp_contact);
	if (contact_node == NULL)
	{
		temp_contact.addPhoneNumber(phone_number);
		contacts.addSorted(temp_contact);
		tree.insert(phone_number, &temp_contact);
	}
	else
	{
		if (contact_node->value.is_exist(phone_number) == false)
		{
			contact_node->value.addPhoneNumber(phone_number);
		}
	}
}
void ContactManager::displayNumber(const string& phone_number) const
{
	
}
ostream& operator<< (ostream& o, const ContactManager& c)
{
	cout << c.contacts;
	return o;
}

#endif  /* CONTACT_MANAGER_H_ */
