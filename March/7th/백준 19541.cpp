#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;
const int MAX_N = 1e5;
int main() {
	int N, M, k[MAX_N], cnt, i, j, joinCnt[MAX_N] = {}, infestJoinCnt[MAX_N] = {};
	vector<int> a[MAX_N];
	bool infested[MAX_N], traced = 1, alreadyInfested[MAX_N] = {}, simulResult[MAX_N], infest;
	scanf("%d%d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &k[i]);
		a[i].resize(k[i]);
		for (j = 0; j < k[i]; j++) {
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
	}
	for (i = 0; i < N; i++) scanf("%d", &infested[i]);
	memcpy(alreadyInfested, infested, sizeof alreadyInfested);
	for (i = M - 1; i >= 0; i--) {
		infest = 1;
		for (int& A : a[i]) if (!alreadyInfested[A]) {
			infest = 0;
			break;
		}
		if (!infest)
			for (int& A : a[i])
				alreadyInfested[A] = 0;
	}
	memcpy(simulResult, alreadyInfested, sizeof alreadyInfested);
	for (i = 0; i < M; i++) {
		infest = 0;
		for (int& A : a[i]) if (simulResult[A]) {
			infest = 1;
			break;
		}
		if (infest) {
			for (int& A : a[i])
				simulResult[A] = 1;
		}
	}
	for (i = 0; i < N; i++)
		traced &= simulResult[i] == infested[i];
	if (traced) {
		puts("YES");
		for (i = 0; i < N; i++) printf("%d ", alreadyInfested[i]);
	}
	else puts("NO");
	return 0;
}