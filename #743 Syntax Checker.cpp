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
struct Chrctr {
	char ch;
	int index;
};
int main() {
	string in;
	bool end;
	while (getline(cin, in)) {
		end = false;
		stack<Chrctr> myStack;
		for (int i = 0; i < in.length() && !end; i++) {
			// push open brackets into stack
			if (in[i] == '{' || in[i] == '[' || in[i] == '(') {
				Chrctr *temp = new Chrctr;
				temp->ch = in[i];
				temp->index = i;
				myStack.push(*temp);
			}
			else if (in[i] == '}' || in[i] == ']' || in[i] == ')') {
				if (!myStack.empty()) {
					switch (in[i]) {
					case '}':
						if (myStack.top().ch == '{') {
							myStack.pop();
						}
						else {
							std::cout << i + 1 << endl;
							end = true;
						}
						break;
					case ']':
						if (myStack.top().ch == '[') {
							myStack.pop();
						}
						else {
							std::cout << i + 1 << endl;
							end = true;
						}
						break;
					case ')':
						if (myStack.top().ch == '(') {
							myStack.pop();
						}
						else {
							std::cout << i + 1 << endl;
							end = true;
						}
						break;
					}
				}
				else {
					std::cout << i + 1 << endl;
					end = true;
				}

			}
		}
		if (myStack.empty() && !end) {
			std::cout << "Success\n";
		}
		else if (!end) {
			Chrctr* ans = new Chrctr;
			ans->ch = 0;
			ans->index = 0;
			while (!myStack.empty()) {
				*ans = myStack.top();
				myStack.pop();
			}
			std::cout << ans->index + 1<<endl;
		}
	}

	return 0;
}
