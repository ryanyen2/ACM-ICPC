#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iterator>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) os << v[i] << " ";
	return os;
}

class Customer {
public:
	int arrT;
	int proT;
	int endT;
	int limit;
	void setup(int ar, int pr, int li) { arrT = ar; proT = pr; limit = li; }
};

int main() {
	int n, a, o, l, last, time;
	while (cin >> n) {
		queue<Customer> q;
		time = 0;
		last = 1;
		_for(i, 0, n) {
			cin >> a >> o >> l;
			Customer c;
			c.setup(a, o, l);
			time = c.arrT;
			// leave the queue
			while (!q.empty() && q.front().endT <= time) 
				q.pop();
			if (q.empty()) {
				q.push(c);
				q.back().endT = q.back().arrT + q.back().proT;	// extend timeline
				if (i == n-1) last = 1;
			}
			else {
				if (q.size() <= c.limit) {
					int temp = q.back().endT;
					q.push(c);
					q.back().endT = temp + q.back().proT;
					if (i==n-1) last = 1;
				}
				else
					if (i==n-1) last = 0;
			}
		}
		if (last) cout << q.back().endT - q.back().proT << endl;
		else cout << -1 << endl;
	}
	return 0;
}
