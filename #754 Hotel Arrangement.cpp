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
		os << v[i] <<endl;
	}
	return os;
}
typedef long long int ll;

bool isPossible(int arr[], int n, int k, int mid) {
	int cnt = 1, curr = arr[0];

	_for(i, 1, n) {
		if (arr[i] - curr >= mid) {
			cnt++;
			curr = arr[i];
			if (cnt == k) return true;
		}
	}
	return false;
}
int binarySearch(int n, int k, int arr[]) {
	int first, last, mid, ans;
	sort(arr, arr + n);
	first = 0;
	last = arr[n - 1];

	ans = 0;
	while (first <= last) {

		mid = (first + last) / 2;
		if (!isPossible(arr, n, k, mid)) last = mid - 1;
		else {
			ans = max(ans, mid);
			first = mid + 1;
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k, x;
		cin >> n >> k;
		int *arr = new int[n];
		_for(i, 0, n) cin >> arr[i];
		cout << binarySearch(n, k, arr)<<endl;
	}
	return 0;
}
