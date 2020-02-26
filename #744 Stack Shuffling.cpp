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

struct Number {
	int index;
	int data;
};

bool validForI(int i, Number* b, int size) {
	Number p = b[i], q;
	for (int j = i; j < size; j++) {
		if (b[j].index > b[i].index) {
			q = b[j];
			if (q.index < p.index) return false;
			p = q;
		}
	}
	return true;
}

int main() {
	int test_cases, n, op_time, data;
	cin >> test_cases;
	_for(i, 0, test_cases) {
		cin >> n;
		Number* a = new Number[n];
		Number* b = new Number[n];
		_for(j, 0, n) {
			cin >> a[j].data;
			a[j].index = j;
		}
		cin >> op_time;
		// for each target cases
		_for(j, 0, op_time) {
			bool valid = true;
			_for(k, 0, n) {
				cin >> data;
				//b[k] = num;
				_for(l, 0, n) {
					if (a[l].data == data) {
						b[k] = a[l];
						break;
					}
				}
			}
			_for(k, 0, n) {
				if (!validForI(k, b, n)) {
					valid = false;
					break;
				}
			}
			if (valid) printf("Aye\n");
			else printf("Impossible\n");
		}
	}
}
