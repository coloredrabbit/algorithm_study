#include<cstdio>
#include<unordered_set>
#include<algorithm>
using namespace std;
const int MAX_N = 1e5 + 5;
int p[MAX_N], adj[MAX_N], vi[MAX_N];
unordered_set<int> c[MAX_N];
int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	p[u] = v;
	c[v].insert(c[u].begin(), c[u].end());
}
void dfs(int u) {
	vi[u] = 1;
	int& v = adj[u];
	if (!vi[v]) {
		dfs(v);
		merge(u, v);
	}
}
int main() {
	int N, K, a, b, cur[MAX_N], i;
	scanf("%d%d", &N, &K);
	for (i = 0; i < N; i++) {
		p[i] = cur[i] = i;
		c[i].insert(i);
	}
	for (i = 0; i < K; i++) {
		scanf("%d%d", &a, &b);
		a--, b--;
		c[cur[a]].insert(b);
		c[cur[b]].insert(a);
		swap(cur[a], cur[b]);
	}
	for (i = 0; i < N; i++) adj[cur[i]] = i;
	for (i = 0; i < N; i++) {
		if (!vi[i]) dfs(i);
		printf("%d\n", c[find(i)].size());
	}
	return 0;
}