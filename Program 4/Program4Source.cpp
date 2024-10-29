#include <iostream>
#include <fstream>
#include <string>

#define TABLESIZE 10
#define MYFILE "CustomBORGSource.cpp"

using namespace std;

class Node {
public:
	string key;
	int scope;
	float value;
	Node* next;
	//constructor, initialize node
	Node(string key, int scope, float value = 0) {
		this->key = key;
		this->scope = scope;
		this->next = nullptr;
		this->value = value;
	}
};

class BORG {
public:
	//define file, current scope, and create hash table
	ifstream BORGFile;
	int scope;
	Node* table[TABLESIZE];

	//hash function
	int hash(string var) {
		int hash = 0;
		for (int i = 0; i < size(var); i++) {
			hash += var[i] * i;
		}
		return hash % TABLESIZE;
	}

	//make a new variable, add it to the hash table with chaining
	void makeVar(string varName, int value = 0) {
		Node* newNode = new Node(varName, scope, value);
		int index = hash(varName);
		if (table[index] == nullptr) {
			table[index] = newNode;
		}
		else {
			Node* current = table[index];
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
			return;
		}
	}
	//prints the variable name and value
	void printVar(string varName) {
		int index = hash(varName);
		Node* current = table[index];
		string temp;
		while (current != nullptr) {
			//check if keys match
			if (varName == current->key) {
				//need to see what's next here: if it's an expression, we need to run the math part and
				//assign it, as well as have the other output
				char op = ' ';
				BORGFile >> temp;
				if (temp == "+") {
					op = '+';
				}
				else if (temp == "-") {
					op = '-';
				}
				else if (temp == "*") {
					op = '*';
				}
				else if (temp == "/") {
					op = '/';
				}
				else if (temp == "^") {
					op = '^';
				}
				else if (temp == "%") {
					op = '%';
				}
				//not an operator if you get here, put it back and send the value
				else {
					BORGFile.putback(' ');
					for (int i = size(temp); i > 0; i--) {
						BORGFile.putback(temp[i - 1]);
					}
					cout << varName << " IS " << current->value << endl;
					return;
				}
				BORGFile >> temp;
				switch (op) {
				case '+':
					cout << varName << " + " << temp << " IS " << current->value + stoi(temp) << endl;
					return;
				case '-':
					cout << varName << " - " << temp << " IS " << current->value - stoi(temp) << endl;
					return;
				case '*':
					cout << varName << " * " << temp << " IS " << current->value * stoi(temp) << endl;
					return;
				case '/':
					cout << varName << " / " << temp << " IS " << current->value / stoi(temp) << endl;
					return;
				case '^':
					cout << varName << " ^ " << temp << " IS " << pow(current->value, stoi(temp)) << endl;
					return;
				case '%':
					int num = current->value;
					cout << varName << " % " << temp << " IS " << num % stoi(temp) << endl;
					return;
				}
			}
			//if they don't match, move down the chain
			current = current->next;
		}
		cout << varName << " IS UNDEFINED" << endl;
		return;
	}
	//operates on the key value, either temporary or permanent
	int operate() {
		int value1 = 0; //first possible value
		int value2 = 0; //second possible value, will not always be used
		char op = ' '; //operator for possible operation
		string temp;
		BORGFile >> temp;
		//checking if first value is a valid key, pull value if true
		Node* currentTemp = table[hash(temp)];
		while (currentTemp != nullptr) {
			if (currentTemp->key == temp) {
				break;
			}
			currentTemp = currentTemp->next;
		}
		if (currentTemp != nullptr) {
			value1 = currentTemp->value;
		}
		//not a key so must be an int
		else {
			value1 = stoi(temp);
		}

		BORGFile >> temp;
		if (temp == "+") {
			op = '+';
			}
		else if (temp == "-") {
			op = '-';
				}
		else if (temp == "*") {
			op = '*';
					}
		else if (temp == "/") {
			op = '/';
						}
		else if (temp == "^") {
			op = '^';
		}
		else if (temp == "%") {
			op = '%';
		}
		//not an operator if you get here, put it back
		else {
			BORGFile.putback(' ');
			for (int i = size(temp); i > 0; i--) {
				BORGFile.putback(temp[i-1]);
			}
		}
		//do the calculation if there's an operator
		if (op != ' ') {
			BORGFile >> temp;
			//check if next value is key
			currentTemp = table[hash(temp)];
			while (currentTemp != nullptr) {
				if (currentTemp->key == temp) {
					break;
				}
				currentTemp = currentTemp->next;
			}
			if (currentTemp != nullptr) {
				value2 = currentTemp->value;
			}
			//not a key so must be an int
			else {
				value2 = stoi(temp);
			}
			switch (op){
			case '+':
				return value1 + value2;
			case '-':
				return value1 - value2;
			case '*':
				return value1 * value2;
			case '/':
				return value1 / value2;
			case '^':
				return pow(value1, value2);
			case '%':
				return value1 % value2;
			}
		}
		//just return the value if there's no operation
		return value1;


	}
	//determines which command keyword has been inputted
	void choice(string varName) {
		//start scope operator
		if (varName == "START") {
			scope++;
			return;
		}
		//finish scope operator
		else if (varName == "FINISH") {
			scope--;
			//deleting variables out of scope
			for (int i = 0; i < TABLESIZE; i++) {
				Node* current = table[i];
				//need to check if current is out of scope, if yes, need to delete it and reform links
				//means we need to keep track of current's parent node (if applicable)
				//will have case where current is out of scope and current->next does not exist, just replace table[i] with nullptr
				if (current != nullptr && current->scope > scope && current->next == nullptr) {
					table[i] = nullptr;
					delete current;
					current = nullptr;
				}
				//if table[i] was in scope or had another value following it, we need to run down the list and remove vars out of scope
				while (current != nullptr) {	
					Node* parent = current;
					current = current->next;
					if (current != nullptr && current->scope > scope) {
						parent->next = current->next;
						delete current;
						current = parent;
					}
				}
			}
			return;
		}
		//check for COM, discard line if found
		else if (varName == "COM") {
			string trash;
			getline(BORGFile, trash);
			return;
		}
		//check for variable declaration
		else if (varName == "VAR") {
			string var;
			BORGFile >> var;
			string temp;
			BORGFile >> temp;
			int value = 0;
			if (temp == "=") {
				value = operate();
			}
			makeVar(var, value);

			return;
		}
		//check for print variable
		else if (varName == "PRINT") {
			string var;
			BORGFile >> var;
			printVar(var);
		}
		//check for declared variable
		//we need to first see if the variable exists, then look ahead for the type of operator: ++ and -- are just one thing,
		//= will be followed by a number, will need to also check after the number for an operator, which will always
		//be followed by another number
		else {
			int index = hash(varName);
			int value = 0;
			string temp;
			Node* current = table[index];
			//checking if the variable even exists
			while (current != nullptr) {
				if (current->key == varName) {
					BORGFile >> temp;
					if (temp == "++") {
						current->value = current->value + 1;
					}
					else if (temp == "--") {
						current->value = current->value - 1;
					}
					else if (temp == "=") {
						current->value = operate();
					}
					return;
				}
				current = current->next;
			}
			if (value == 0) {
				cout << varName << " IS UNDEFINED" << endl;
			}
			return;
		}
	}
	//constructor, open file and assign to variable
	BORG() {
		BORGFile.open(MYFILE);
		if (!BORGFile.is_open()) {
			cout << "Failed to open " << MYFILE << endl;
		}
		scope = 0;
		for (int i = 0; i < TABLESIZE; i++) {
			table[i] = nullptr;
		}
	}
	//deconstructor, close file
	~BORG() {
		BORGFile.close();
	}
};

int main() {
	BORG borg;
	string temp;
	char EOFTest;
	bool stop = false;

	while (!stop) {
		borg.BORGFile >> temp;
		borg.choice(temp);
		EOFTest = borg.BORGFile.peek();
		if (EOFTest == EOF) {
			stop = true;
		}
	}

	return 0;
}