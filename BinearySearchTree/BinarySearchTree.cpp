#include <iostream>;

using namespace std;

class Node {
public:
	int data;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int data) {
		this->data = data;
	}
};

class BinarySearchTree {
public:
	Node* root = nullptr;
	void add(int data) {
		//if no root, your data is now the root
		if (root == nullptr) {
			root = new Node(data);
		}
		//put the data where it belongs
		else {
			Node* current = root;
			bool sorted = false;
			while (!sorted) {
				//move left if value is less than
				if (data < current->data) {
					if (current->left == nullptr) {
						current->left = new Node(data);
						sorted = true;
					}
					else {
						current = current->left;
					}
				}
				//move right if value is greater than
				else if (data > current->data) {
					if (current->right == nullptr) {
						current->right = new Node(data);
						sorted = true;
					}
					else {
						current = current->right;
					}
				}
				else if (data == current->data) {
					cout << data << " already in tree" << endl;
					sorted = true;
				}
			}
		}
	}
	//used to send root to in-order print
	void print() {
		inorder(root);
		cout << endl;
	}
	void inorder(Node* current) {
		//left
		if (current->left != nullptr) {
			inorder(current->left);
		}
		//visit
		cout << current->data << " ";
		//right
		if (current->right != nullptr) {
			inorder(current->right);
		}
	}
};

int main() {
	BinarySearchTree tree;
	int data = 0;
	while (data != -1) {
		cout << "input value to tree: ";
		cin >> data;

		tree.add(data);
		tree.print();
	}

	return 0;
}