#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iterator>
#include <cstdio>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) os << v[i] << " ";
	return os;
}


int main() {
	int test_case;
	cin >> test_case;
	int coins_amount, price, j;
	while (test_case--) {
		cin >> price >> coins_amount;
		int dp[20000] = {}, mx = 0, x;
		dp[0] = 1;
		_for(i, 0, coins_amount) {
			cin >> x;
			mx += x;
			if (mx > 20000)  mx = 19999;
			for (j = mx; j >= x; j--) {
				if ((dp[j] == 0 || dp[j] > dp[j - x] + 1) && dp[j-x]) {
					dp[j] = dp[j - x] + 1;
				}
			}
		}
		while (!dp[price])  price++;
		printf("%d %d\n", price, dp[price] - 1);
	}
	return 0;
}
