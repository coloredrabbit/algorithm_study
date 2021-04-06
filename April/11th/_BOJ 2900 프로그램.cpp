#include<iostream>
using namespace std;
using ll = long long;
const int MAX_N = 1e6 + 1, LIMIT = 1e3 + 1;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, X, K, i, j, Q, L, R, cnt[MAX_N] = {};
	ll ans, ps[MAX_N] = {}, A[MAX_N] = {};
	cin >> N >> K;
	for (i = 0; i < K; i++) {
		cin >> X;
		cnt[X]++;
	}
	
	ll c = 0;
	for (i = 1; i < N; i++) if(cnt[i]) {
		for (j = i; j < N; j += i)
			A[j] += cnt[i];
	}
	ps[0] = K;
	for (i = 1; i < N; i++)
		ps[i] = ps[i - 1] + A[i];
	cin >> Q;
	while (Q--) {
		cin >> L >> R;
		ans = ps[R];
		if (L) ans -= ps[L - 1];
		printf("%lld\n", ans);
	}
	return 0;
}