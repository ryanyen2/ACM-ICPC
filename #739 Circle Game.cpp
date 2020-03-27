#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <iterator>
#include <cstdio>
#include <stack>
#include <functional>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) {
		os << v[i].data << " " ;
		cout << v[i].index << " " <<endl;
	}
	return os;
}
typedef long long int ll;

struct str {
	int index;
	int data;
};

int main() {
	int n, op_n, d, op1, op2, op3;
	cin >> n;
	str* temp = new str;
	vector <str> vc;
	_for(i, 0, n) {
		cin >> d;
		temp->data = d;
		temp->index = i;
		vc.push_back(*temp);
	}
	cin >> op_n;
	int curr_index = 0;
	_for(i, 0, op_n) {
		str* temp = new str;
		cin >> op1;
		switch (op1) {
		case 1:
			cin >> op2 >> op3;
			curr_index = (curr_index + op2 - 1) % n;
			temp->data = op3;
			temp->index = curr_index + 1;
			vc.insert(vc.begin() + curr_index + 1, *temp);
			curr_index++; n++;
			_for(j, curr_index + 1, n)
				vc[j].index++;
			break;
		case 2: 
			cin >> op2;
			curr_index = (curr_index + op2 - 1) % n;
			n--;
			_for(j, curr_index, n) {
				vc[j] = vc[j + 1];
				vc[j].index--;
			}
			break;
		case 3: 
			cin >> op2;
			curr_index = (curr_index + op2 - 1) % n;
			cout << vc[curr_index].data << endl;
			break;
		}

		//cout << "curr " << curr_index << endl;
	}

	return 0;
}
