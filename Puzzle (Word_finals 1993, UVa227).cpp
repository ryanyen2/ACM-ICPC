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
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) os << v[i] << " ";
	return os;
}

string instruction;
string strs[5];
void get_input(){
	// get origin matrics
	_for(i, 0, 5) {
		getline(cin, strs[i]);
	}
	// get_instruct
	getline(cin, instruction);
}

int obx = 0, oby = 0;
void find_blank() {
	_for(x, 0, 5) {
		_for(y, 0, 5) {
			if (strs[x][y] == ' ') {
				obx = x;
				oby = y;
				break;
			}
		}
	}
}

int main() {
	
	get_input();
	
	_for(i, 0, instruction.size()) {
		find_blank();
		if (instruction[i] == 'A') {
			strs[obx][oby] = strs[obx - 1][oby];
			strs[obx - 1][oby] = ' ';
		}
		else if (instruction[i] == 'B') {
			strs[obx][oby] = strs[obx + 1][oby];
			strs[obx + 1][oby] = ' ';
		}
		else if (instruction[i] == 'L') {
			strs[obx][oby] = strs[obx][oby - 1];
			strs[obx][oby - 1] = ' ';
		}
		else if (instruction[i] == 'R') {
			strs[obx][oby] = strs[obx][oby + 1];
			strs[obx][oby + 1] = ' ';
		}
		else break;
	}

	_for(x, 0, 5) {
		_for(y, 0, 5) {
			cout << strs[x][y] << ' ';
		}
		cout << endl;
	}

	return 0;
}

