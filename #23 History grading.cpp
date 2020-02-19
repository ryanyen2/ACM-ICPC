#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		bool flag = false;
		int ref_list[22], t;
		// create reference list
		for (int i = 0; i < n; ++i) {
			cin >> t;
			ref_list[t-1] = i;
		}
		string a;
		while (cin >> a) {
			int target_list[22] = {}, lcs[25][25] = {};
			if (a == "-") {
				break;
				flag = true;
			}
			target_list[stoi(a)-1] = 0;
			for (int i = 1; i < n; ++i) {
				cin >> t;
				target_list[t-1] = i;
			}

			for (int i = n; i >= 0; i--)
				for (int j = n; j >= 0; j--) {
					if (i == n || j == n) {
						lcs[i][j] = 0;
						continue;
					}

					if (ref_list[i] == target_list[j]) lcs[i][j] = 1 + lcs[i + 1][j + 1];
					else lcs[i][j] = max(lcs[i][j + 1], lcs[i + 1][j]);
				}
			printf("%d\n", lcs[0][0]);
		}
		if (flag) break;
	}
	return 0;
}
