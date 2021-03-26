
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 1e5 + 10;

int cnt[MAX_N][26];

int main() {
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++) {
		int N, Q; cin >> N >> Q;
		string s; cin >> s;
		
		for(int i = 0; i < N; i++) 
			for(int j = 0; j < 26; j++)
				cnt[i][j] = 0;
	
		for(int i = 0; i < N; i++) {
			char x = s[i] - 'A';
			cnt[i][x]++;
			
			if(i > 0) {
				for(int j = 0; j < 26; j++) 
					cnt[i][j] += cnt[i - 1][j];
			}
		}
		
		int ans = 0;
		while(Q--) {
			int L, R; cin >> L >> R;
			L--, R--;
			
			int odd = 0;
			for(int j = 0; j < 26; j++) {
				int k = cnt[R][j] - (L == 0 ? 0 : cnt[L - 1][j]);
				if(k & 1) odd++;
			}
			if(odd <= 1) ans++;
		}
		cout << "Case #" << tc << ": " << ans << '\n';
	}

	return 0;
}