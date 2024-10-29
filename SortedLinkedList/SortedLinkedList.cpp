#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data, Node* next){
		this->data = data;
		this->next = next;
	}
};

class SortedLinkedList {
public:
	int count = 0;
	Node* head = nullptr;
	void makeNode(int data) {
		count++;
		Node* newNode = new Node(data, nullptr);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	//print the linked list
	void print() {
		Node* temp = head;
		cout << "Sorted List: ";
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != nullptr);
		cout << endl;
	}
	//sorts the linked list in ascending order
	void sortList() {
		Node* first = head;
		int swap;
		//run until end of list
		while (first != nullptr) {
			Node* current = first->next;
			int smallest = first->data;
			//putting smallst value at front of unsorted list
			while (current != nullptr) {
				if (current->data < first->data) {
					swap = current->data;
					current->data = first->data;
					first->data = swap;
				}
				current = current->next;
			}
			//move to next node in list
			first = first->next;
		}
	}
};

int main() {
	int choice = 0;
	SortedLinkedList list;
	while (choice != -1) {
		//getting number from user
		cout << "Give a number to add to the list (-1 to quit)\n";
		cout << ">> ";
		cin >> choice;

		if (choice != -1) {
			list.makeNode(choice);
			list.sortList();
			list.print();
		}
	}

	return 0;
}