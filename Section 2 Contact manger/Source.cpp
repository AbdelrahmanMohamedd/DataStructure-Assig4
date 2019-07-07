#include <iostream>
#include <fstream>
#include "ContactManager.h"
using namespace std;

const string FILE_NAME = "all-contacts.in";
const string TEST_FILE_NAME = "test.txt";

int main()
{
	ContactManager main;
	main.loadFromFile(TEST_FILE_NAME);
	cout << main << endl << endl;
	main.add("m", "60");
	main.add("h", "80");
	cout << main << endl << endl;
	main.add("m", "60");
	cout << main << endl << endl;

	ContactManager main2;
	main2.loadFromFile(FILE_NAME);
	cout << main2 << endl;
	system("Pause");
	return 0;
}