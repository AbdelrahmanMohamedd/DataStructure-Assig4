#ifndef CONTACT_H_
#define CONTACT_H_

#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Contact 
{
private:
	string name;
	LinkedList<string> phone_numbers;

public:
	Contact();
	Contact(const string& name);
	void addPhoneNumber(const string& number);
	string getName();
	bool is_exist(const string& number);
	bool operator>(const Contact& c);
	bool operator<(const Contact& c);
	bool operator==(const Contact& c);
	friend ostream& operator<< (ostream& o, const Contact& c);
};

Contact::Contact()
	:name(""), phone_numbers()
{
	phone_numbers.delimeter = " - ";
}
Contact::Contact(const string& name)
	:name(name), phone_numbers()
{
	phone_numbers.delimeter = " - ";
}
void Contact::addPhoneNumber(const string& number)
{
	phone_numbers.addSorted(number);
}
string Contact::getName()
{
	return name;
}
bool Contact::is_exist(const string& number)
{
	if (phone_numbers.get(number) == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Contact::operator>(const Contact& c)
{
	return (this->name > c.name);
}
bool Contact::operator<(const Contact& c)
{
	return (this->name < c.name);
}
bool Contact::operator==(const Contact& c)
{
	return !(this->name < c.name || this->name > c.name);
}
ostream& operator<< (ostream& o, const Contact& c)
{
	o << c.name << ": " << c.phone_numbers;
	return o;
}

#endif  /* CONTACT_H_ */
