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

// flip row
vector<vector<char>> flip_row(int col, int location, vector<vector<char>> grid){

	_for(j, 0, col) {
		if (grid[location][j] == '0') grid[location][j] = '1';
		else grid[location][j] = '0';
	}
	return grid;
}
// flip column
vector<vector<char>> flip_col(int row, int location, vector<vector<char>> grid) {
	_for(j, 0, row) {
		if (grid[j][location] == '0') grid[j][location] = '1';
		else grid[j][location] = '0';
	}
	return grid;
}

// use an array to check whether 1>0 -> dnt need flip
// if 1 == 0 -> flip if the head is 0
vector<int>renew_row_sum(int row, vector<int>row_sum, vector<vector<char>>grid) {
	_for(i, 0, row) {
		int zero_cnt = count(grid[i].begin(), grid[i].end(), '0');
		int one_cnt =  count(grid[i].begin(), grid[i].end(), '1');
		row_sum.push_back(one_cnt - zero_cnt);
	}
	//cout << "row_sum: " << row_sum << endl;
	return row_sum;
}
vector<int>renew_col_sum(int row, int col, vector<int>col_sum, vector<vector<char>>grid) {

	_for(i, 0, col) {
		int col_amount = 0;
		_for(j, 0, row) {
			if (grid[j][i] == '0') col_amount++;
		}
		col_sum.push_back((row - col_amount) - col_amount);		// >0 -> 1's amount > 0
	}
	//cout << "col_sum: " << col_sum << endl;
	return col_sum;
}

bool terminate(int row,int col, vector<int>row_sum, vector<int>col_sum) {
	_for(i, 0, row)
		if (row_sum[i] < 0) return false;
	_for(i, 0, col)
		if (col_sum[i] < 0) return false;
	return true;

}
bool first(int row, int col, vector<int>row_sum, vector<int> col_sum, vector<vector<char>>grid) {
	int rs = 0, cs = 0;
	_for(i, 0, row) if (row_sum[i] < rs) rs = row_sum[i];
	_for(i, 0, col) if (col_sum[i] < cs) cs = col_sum[i];
	return (rs < cs);	// true = row first
}

int main() {

	int row, col;
	while (cin >> row >> col) {
		vector <vector<char>> grid(row, vector<char>(col));
		int ans = 0;
		// get user input
		_for(i, 0, row) {
			_for(j, 0, col)
				cin >> grid[i][j];
		}
		// renew the row and col sum (<0 -> flip)
		vector <int> row_sum;
		vector<int> col_sum;
		row_sum = renew_row_sum(row, row_sum, grid);
		col_sum = renew_col_sum(row, col, col_sum, grid);
		do {
			if (first(row, col, row_sum, col_sum, grid)) goto row;
			else goto col;
		row:_for(i, 0, row) {
				if (row_sum[i] < 0 || (row_sum[i] == 0 && grid[i][0] == '0'))
					grid = flip_row(col, i, grid);
			
			}
		col:_for(i, 0, col) {
				if (col_sum[i] < 0 || (col_sum[i] == 0 && grid[0][i] == '0'))
					grid = flip_col(row, i, grid);
			}
			row_sum.clear();
			col_sum.clear();
			row_sum = renew_row_sum(row, row_sum, grid);
			col_sum = renew_col_sum(row, col, col_sum, grid);

			//_for(i, 0, row) cout << grid[i] << endl;
			//cout << "----------------------" << endl;
		} while ((terminate(row, col, row_sum, col_sum)) == false);


		// count answer
		_for(i, 0, row)
			ans += count(grid[i].begin(), grid[i].end(), '1');
		cout << ans << endl;
		
		// _for(i, 0, row) cout << grid[i] << endl;		print grid
	}
	return 0;
}
