/* Google KickStart */

/* ---------------------------------- template starts ---------------------------------- */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second
#define sz(x) (int)(x.size())
#define all(x) (x).begin(), (x).end()
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

/* ---------------------------------- template ends ---------------------------------- */

const int MAX = 1e3 + 10;

int N, M;
int board[MAX][MAX];
int p[MAX][MAX][4];

bool chk(int x, int y) {
    return 1 <= x && x <= N && 1 <= y && y <= M;
}

ll calc(ll d1, ll d2) {
    if(d1 < d2) swap(d1, d2);
    
    ll sum = ((d2 / 2) - 1) + min(d1 / 2 - 1, d2 - 1);
    return sum ;
}

int main() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    fastio
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int N, M; cin >> N >> M;
        
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                cin >> board[i][j];
     
        for(int k = 0; k < 4; k++) {
            if(k == 0) {
                // 0: N to 1
                for(int j = 1; j <= M; j++) {
                    for(int i = N; i >= 1; i--) {
                        if(i == N) p[i][j][k] = board[i][j];
                        else p[i][j][k] = (board[i][j] == 0 ? 0 : p[i + 1][j][k] + 1);
                    }
                }
            } else if(k == 1) {
                // 1: 1 to N
                for(int j = 1; j <= M; j++) {
                    for(int i = 1; i <= N; i++) {
                        if(i == 1) p[i][j][k] = board[i][j];
                        else p[i][j][k] = (board[i][j] == 0 ? 0 : p[i - 1][j][k] + 1);
                    }
                }
            } else if(k == 2) {
                // 2: M to 1
                for(int i = 1; i <= N; i++) {
                    for(int j = M; j >= 1; j--) {
                        if(j == M) p[i][j][k] = board[i][j];
                        else p[i][j][k] = (board[i][j] == 0 ? 0 : p[i][j + 1][k] + 1);
                    }
                }
            } else if(k == 3) {
                // 3: 1 to M
                for(int i = 1; i <= N; i++) {
                    for(int j = 1; j <= M; j++) {
                        if(j == 1) p[i][j][k] = board[i][j];
                        else p[i][j][k] = (board[i][j] == 0 ? 0 : p[i][j - 1][k] + 1);
                    }
                }
            }
        }
        
        ll ans = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                ll L = p[i][j][3], R = p[i][j][2];
                ll D = p[i][j][0], U = p[i][j][1];
                
                if(L > 1 && U > 1) ans += calc(L, U);
                if(L > 1 && D > 1) ans += calc(L, D);
                if(R > 1 && U > 1) ans += calc(R, U);
                if(R > 1 && D > 1) ans += calc(R, D);
            }
        }
        
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}