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
#include <cassert>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) os << v[i] << " ";
	return os;
}
char a[100], b[100];
int dp[100][100], arg[100][100];
void print(int i, int j) {
	if (i == 0 && j == 0)    return;
	if (arg[i][j] == 1)
		print(i - 1, j - 1);
	else if (arg[i][j] == 2) {
		print(i-1, j);
		printf("D%c%02d", a[i - 1], j + 1);
	}
	else if (arg[i][j] == 3) {
		print(i, j - 1);
		printf("I%c%02d", b[j - 1], j);
	}
	else {
		print(i - 1, j - 1);
		printf("C%c%02d", b[j - 1], j);
	}

}
int main() {
	int i, j;
	while (cin >> a >> b) {
		memset(dp, 63, sizeof(dp));
		int la = strlen(a), lb = strlen(b);
		dp[0][0] = 0;
		for (i = 0; i <= la; i++) {
			for (j = 0; j <= lb; j++) {
				if (a[i] == b[j] && dp[i + 1][j + 1] > dp[i][j]) // copy
					dp[i + 1][j + 1] = dp[i][j], arg[i + 1][j + 1] = 1;
				if (dp[i + 1][j] > dp[i][j] + 1) // del
					dp[i + 1][j] = dp[i][j] + 1, arg[i + 1][j] = 2;
				if (dp[i][j + 1] > dp[i][j] + 1) // ins
					dp[i][j + 1] = dp[i][j] + 1, arg[i][j + 1] = 3;
				if (dp[i + 1][j + 1] > dp[i][j] + 1) // change
					dp[i + 1][j + 1] = dp[i][j] + 1, arg[i + 1][j + 1] = 4;

				_rep(k, 0, la) {
					_rep(t, 0, lb) {
						cout << dp[k][t] << ' ';
					}
					cout << endl;
				}
				cout << "----dp----" << endl;
				_rep(k, 0, la) {
					_rep(t, 0, lb) {
						cout << arg[k][t] << ' ';
					}
					cout << endl;
				}
				cout << "----arg----" << endl;
			}

		}
		print(la, lb);
		puts("E");
	}
	return 0;
}
