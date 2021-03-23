#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int MAX_N = 1e3;
int p[MAX_N * MAX_N], c[MAX_N * MAX_N], pos[2][MAX_N * MAX_N];
bool invalid[MAX_N * MAX_N];
int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
void apply(int u, int w) {
	if (w != -1 && pos[0][u] != w && pos[1][u] != w) {
		if (pos[0][u] != -1 && pos[1][u] != -1)
			invalid[u] = 1;
		else pos[pos[0][u] != -1][u] = w;
	}
}
void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	p[u] = v;
	c[v] += c[u];
	invalid[v] |= invalid[u];
	apply(v, pos[0][u]); apply(v, pos[1][u]);
}
int main() {
	int N, M, b[MAX_N][MAX_N], i, j, k, z, u, v, dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 }, ans = 0, maxi[2] = {};
	map<int, int> _uno;
	map<pair<int, int>, int> _dos;
	bool vi[MAX_N * MAX_N] = {};
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) {
		scanf("%d", &b[i][j]);
		u = i * M + j;
		p[u] = u;
		c[u] = 1;
		pos[0][u] = pos[1][u] = -1;
	}
	for (z = 0; z < 2; z++)
		for (i = 0; i < N; i++) for (j = 0; j < M; j++) if (b[i][j] == 2) {
			u = i * M + j;
			for (k = 0; k < 4; k++) {
				int ty = i + dy[k], tx = j + dx[k];
				if (0 <= ty && ty < N && 0 <= tx && tx < M) {
					v = ty * M + tx;
					if (z == 1 && b[ty][tx] == 2) {
						merge(u, v);
						u = find(u);
					}
					else if (z == 0 && b[ty][tx] == 0)
						apply(u, v);
				}
			}
		}
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) if (b[i][j] == 2) {
		u = i * M + j;
		u = find(u);
		if (!vi[u]) {
			vi[u] = 1;
			if (invalid[u]) continue;

			if (pos[0][u] < pos[1][u])
				swap(pos[0][u], pos[1][u]);
			if (pos[0][u] != -1) {
				if (pos[1][u] == -1) {
					vi[u] = 1;
					if (maxi[1] < c[u])
						maxi[1] = c[u];
					if (maxi[0] < maxi[1]) swap(maxi[0], maxi[1]);

					int& val = _uno[pos[0][u]];
					val += c[u];
					ans = max(ans, val);
				}
				else {
					int& val = _dos[{pos[0][u], pos[1][u]}];
					val += c[u];
					ans = max(ans, val);
				}
			}
		}
	}
	for (auto it = _dos.begin(); it != _dos.end(); it++) {
		auto jt = _uno.find(it->first.first);
		if (jt != _uno.end())
			it->second += jt->second;
		jt = _uno.find(it->first.second);
		if (jt != _uno.end())
			it->second += jt->second;
		ans = max(ans, it->second);
	}
	ans = max(ans, maxi[0] + maxi[1]);
	printf("%d", ans);
	return 0;
}