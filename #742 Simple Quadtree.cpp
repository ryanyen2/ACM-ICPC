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

int numOfNodes(vector< vector<int> >& board, int x, int y, int size) {
	if (size == 0) return 1;
	bool same = true;
	for (int i = x; i < x + pow(2, size); i++) {
		for (int j = y; j < y + pow(2, size); j++) {
			if (board[i][j] != board[x][y]) {
				same = false;
				goto outside;
			}
		}
	}
outside:
	if (same) return 1;
	else {
		return 1 + numOfNodes(board, x, y, size - 1)
			+ numOfNodes(board, x + pow(2, size - 1), y, size - 1)
			+ numOfNodes(board, x, y + pow(2, size - 1), size - 1)
			+ numOfNodes(board, x + pow(2, size - 1), y + pow(2, size - 1), size - 1);
	}
}

int main() {
	int k;
	string line;

	while (cin >> k) {
		
		vector< vector<int> > grid;
		for (int i = 0; i < pow(2, k); i++) {
			vector<int> temp;
			grid.push_back(temp);
		}

		for (int i = 0; i < grid.size(); i++) {
			cin >> line;
			for (int j = 0; j < line.length(); j++) {
				grid[i].push_back(int(line[j]) - 48);
			}
		}
		cout << numOfNodes(grid, 0, 0, k) << endl;
	}
}
