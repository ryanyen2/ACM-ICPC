#include <iostream>
#include<algorithm>
using namespace std;
#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)

struct ListNode {
	int data;
	struct ListNode* next;
}*temp, *first;

void InsertAfter(int data, int location) {
	temp = new ListNode;
	temp->data = data;
	ListNode* current = first;
	_for(cnt, 1, location)
		current = current->next;
	temp->next = current->next;
	current->next = temp;
}

void DeleteItem(int location) {
	ListNode* current = first;
	temp = first;
	_for(cnt, 1, location-1) {
		current = temp;
		temp = temp->next;
	}
	if (temp == first) {		// !! if the tempt delete node is the first node
		first = temp->next;		// move first forward
		delete temp;
		temp = NULL;			// avoid unneccessary bug
	}
	else {
		current->next = temp->next;
		delete temp;
		temp = NULL;
	}
}

void Query(int location) {
	ListNode* current = first;
	_for(cnt, 1, location)
		current = current->next;
	cout << current->data << endl;
}

void PrintList() {
	temp = first;
	while (temp != NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}cout << '\n';
}

void Reverse(int p, int q) {
	ListNode* current = first;
	_for(i, 1, p) current = current->next;
	temp = first;
	_for (i, 1, q) temp = temp->next;
	ListNode* j = current;
	// reverse interval;
	while (current != temp->next) {
		while (j != temp->next) {
			swap(j->data, current->data);
			j = j->next;
		}
		current = current->next, j = current;
	}
}

int main() {
	
	int n, tag;
	cin >> n >> tag;
	// creat first element
	temp = new ListNode;
	temp->data = tag;
	temp->next = first;
	first = temp;

	_for(i, 1, n) {
		cin >> tag;
		// push back to the end of list
		temp = new ListNode;
		temp->data = tag;
		temp->next = NULL;
		ListNode* current = first;
		while (current->next != NULL) current = current->next;
		current->next = temp;
	}

	int op, op_amount;
	cin >> op_amount;
	_for(i, 0, op_amount) {
		cin >> op;
		switch(op) {
		case 1:
			int location, val;
			cin >> location >> val;
			InsertAfter(val, location);
			break;
		case 2:
			cin >> location;
			DeleteItem(location);
			break;
		case 3:
			int i, j;
			cin >> i >> j;
			Reverse(i, j);
			break;
		case 4:
			cin >> location;
			Query(location);
			break;
		}
		// PrintList();
	}
	

	return 0;
}
