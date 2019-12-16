#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <set>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) os << v[i] << " ";
	return os;
}

int main() {
	int ans[10] = { 0 };
	vector <int> list;
	int n;
	cout << "Type in an integer: \n";
	cin >> n;
	
	_rep(i, 0, n) {
		if (i < 10) list.push_back(i);
		else {
			int x = i;
			while (x > 0) {
				list.push_back(x % 10);
				x /= 10;
			}
		}
	}
	_for(j, 0, 10) {
		_for(i, 0, list.size()) {
			if (list[i] == j) ans[j]++;
		}
	}
	
	_for(i, 0, 10) cout << ans[i] << " ";

	

	return 0;
}
