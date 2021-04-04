#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
using ll = long long;
const int MAX_N = 50, OFFSET = 50;
char t[MAX_N][MAX_N];
void rot(char b[MAX_N][MAX_N], int M) {
    int i, j, L, R, B, T;
    for (i = 0; i < M / 2; i++) {
        for (j = i; j < M - i - 1; j++) {
            char temp = b[i][j];
            b[i][j] = b[M - 1 - j][i];
            b[M - 1 - j][i] = b[M - 1 - i][M - 1 - j];
            b[M - 1 - i][M - 1 - j] = b[j][M - 1 - i];
            b[j][M - 1 - i] = temp;
        }
    }
    L = T = M + 1, R = B = -1;
    for (i = 0; i < M; i++)  for (j = 0; j < M; j++) if (b[i][j] == '1') {
        T = min(T, i); B = max(B, i);
        L = min(L, j); R = max(R, j);
    }
    memset(t, 0, sizeof t);
    for (i = T; i <= B; i++) for (j = L; j <= R; j++)
        t[i - T][j - L] = b[i][j];
    memcpy(b, t, sizeof t);
}
int main() {
    int i, j, k, y, x, N[2], M[2], L[2], ty, tx, ans, valid;
    char b[2][MAX_N][MAX_N] = {};
    for (k = 0; k < 2; k++) {
        scanf("%d%d\n", &N[k], &M[k]);
        for (i = 0; i < N[k]; i++) scanf("%s", &b[k][i]);
        L[k] = max(N[k], M[k]);
    }
    ans = 1e9;
    for (k = 0; k < 4; k++) {
        for (i = 0; i < N[0] + N[1]; i++) {
            for (j = 0; j < M[0] + M[1]; j++) {
                valid = 1;
                for (y = 0; valid && y < N[1]; y++) for (x = 0; valid && x < M[1]; x++) {
                    ty = i - N[1] + 1 + y, tx = j - M[1] + 1 + x;
                    if (0 <= ty && ty < N[0] && 0 <= tx && tx < M[0])
                        valid &= !(b[0][ty][tx] == '1' && b[1][y][x] == '1');
                }
                if (valid)
                    ans = min(ans, (max(M[0] - 1, j) - min(0, j - M[1] + 1) + 1) * (max(N[0] - 1, i) - min(0, i - N[1] + 1) + 1));
            }
        }
        rot(b[1], L[1]);
        swap(N[1], M[1]);
    }
    printf("%d", ans);
    return 0;
}