#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 1, v.size()-1) os << v[i];
	return os;
}


int main() {

	int a, b, i = 0;
	vector <int> answer, remain;
	while (cin >> a >> b && (a)) {
		bool bre = true;
		answer.push_back(0);
		while (a && bre) {
			int q = (a * 10) / b;
			a = (a * 10) % b;	// remain
			answer.push_back(q);
			remain.push_back(a);

			for (i = 0; i < remain.size(); i++) 
				if (answer[i] == q) 
					if (remain[i-1] == a) 
						bre = false;
		
		if (a == 0) {
			_for(s, 1, answer.size()) cout << answer[s] <<endl;
			cout << "This expansion terminates." << endl;
		}
		else cout << '.' << answer << endl << "The last " << i - 1 << " digits repeat forever." << endl;
		answer.clear(); remain.clear();
	}
	
	return 0;
}
