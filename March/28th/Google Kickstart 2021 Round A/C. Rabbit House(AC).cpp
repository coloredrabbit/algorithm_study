#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 3e2 + 10;

int N, M;
long long a[MAX][MAX];
long long d[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		
		
		priority_queue<pair<int, pii>> pq;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				cin >> a[i][j];
				d[i][j] = a[i][j];
				pq.push({a[i][j], {i, j}});
			}
		}
		
		while(!pq.empty()) {
			int c = pq.top().fi;
			int x = pq.top().sc.fi;
			int y = pq.top().sc.sc;
			pq.pop();
			
			if(c < a[x][y]) continue;
			for(int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if(0 <= nx && nx < N && 0 <= ny && ny < M) {
					if(c - 1 > d[nx][ny]) {
						d[nx][ny] = c - 1;
						pq.push({c - 1, {nx, ny}});
					}
				}
			}
		}
		
		long long ans = 0;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				ans += abs(d[i][j] - a[i][j]);
		cout << "Case #" << tc << ": " << ans << '\n';
	}

	return 0;
}