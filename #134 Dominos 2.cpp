#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) os << v[i] << " ";
	return os;
}

int main() {
	int cases, n, m, l, x, y, z;
	cin >> cases;
	_for(i, 0, cases) {
		vector<int>xlist, ylist, anslist;
		cin >> n >> m >> l;
		// x->y sequence
		_for(j, 0, m) {
			cin >> x >> y;
			xlist.push_back(x);
			ylist.push_back(y);
		}
		// by hand
		_for(j, 0, l) {
			cin >> z;
			if (find(anslist.begin(), anslist.end(), z) == anslist.end())
				anslist.push_back(z);
		}//cout << anslist;
		int cnt = 0;
	re:bool done = false;
		for (int k = cnt; k < anslist.size(); k++) {
			_for(t, 0, xlist.size()) {
				if (anslist[k] == xlist[t] && find(anslist.begin(), anslist.end(), ylist[t]) == anslist.end()) {
					done = true;
					anslist.push_back(ylist[t]);
					++cnt;
				}
			}
			if (!done) goto end;
		}goto re;

	end:cout << anslist.size() << endl;
	}
	return 0;
}
