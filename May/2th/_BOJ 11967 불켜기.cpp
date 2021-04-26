#include<cstdio>
#include<set>
#include<queue>
#include<vector>
using namespace std;
int main() {
	int N, M, ans = 0, x, y, a, b, dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 }, vi[101][101] = {}, i, j, f;
	vector<pair<int, int>> adj[101][101];
	set<pair<int, int>> one;
	queue<pair<int, int>> q;
	scanf("%d%d", &N, &M);
	while (M--) {
		scanf("%d%d%d%d", &x, &y, &a, &b);
		x--, y--, a--, b--;
		adj[x][y].push_back({ a, b });
	}
	vi[0][0] = 2;
	q.push({ 0,0 });
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		for (auto e : adj[u.first][u.second]) {
			if (!vi[e.first][e.second]) {
				vi[e.first][e.second] = 1;
				one.insert(e);
			}
		}

		for(auto it = one.begin(); it != one.end(); ){
			f = 0;
			for (i = 0; i < 4; i++) {
				int ty = it->first + dy[i], tx = it->second + dx[i];
				if (0 <= ty && ty < N && 0 <= tx && tx < N && vi[ty][tx] == 2) {
					vi[it->first][it->second] = 2;
					q.push(*it);
					it = one.erase(it);
                    f = 1;
                    break;
				}
			}
			if (!f) it++;
		}
	}
	for (i = 0; i < N; i++) for (j = 0; j < N; j++)
		ans += vi[i][j] > 0;
	printf("%d", ans);
	return 0;
}