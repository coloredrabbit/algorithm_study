#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int X, Y, D, T, c, i;
	double ans, ori, d;
	scanf("%d%d%d%d", &X, &Y, &D, &T);
	ori = ans = sqrt(X * X + Y * Y);
	c = ori / D;
	for (i = 0; i < 2; i++)
		ans = min(ans, (c + i) * T + abs(ori - D * (c + i)));

	d = max(0., ori - 2 * D);
	c = d / D;
	if (c * D < d) c++;

	ans = min(ans, (2. + c) * T);
	printf("%.11lf", ans);
	return 0;
}