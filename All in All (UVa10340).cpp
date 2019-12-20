#include <iostream>
#include <string>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)

string find_same(string s, string t) {
	bool find = false;
	_for (i, 0, s.size()) {
		static int x = 0;
		for (int j = x; j < t.size(); j++) {
			if (s[i] == t[j]) {
				find = true;
				x = j + 1;
				break;
			}
		}
	}
	if (find == false) return "No";
	else return "Yes";
}

int main() {

	string s, t;
	while (cin >> s >> t)
		cout << find_same(s, t) <<endl;
	
	return 0;
}
