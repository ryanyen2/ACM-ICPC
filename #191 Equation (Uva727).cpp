#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <cstdio>
#include <stack>
using namespace std;
#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) os << v[i] << " ";
	return os;
}

char optype[5] = { '(', '+', '-', '*', '/'};
int prio_op[5] = { 0, 1, 1, 2, 2 };
#define operator(ch) (ch=='+') || (ch=='-') || (ch=='*') || (ch=='/') ? 1: 0
#define operands(ch) ((ch) >= '0' && (ch) <= '9') ? 1: 0
int priority(char c) {
	_for(i, 0, 5)
		if (c == optype[i])
			return prio_op[i];
	return -1;
}
int main() {
	int test_cases;
	string s; char c;
	cin >> test_cases;
	_for(i, 0, test_cases+2) {
		stack<char>op;
		while (getline(cin, s) && !s.empty()) {
			c = s[0];
			if (operands(c)) cout << c;
			else if (c == optype[0]) op.push(c);
			else if (c == ')') {
				while (!op.empty()) {
					if (op.top() == '(') {
						op.pop();  break;
					}
					cout << op.top();
					op.pop();
				}
			}
			else if (operator(c)) {
				while (!op.empty()) {
					char top = op.top();
					if (priority(c) <= priority(top)) {
						cout << op.top();
						op.pop();
					}
					else break;
				}
				op.push(c);
			}
		}
		while (!op.empty()) {
			cout << op.top();
			op.pop();
		}
		if (i > 1){
			if (i != test_cases + 1)
				printf("\n\n");
			else printf("\n");
		}
	}

	return 0;
}
