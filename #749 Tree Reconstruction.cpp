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

int preIndex = 0, t = 0;

int search(int arr[], int startIn, int endIn, int data) {
	int i = 0;
	for (i = startIn; i < endIn; i++)
		if (arr[i] == data)
			return i;
	return i;
}
void printPost(int arr[], int pre[], int inStrt, int inEnd) {
	if (inStrt > inEnd) return;
	int inID = search(arr, inStrt, inEnd, pre[preIndex++]);
	printPost(arr, pre, inStrt, inID - 1);
	printPost(arr, pre, inID + 1, inEnd);
	if (t-- != 1) cout << arr[inID] << " ";
	else cout << arr[inID];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		t = n;
		int *preArr = new int[n];
		int* inArr = new int[n];
		_for(i, 0, n) cin >> preArr[i];
		_for(i, 0, n) cin >> inArr[i];
		printPost(inArr, preArr, 0, n-1);
		preIndex = 0;
		putchar('\n');
	}
	return 0;
}
