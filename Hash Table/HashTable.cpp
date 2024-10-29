#include <iostream>

using namespace std;

class HashTable {
public:
	int array[27];
	
	//gets the hash from the value
	int Hash(int value) {
		return value % 27;
	}
	//add a new value to the hash table, returns -1 if hash is full
	int Add(int value) {
		int index = Hash(value);
		while (array[index] != -1) {
			index = (index + 1) % 27;
			if (index == (Hash(value) / 2)) {
				return -1;
			}
		}
		array[index] = value;
		return index;
	}
	//searches the hash table for the given value, returns -1 if not found
	int Find(int value) {
		int index = Hash(value);
		while (array[index] != -1) {
			//if you find it, stop and return the index
			if (value == array[index]) {
				return index;
			}
			index = index++;
			//if you wrap all the way around, it's not there
			if (index == (Hash(value) * 2)) {
				return -1;
			}
		}
		//if nothing there, it's not in the hash
		return -1;
	}
	//constructor, initialize array
	HashTable() {
		for (int i = 0; i < 27; i++) {
			array[i] = -1;
		}
	}
};

int main() {
	HashTable ht;
	
	int choice = 1;
	int num = 0;
	while (choice != 3) {
		//user choice menu
		cout << "Choose option below:\n1. Add\n2. Find\n3. Quit\n>> ";
		cin >> choice;
		switch (choice) {
		//user adds number
		case 1:
			cout << "Type number to add: ";
			cin >> num;
			num = ht.Add(num);
			if (num == -1) {
				cout << "Error: Table is full" << endl << endl;
			}
			else {
				cout << "Number added. Index is " << num << endl << endl;
			}
			break;
		//user finds number
		case 2:
			cout << "Type number to find: ";
			cin >> num;
			num = ht.Find(num);
			if (num == -1) {
				cout << "Error: Number not found" << endl << endl;
			}
			else {
				cout << "Number found. Index is " << num << endl << endl;
			}
			break;
		//exit case
		case 3:
			cout << "Exiting";
			break;
		//invalid user input
		default:
			cout << "Invalid input. Valid inputs are 1, 2, 3." << endl << endl;
		}
	}

	return 0;
}