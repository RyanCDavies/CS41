#include <iostream>

using namespace std;

class Node {
public:
	int num;
	Node* next;
	//constructor
	Node(int num) {
		this->num = num;
		this->next = nullptr;
	}
};

class Queue {
public:
	Node* front;
	Node* end;
	int count;

	void enqueue(int num) {
		Node* NewNode = new Node(num);
		if (front == nullptr) {
			front = NewNode;
		}
		else {
			Node* current = front;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = NewNode;
		}
		end = NewNode;
		count++;
	}
	int dequeue() {
		if (count == 0) {
			cout << "Error: queue empty" << endl;
			return -1;
		}
		Node* temp = front;
		front = front->next;
		cout << "Number dequeued: " << temp->num << endl;
		int num = temp->num;
		delete temp;
		count--;
		return num;
	}
	bool IsEmpty() {
		if (count == 0) {
			return true;
		}
		return false;
	}
	//constructor
	Queue() {
		front = nullptr;
		end = nullptr;
		count = 0;
	}
};

int main() {
	int num = 0;
	char choice = 'y';
	Queue q;
	while (choice == 'y') {
		cout << "queue? (y/n) ";
		cin >> choice;
		if (choice == 'y') {
			cout << "Enter num: ";
			cin >> num;
			q.enqueue(num);
		}
		cout << "dequeue? (y/n) ";
		cin >> choice;
		if (choice == 'y') {
			q.dequeue();
		}
		cout << "queue is empty: " << boolalpha << q.IsEmpty() << endl;
		cout << "continue? (y/n) ";
		cin >> choice;
	}

	return 0;
}