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
#define MAXN 1001
#define level 8

vector <int> tree[MAXN];
int depth[MAXN];
int parent[MAXN][level];

// count depth
void dfs(int cur, int prev) {
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (int i = 0; i < tree[cur].size(); i++) {
		if (tree[cur][i] != prev)
			dfs(tree[cur][i], cur);
	}
}

void precomputeSparseMatrix(int n) {
	_for(i, 1, level) {
		_rep(node, 1, n) {
			if (parent[node][i - 1] != -1)
				parent[node][i] = parent[parent[node][i - 1]][i - 1];
		}
	}
}
// lowest common ancestor
int lca(int u, int v) {
	if (depth[v] < depth[u]) swap(u, v);
	int diff = depth[v] - depth[u];
	
	// bring both nodes to sameheight
	for (int i = 0; i < level; i++)
		if ((diff >> i) & 1)
			v = parent[v][i];
	if (u == v) return u;

	// 2^i jumpping strategy to reach lca
	for (int i = level - 1; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

void addEdge(int a, int b) {
	tree[a].push_back(b);
	tree[b].push_back(a);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(parent, -1, sizeof(parent));
		int root, n, ch, pa, qa, qb;
		cin >> root >> n;
		_for(i, 1, n) {
			cin >> ch >> pa;
			addEdge(pa, ch);
		}
		dfs(root, 0);
		precomputeSparseMatrix(n);
		cin >> qa >> qb;
		printf("%d\n", lca(qa, qb));
	}
	return 0;
}
