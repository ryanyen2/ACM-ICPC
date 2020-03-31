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
		os << v[i] << " ";
	}
	cout << endl;
	return os;
}
typedef long long int ll;
int cnt = 0;
int mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int middle = (l + r) / 2;
		mergeSort(arr, l, middle);
		mergeSort(arr, middle + 1, r);
		int* b = new int[r + 1];
		_rep(i, 1, middle)
			b[i] = arr[i];
		_rep(j, middle + 1, r)
			b[r + (middle - j + 1)] = arr[j];
		for (int i = l, j = r, k = l; k <= r; k++) {
			if (b[i] <= b[j]) {
				arr[k] = b[i++];
			}
			else {
				arr[k] = b[j--];
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {

	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		int *arr = new int[n];
		cnt = 0;
		_for(i, 0, n) cin >> arr[i];
		
		cout << mergeSort(arr, 0, n-1) <<endl;
	}

}
