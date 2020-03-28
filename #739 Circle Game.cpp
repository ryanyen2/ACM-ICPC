#include <iostream>
#include<algorithm>
using namespace std;
#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)

class Node {
public:
	int data;
	Node* next;
	Node(int d) { data = d; }
};

class List {
public:
	Node* first;
	List(Node* n) { first = n; }
};

int main() {
	int n, data;
	cin >> n >> data;
	Node* p, * current = NULL, *ref;
	p = new Node(data);
	ref = p;
	List myList(p);
	for (int i = 1; i < n; i++) {
		cin >> data;
		current = new Node(data);
		p->next = current;
		p = current;
	}
	current->next = ref;
	int op;
	int num_of_op;
	cin >> num_of_op;
	for (int i = 0; i < num_of_op; i++) {
		cin >> op;
		switch (op) {
		case 1:
			int j, d;
			cin >> j >> d;
			current = ref;
			_for(k, 0, j) {
				p = current;
				current = current->next;
			}
			p->next = new Node(d);
			ref = p->next;
			p->next->next = current;
			break;
		case 2:
			cin >> j;
			if (j == 1) {
				p = ref->next;
				while (p->next != ref) p = p->next;
				current = ref->next;
				p->next = current;
				ref = current;
			}
			else {
				p = ref;
				current = ref->next->next;
				_for(k, 0, j-2) {
					current = current->next;
					p = p->next;
				}
				p->next = current;
				ref = current;
			}
			break;
		case 3:
			cin >> j;
			p = ref;
			_for(k, 0, j-1) {
				p = p->next;
			}
			cout << p->data << endl;
			ref = p;
		}
	}
	return 0;
}
