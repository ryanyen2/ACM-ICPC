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




// another solution
struct rect {
	int w;
	int h;
};
bool sort_rect(const rect& r1, const rect& r2) {
	if (r1.w != r2.w) return r1.w > r2.w;
	else return r1.h > r2.h;
}

int main() {

	rect rects[6];
	while (cin >> rects[0].w >> rects[0].w) {
		if (rects[0].w < rects[0].h) swap(rects[0].w, rects[0].h);
		_for(i, 1, 6) {
			cin >> rects[i].w >> rects[i].h;
			if (rects[i].w < rects[i].h) swap(rects[i].w, rects[i].h);
		}

		sort(rects, rects+6, sort_rect);
		if (rects[0].w != rects[1].w || rects[0].h != rects[1].h ||
			rects[2].w != rects[3].w || rects[2].h != rects[3].h ||
			rects[4].w != rects[5].w || rects[4].h != rects[5].h
			) printf("IMPOSSIBLE\n");
		else if (rects[0].w != rects[2].w || rects[0].h != rects[4].w || rects[2].h != rects[4].h) printf("IMPOSSIBLE\n");
		else printf("POSSIBLE\n");
	}
	return 0;
}
