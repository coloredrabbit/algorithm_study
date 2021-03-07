#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(x) (int)(x.size())
#define all(x) (x).begin(), (x).end()
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

using namespace std;

const int MAX_N = 5e6 + 1;

int p[MAX_N];

int main() {
    //freopen("input.txt", "r", stdin);
    fastio
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int N; cin >> N;
        string s; cin >> s;

        memset(p, 0, sizeof(p));
        for(int i = 0; i < N; i++) {
            p[i] = s[i] - '0';
            if(i > 0) p[i] += p[i - 1];
        }
        
        int ans = 0;
        int H = (N + 1) / 2;
        for(int i = H - 1; i < N; i++) ans = max(ans, p[i] - p[i - H]);
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}
