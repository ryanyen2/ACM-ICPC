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
#include <map>
using namespace std;
#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) os << v[i] << " ";
	return os;
}
void BFS(map<string, string> prev, string v) {
	if (prev[v] != v) BFS(prev, prev[v]);
	printf("%c", v[0]);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		map<string, vector<string>>roadMap;
		int rds, qs;
		cin >> rds >> qs;
		// set up
		_for(i, 0, rds) {
			string A, B;
			cin >> A >> B;
			roadMap[A].push_back(B);
			roadMap[B].push_back(A);
		}

		// inquiry
		_for(i, 0, qs) {
			string qA, qB;
			queue<string>q;
			map<string, string> prev;
			cin >> qA >> qB;
			//setup first
			q.push(qA);
			prev[qA] = qA;
			while (!q.empty() && !prev.count(qB)) {
				string fro = q.front();
				q.pop();
				_for(j, 0, roadMap[fro].size()) {
					string v = roadMap[fro][j];
					if (!prev.count(v)) {
						q.push(v);
						prev[v] = fro;
					}
				}
			}
			BFS(prev, qB); putchar('\n');
		}
		if (T) putchar('\n');
	}
}
