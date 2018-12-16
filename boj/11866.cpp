#include <iostream>
using namespace std;
class node {
public:
	node *prev=nullptr;
	int num;
	node *next=nullptr;
	node(int num) :num(num) {}
};
class circular_queue {
public:
	node *front=nullptr, *rear=nullptr;
	node *current;
	int size;
	int step;
	circular_queue(int size, int step): size(size), step(step) {
		if (size) {
			front = rear = new node(1);
			front->next = rear;
			front->prev = rear;
			rear->next = front;
			rear->prev = front;
		}
		for (int a = 2; a <= size; a++) {
			node *newnode = new node(a);
			newnode->next = front;
			newnode->prev = rear;
			front->prev = newnode;
			rear->next = newnode;
			rear = newnode;
		}
		current = front;
	}

	int pop_step() {
		for (int a = 1; a < step; a++)
			current = current->next;
		int val = current->num;
		size--;
		node *delnode = current;
		current = current->next;
		delnode->prev->next = delnode->next;
		delnode->next->prev = delnode->prev;
		delete delnode;
		return val;
	}
	
};

int main(void) {
	int n, m;
	cin >> n >> m;
	circular_queue q(n,m);
	cout << "<";
	while (q.size) {
		cout << q.pop_step();
		if (q.size != 0)
			cout << ", ";
	}
	cout << ">" << endl;
	return 0;
}