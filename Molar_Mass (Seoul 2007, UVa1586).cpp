#include <iostream>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)

int main() {

	char ip[1024];
	gets_s(ip);
	double sum = 0, w[256];
	int cnt = 0, n = strlen(ip);
	w['C'] = 12.01, w['H'] = 1.008, w['O'] = 16.00, w['N'] = 14.01;

	_for(i, 0, n) {
		char c = ip[i];
		if (isupper(c)) {
			if (isdigit(ip[i + 1])) {
				int cp1 = ip[i + 1] - '0';
				int p = 1;
				while (isdigit(ip[i + 1 + p])) {
					cp1 *= 10;
					cp1 += ip[i + p] - '0';
					p++;
				}
				sum += cp1 * w[c];
			}
			else sum += w[c];
		}
	}

	cout << sum;

	

	return 0;
}

