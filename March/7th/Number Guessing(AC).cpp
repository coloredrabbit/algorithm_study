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

void solve() {
    int a, b, n; cin >> a >> b >> n;
    int ans = 0, L = a, R = b;
    while(L <= R) {
        int M = (L + R) / 2;
        cout << M << '\n';
        
        string s; cin >> s;
        if(s == "CORRECT") break;
        else if(s == "TOO_BIG") R = M - 1;
        else if(s == "TOO_SMALL") L = M + 1;
        else if(s == "WRONG_ANSWER") L = a, R = b;
    }
}

int main() {
    int T; cin >> T;
    while(T--) solve();
}
