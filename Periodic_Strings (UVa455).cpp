#include <iostream>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)
int main() {
	
	string ip;
	getline(cin, ip);
	char ans;
	_for(i, 1, ip.size()) {
		char first_char = ip[0];
		if (ip[i] == first_char) {
			cout << i;
			break;
		}
	}
	

	return 0;
}

