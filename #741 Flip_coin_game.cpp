#include <iostream>
#include <string>
using namespace std;

int pow(int base, int exp);

void reset(int** resetee, int** reseter, int rows, int columns);

int numOfBiDigits(int num);

int getIthBiDigit(int num, int i);

void flipJthColumn(int j, int** board, int rows) {
	for (int i = 0; i < rows; i++) {
		board[i][j] == 0 ? board[i][j] = 1 : board[i][j] = 0;
	}
}

void flipIthRow(int i, int** board, int columns) {
	for (int j = 0; j < columns; j++) {
		board[i][j] == 0 ? board[i][j] = 1 : board[i][j] = 0;
	}
}

void flipColumns(int** board, int rows, int columns) {
	for (int i = 1; i < rows; i++) {
		int counter0 = 0, counter1 = 0;
		for (int j = 0; j < columns; j++) {
			board[i][j] == 0 ? counter0++ : counter1++;
		}
		if (counter0 > counter1) flipIthRow(i, board, columns);
	}
}

int counts1(int** board, int rows, int columns) {
	
	int ans = 0;
	for (int j = 0; j < columns; j++) {
		if (board[0][j] == 1) ans++;
	}
	for (int i = 1; i < rows; i++) {
		int counter0 = 0, counter1 = 0;
		for (int j = 0; j < columns; j++) {
			board[i][j] == 0 ? counter0++ : counter1++;
		}
		counter1 > counter0 ? ans += counter1 : ans += counter0;
	}
	return ans;
}

int main() {
	int row, col, max_cnt;
	while (cin >> row >> col) {
		max_cnt = 0;
		int counter = pow(2, col) - 1;

		
		int** grid = new int* [row];
		for (int i = 0; i < row; i++) {
			grid[i] = new int[col];
		}

		string line;
		for (int i = 0; i < row; i++) {
			cin >> line;
			for (int j = 0; j < line.length(); j++) {
				grid[i][j] = int(line[j] - 48);
			}
		}

		
		int** temp = new int* [row];
		for (int i = 0; i < row; i++) {
			temp[i] = new int[col];
			for (int j = 0; j < col; j++) {
				temp[i][j] = grid[i][j];
			}
		}

		while (counter >= 0) {

			for (int j = 0; j < col; j++) {
				if (getIthBiDigit(counter, col - j - 1) == 1) {
					flipJthColumn(j, grid, row);
				}
			}

			//flipColumns(board, rows, columns);
			if (counts1(grid, row, col) > max_cnt) max_cnt = counts1(grid, row, col);

			reset(grid, temp, row, col);
			counter--;
		}

		cout << max_cnt << endl;
	}

}

void reset(int** resetee, int** reseter, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			resetee[i][j] = reseter[i][j];
		}
	}
}

int getIthBiDigit(int num, int i) {
	// return (num % pow(2, numOfBiDigits(num) - i) / pow(2, numOfBiDigits(num) - i - 1));
	return num % pow(2, i + 1) / pow(2, i);
}

int pow(int base, int exp) {
	int ans = 1;
	for (int i = 0; i < exp; i++) {
		ans *= base;
	}
	return ans;
}

int numOfBiDigits(int num) {
	int ans = 0;
	while (num > 0) {
		num /= 2;
		ans++;
	}
	return ans;
}
