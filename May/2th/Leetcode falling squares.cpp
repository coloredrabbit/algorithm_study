#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int MAX_N = 2e3;
int N, t[(MAX_N + 1) * 2];
int query(int l, int r) {
	int res = 0;
	for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) res = max(res, t[l++]);
		if (r % 2 == 0) res = max(res, t[r--]);
	}
	return res;
}
void update(int l, int d) {
	for (t[l += N] = d; l > 1; l >>= 1)
		t[l >> 1] = max(t[l], t[l ^ 1]);
}
class Solution {
public:
	vector<int> fallingSquares(vector<vector<int>>& positions) {
		vector<int> ans;
		vector<int> xpos;
		int cnt = 0, at, w, l, r, maxi, top, i;
		map<int, int> indices;
		memset(t, 0, sizeof t);

		for (auto& p : positions) {
			at = p[0], w = p[1];
			xpos.push_back(at);
			xpos.push_back(at + w - 1);
		}
		sort(xpos.begin(), xpos.end());
		N = unique(xpos.begin(), xpos.end()) - xpos.begin();

		for (auto& p : positions) {
			at = p[0], w = p[1];
			l = lower_bound(xpos.begin(), xpos.begin() + N, at) - xpos.begin();
			r = lower_bound(xpos.begin(), xpos.begin() + N, at + w - 1) - xpos.begin();
			top = query(l, r);
			for (i = l; i <= r; i++)
				update(i, w + top);
			maxi = max(maxi, w + top);
			ans.push_back(maxi);
		}
		return ans;
	}
};