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

const int MAX = 3e2 + 10;

int N, M;
ll board[MAX][MAX];
ll ans[MAX][MAX];
bool updated[MAX][MAX];

bool chk(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

int main() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    fastio
        
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> N >> M;
        
        priority_queue< pair<int, pii> > pq;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> board[i][j];
                ans[i][j] = board[i][j];
                updated[i][j] = 0;

                pq.push({ans[i][j], {i, j}});
            }
        }
                
        while(!pq.empty()) {
            ll now = pq.top().fi;
            int x = pq.top().sc.fi;
            int y = pq.top().sc.sc;
            pq.pop();
            
            updated[x][y] = 1;
            if(ans[x][y] != now) continue;
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if(chk(nx, ny) && !updated[nx][ny]) {
                    int diff = abs(now - ans[nx][ny]);
                    
                    if(diff > 1) ans[nx][ny] = max(ans[nx][ny], now - 1);
                    pq.push({ans[nx][ny], {nx, ny}});
                }
            }
        }
        
        ll sum = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                sum += abs(ans[i][j] - board[i][j]);

        cout << "Case #" << tc << ": " << sum << '\n';
    }
}