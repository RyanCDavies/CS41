#include <iostream>

using namespace std;

class Vertex {
public:
	string key;
	Vertex* next;
	int weight;

	//tentative values
	int tweight;
	Vertex* tsource;

	Vertex(string key, int weight = 0, Vertex* next = nullptr) {
		this->key = key;
		this->weight = weight;
		this->next = next;
	}
};

class Graph {
public:
	Vertex* home;

	Graph() {
		home = new Vertex("home");
	}

	void addVertex(string key) {
		Vertex* current = home;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Vertex(key);
	}
};

int main() {


	return 0;
}