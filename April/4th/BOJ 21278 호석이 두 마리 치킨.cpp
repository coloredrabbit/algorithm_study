#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_N = 100;
vector<int> adj[MAX_N];
int dist[MAX_N];
queue<int> q;
int bfs(int s1, int s2) {
	int ret = 0;
	memset(dist, -1, sizeof dist);
	q.push(s1); q.push(s2);
	dist[s1] = dist[s2] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int& v : adj[u]) if (dist[v] == -1) {
			dist[v] = dist[u] + 1;
			q.push(v);
			ret += dist[v];
		}
	}
	return ret * 2;
}
int main() {
	int N, M, u, v, i, j, d, ans = 1e9, a1, a2;
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (i = 0; i < N; i++) for (j = i + 1; j < N; j++) {
		d = bfs(i, j);
		if (ans > d) {
			ans = d;
			a1 = i, a2 = j;
		}
	}
	printf("%d %d %d", a1 + 1, a2 + 1, ans);
	return 0;
}