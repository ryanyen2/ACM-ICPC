#include <iostream>
using namespace std;

#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
const int MAX_N = 100001;
int arr[MAX_N], mod_map[MAX_N];

int main() {
	
	int c, n;
	arr[0] = 0;
	while (cin >> c >> n && c) {
		// user input
		_rep(i, 1, n) {
			cin >> arr[i];
			mod_map[i] = -1;
		}
		int last_mod = 0, cur_mod = 0, index = -1, end_of_index = -1;

		_rep(i, 1 , n){
			cur_mod = (arr[i] + last_mod) % c;
			if (mod_map[cur_mod] != -1) {
				index = mod_map[cur_mod] + 1;
				end_of_index = i;
				break;
			}
			mod_map[cur_mod] = i;
			last_mod = cur_mod;
		}
		
		while (index <= end_of_index) printf("%d ", index++);
		putchar('\n');
	}
	return 0;
}
