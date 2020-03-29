
#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iterator>
#include <cstdio>
#include <stack>
#include <queue>
#include <list>
using namespace std;
#define _for(i, a, b) for (int i = (a); i<(b); ++i)

typedef struct Number {
	int index;
	int val;
}*N;

Number get_max(int k, list<Number> S) {
	Number temp_max = S.front();
	auto it = S.begin();
	for (int i = 0; i < k && it != S.end(); i++) {
		if (it->val > temp_max.val) temp_max = *it;
		advance(it, 1);
	}
	return temp_max;
}

void printAns(int k, list<Number> &S) {
	N maxNum = new Number;
	maxNum->index = S.front().index;
	maxNum->val = 0;
	int it;
	if (k < S.size()) it = k;
	else it = S.size();
	*maxNum = get_max(k, S);
	_for(i, 0, it) {
		if (S.front().index != maxNum->index) {
			S.front().val--;
			S.push_back(S.front());
			S.pop_front();
		}
		else {
			if (S.size() == 1) printf("%d", S.front().index);
			else printf("%d ", S.front().index);
			S.pop_front();
		}
	}

}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, k, num;
		list<Number> S;
		cin >> n >> k;
		_for(j, 0, n) {
			cin >> num;
			N temp = new Number;
			temp->index = j + 1;
			temp->val = num;
			S.push_back(*temp);
		}
		_for(j, 0, n)
			printAns(k, S);

		cout << endl;
	}
}
