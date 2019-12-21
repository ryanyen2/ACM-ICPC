#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)

int main() {

	vector <int> w; int wi, hi;
	_for(i, 0, 6) {
		cin >> wi >> hi;
		w.push_back(wi), w.push_back(hi);
	}
	
	sort(w.begin(), w.end());
	w.resize(distance(w.begin(), unique(w.begin(), w.end())));
	if (w.size() == 3) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" <<endl;

	
	return 0;
}
