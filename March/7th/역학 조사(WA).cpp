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

const int MAX = 1e5 + 10;

vector<int> a[MAX];
int res[MAX], ans[MAX], state[MAX];

int main() {
    // freopen("input.txt", "r", stdin);
    
	int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int K; cin >> K;
        
        a[i].resize(K);
        for(auto& x : a[i]) cin >> x;
    }
    
    for(int i = 1; i <= N; i++) {
        cin >> res[i];
        ans[i] = state[i] = -1;
    }
        
    for(int i = 0; i < M; i++) {
        bool not_infected = 0, infected = 0;
        for(auto& x : a[i]) {
            if(res[x] == 0) not_infected = 1;
            if(state[x] == 1) infected = 1;
        }
                
        if(not_infected && infected) {
            cout << "NO" << '\n';
            return 0;
        } else if(not_infected) {
            for(auto& x : a[i]) ans[x] = state[x] = 0;
        } else {
            for(auto& x : a[i]) state[x] = 1;
        }
    }
    
    for(int i = 1; i <= N; i++) {
        if(ans[i] == -1) {
            ans[i] = res[i];
        } else {
            if(state[i] != -1 && state[i] != res[i]) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    
    cout << "YES" << '\n';
    for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
        
	return 0;
}