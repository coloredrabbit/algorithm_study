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

int main() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    fastio
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int N, K; cin >> N >> K;
        string s; cin >> s;
        
        int same = 0;
        for(int i = 0; i < N / 2; i++) 
            if(s[i] != s[N - 1 - i]) 
                same++;
        
        cout << "Case #" << tc << ": " << abs(same - K) << '\n';
    }
}

