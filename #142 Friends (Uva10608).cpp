#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iterator>
#include <cstdio>
#include <stack>
#include <functional>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) {
		os << v[i] << " ";
	}
	cout << endl;
	return os;
}
typedef long long int ll;
#define MAX_N 10001
int group[MAX_N], num_size[MAX_N], n;

void union_set(int a, int b) {
	if (group[a] != group[b]) {
		int x = group[a], y = group[b];
		num_size[group[a]] = 0;
		for (int i = 1; i <= n; i++) {
			if (group[i] == x) {
				group[i] = y;
				num_size[group[b]]++;
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int m, a, b;
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			group[i] = i;
			num_size[i] = 1;
		}

		while (m--) {
			cin >> a >> b;
			union_set(a, b);
		}

		int max = -1;
		for (int i = 1; i <= n; i++) {
			if (num_size[i] > max) max = num_size[i];
		}

		printf("%d\n", max);
	}
	return 0;
}
