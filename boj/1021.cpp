#include <iostream>
using namespace std;
class node {
public:
	node *prev = nullptr;
	int value;
	node *next = nullptr;
	node(int value) :value(value) {}	
};
class circular_queue {
public:
	node *front=nullptr;
	node *rear=nullptr;
	node *current;
	int size;
	circular_queue(int size) :size(size) {
		front = rear = new node(1);
		current = front;
		for (int a = 2; a <= size; a++) {
			node *newNode = new node(a);
			newNode->prev = rear;
			newNode->next = front;
			front->prev = rear->next = newNode;
			rear = newNode;
		}
	}

	int delete_current_node() {
		size--;
		node *deleteNode = current;
		if (size == 0) {
			delete deleteNode;
			front = rear = current = nullptr;
			return -1;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
		int val = current->value;
		current = current->next;
		delete deleteNode;
		return val;
		if (size == 0) {
			front = rear = current = nullptr;
		}
	}

	int target_dist_cw(int target) {
		node *cur = current;
		for (int a = 0; a < size; a++) {
			if (cur->value == target) {
				return a;
			}
			cur = cur->next;
		}
		return 0;
	}
	int target_dist_ccw(int target) {
		node *cur = current;
		for (int a = 0; a < size; a++) {
			if (cur->value == target) {
				return a;
			}
			cur = cur->prev;
		}
		return 0;
	}

	int move(int target) {
		int cw = target_dist_cw(target);
		int ccw = target_dist_ccw(target);
		if (size == 0)
			return 0;
		for (int a = 0; a < cw; a++) {
			current = current->next;
		}
		return cw < ccw ? cw : ccw;
	}

};

int min(int a, int b) {
	return a > b ? b : a;
}

int main(void) {
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	circular_queue q(n);
	for (int a = 0; a < m; a++) {
		int t;
		cin >> t;
		cnt += q.move(t);
		q.delete_current_node();
	}
	cout << cnt << endl;
	return 0;
}