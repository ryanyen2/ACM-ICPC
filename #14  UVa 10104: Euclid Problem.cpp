#include <iostream>
using namespace std;
int x, y;
int gcdext(int a, int b) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int g = gcdext(b, a % b);
	int z = x - (a / b) * y;
	x = y; y = z;
	return g;
}
int main() {
	int a, b;
	while (cin >> a >> b) {
		int g = gcdext(a, b);
		cout << x << " " << y << " " << g << endl;
	}
}
