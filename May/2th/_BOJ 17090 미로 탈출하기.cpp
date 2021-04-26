#include<cstdio>
#include<cstring>
const int MAX_N = 502;
int N, M, dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 }, vi[MAX_N][MAX_N], ans;
char b[MAX_N][MAX_N + 1];
int gi(char c) {
	switch (c) {
	case 'R': return 0;
	case 'L': return 1;
	case 'D': return 2;
	default: return 3;
	}
}
void dfs(int y, int x) {
	if (!(1 <= y && y <= N && 1 <= x && x <= M)) {
		vi[y][x] = 1;
		return;
	}
	vi[y][x] = 0;
	int idx = gi(b[y][x]);
	if (vi[y + dy[idx]][x + dx[idx]] == -1)
		dfs(y + dy[idx], x + dx[idx]);
	vi[y][x] = vi[y + dy[idx]][x + dx[idx]];
	ans += vi[y][x];
}
int main() {
	memset(vi, -1, sizeof vi);
	int i, j;
	scanf("%d%d\n", &N, &M);
	for (i = 1; i <= N; i++) scanf("%s", b[i] + 1);
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) if (vi[i][j] == -1)
		dfs(i, j);
	printf("%d", ans);
	return 0;
}