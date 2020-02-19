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

int count_nodes(vector< vector<char> >& grid, int x, int y, int len) {
	if (len == '0') return 1;
	bool same = true;
	for (int i = x; i < x + pow(2, len); i++) {
		for (int j = y; j < y + pow(2, len); j++) {
			if (grid[i][j] != grid[x][y]) {
				same = false;
				goto outside;
			}
		}
	}
outside:
	if (same) return 1;
	else {
		return 1 + count_nodes(grid, x, y, len - 1)
			+ count_nodes(grid, x + pow(2, len - 1), y, len - 1)
			+ count_nodes(grid, x, y + pow(2, len - 1), len - 1)
			+ count_nodes(grid, x + pow(2, len - 1), y + pow(2, len - 1), len - 1);
	}
}

int main() {
	int k;
	string line;

	while (cin >> k) {
		
		int len = pow(2, k);
		vector <vector<char>> grid(len, vector<char>(len));
		// get user input
		_for(i, 0,len) {
			_for(j, 0, len)
				cin >> grid[i][j];
		}

		cout << count_nodes(grid, 0, 0, k) << endl;
	}
	return 0;
}
