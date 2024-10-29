#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	string name;
	int weight;

	Node* nameNext = nullptr;
	Node* weightNext = nullptr;

	Node(string name, int weight) {
		this->name = name;
		this->weight = weight;
	}
};

class NamesWeights {
	Node* nameHead = nullptr;
	Node* weightHead = nullptr;


	void makeNode(string name, int weight) {
		Node* person = new Node(name, weight);
		
	}
	void sortNames() {

	}
	void sortWeights(Node* person) {
		Node* temp = weightHead;
		if (weightHead != nullptr) {
			while (temp != nullptr) {
				if (person->weight < temp->weight) {
					person->weightNext = temp;
				}
				temp = temp->weightNext;
			}
		}
	}
	void printNames() {
		if (nameHead != nullptr) {
			Node* temp = nameHead;
			while (temp != nullptr) {
				cout << temp->name;
				temp = temp->nameNext;
			}
		}
		else {
			cout << "Error: no values in list";
		}
	}
	void printWeights() {
		if (weightHead != nullptr) {
			Node* temp = weightHead;
			while (temp != nullptr) {
				cout << temp->weight;
				temp = temp->weightNext;
			}
		}
		else {
			cout << "Error: no values in list";
		}
	}
};

int main() {



	return 0;
}