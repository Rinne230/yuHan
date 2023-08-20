#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL N = 5e4 + 10, MOD = 1e9 + 7, INF = 0x3f3f3f3f;
LL s[N];
LL get_s(int l, int r)
{
	LL res = 0, mx = 0;
	for (LL i = l, j = r; i <= r; ++i, --j)
	{
		res += i * j;
		mx = max(mx, i * j);
	}
	return res - mx;
}
void solve()
{
	int n;
	scanf("%d", &n);
	for (LL i = 1; i <= n; ++i)
		s[i] = s[i - 1] + i * i;
	LL ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, s[i - 1] + get_s(i, n));
	printf("%lld\n", ans);
}
int main()
{
	int T = 1;
	scanf("%d", &T);
	while (T--)
	{
		solve();
	}
	return 0;
}