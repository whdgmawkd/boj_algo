#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Queue {
private:
	class Node {
	public:
		Node* prev;
		int value;
		Node* next;
		Node(int value) : value(value) {
			prev = nullptr;
			next = nullptr;
		}
	};
	Node* head;
	Node* tail;
	int nodeCnt;
public:
	Queue() {
		nodeCnt = 0;
		head = nullptr;
		tail = nullptr;
	}

	void push(int value) {
		nodeCnt++;
		Node* newNode = new Node(value);
		if (head == nullptr || tail==nullptr) {
			head = tail = newNode;
			return;
		}
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}

	int pop() {
 		if (empty()) {
			return -1;
		}
		int value = tail->value;
		Node* delNode = tail;
		tail = tail->prev;
		if(tail!=nullptr)
			tail->next = nullptr;
		nodeCnt--;
		delete delNode;
		return value;
	}

	int size() {
		return nodeCnt;
	}

	int empty() {
		return size() == 0 ? 1 : 0;
	}

	int front() {
		return empty()?-1:head->value;
	}

	int back() {
		return empty()?-1:tail->value;
	}
};
int nodeCnt;

int main(void) {
	int n;
	cin >> n;
	Queue q = Queue();
	for (int a = 0; a < n; a++) {
		char cmd[6];
		int arg;
		scanf("%s", cmd);
		switch (cmd[1]) {
		case 'u':
			scanf("%d", &arg);
			q.push(arg);
			// push
			break;
		case 'o':
			printf("%d\n", q.pop());
			// pop
			break;
		case 'i':
			printf("%d\n", q.size());
			// size;
			break;
		case 'm':
			printf("%d\n", q.empty());
			// empty
			break;
		case 'r':
			printf("%d\n", q.back());
			// front
			break;
		case 'a':
			printf("%d\n", q.front());
			// back
			break;
		}
	}
}