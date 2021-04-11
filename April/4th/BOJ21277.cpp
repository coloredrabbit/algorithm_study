#include <iostream>

using namespace std;

const int MAX = 2e2 + 10;
const int INF = 1e9;

int N, M, NN, MM;
int ans = MAX * MAX;
int a[MAX][MAX];
int b[MAX][MAX];

void rotate(int c[MAX][MAX], int& n, int &m) {
	int d[m][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			d[j][n - i - 1] = c[i][j];
			c[i][j] = 0;
		}
	}
			
	swap(n, m);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) 
			c[i][j] = d[i][j];
}

int count(int c[MAX][MAX], int d[MAX][MAX], int n, int m, int nn, int mm, int x, int y) {
	for(int i = 0; i < nn; i++)
		for(int j = 0; j < mm; j++)
			if(c[i + x][j + y] == 1 && d[i][j] == 1)
				return INF;

	return max(n, nn + x) * max(m, mm + y);
}

int go() {
	int cnt = INF;
	for(int i = 0; i < N + 1; i++)
		for(int j = 0; j < M + 1; j++) 
			if(!(a[i][j] == 1 && b[0][0] == 1))
				cnt = min(cnt, count(a, b, N, M, NN, MM, i, j));
	
	for(int i = 0; i < NN + 1; i++) 
		for(int j = 0; j < MM + 1; j++)
			if(!(b[i][j] == 1 && a[0][0] == 1))
				cnt = min(cnt, count(b, a, NN, MM, N, M, i, j));
			
	return cnt;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		string s; cin >> s;
		for(int j = 0; j < M; j++) a[i][j] = s[j] - '0';
	}

	cin >> NN >> MM;
	for(int i = 0; i < NN; i++) {
		string s; cin >> s;
		for(int j = 0; j < MM; j++) b[i][j] = s[j] - '0';
	}

	int ans = min((N + NN) * max(M, MM), (M + MM) * max(N, NN));
	for(int k = 0; k < 4; k++) {
		for(int kk = 0; kk < 4; kk++) {
			ans = min(ans, go());
			rotate(b, NN, MM);
		}
		rotate(a, N, M);
	}
	cout << ans << '\n';
	
	return 0;
}