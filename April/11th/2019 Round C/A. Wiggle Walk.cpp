#include <iostream>
#include <map>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
// 0: W, 1: E, 2: N, 3: S

int convert(char o) {
	if(o == 'W') return 0;
	else if(o == 'E') return 1;
	else if(o == 'N') return 2;
	else if(o == 'S') return 3;
	return -1;
}

int main() {
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++) {
		int N, R, C, x, y; cin >> N >> R >> C >> x >> y;
		string s; cin >> s;
		
		map<pii, bool> m;
		m.emplace(make_pair(x, y), true);
		
		for(auto& o : s) {
			int k = convert(o);
			
			x += dx[k], y += dy[k];
			while(m.find(make_pair(x, y)) != m.end()) x += dx[k], y += dy[k];
			m.emplace(make_pair(x, y), true);
		}
		cout << "Case #" << tc << ": " << x << ' ' << y << '\n';
	}

	return 0;
}