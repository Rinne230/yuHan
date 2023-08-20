#include <bits/stdc++.h>
#define re register
using namespace std;
inline int read()
{
	re int t = 0;
	re char v = getchar();
	while (v < '0')
		v = getchar();
	while (v >= '0')
		t = (t << 3) + (t << 1) + v - 48, v = getchar();
	return t;
}
int t, n, ans;
int main()
{
	t = read();
	while (t--)
	{
		n = read();
		re int l = 1, r = n;
		while (l <= r)
		{
			re int mid = l + r >> 1, tmp = n / (mid + mid + 2);
			re int s = tmp * 2 + max(0, n % (mid + mid + 2) - mid - mid);
			if (s <= mid)
				ans = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		printf("%d\n", ans);
	}
}
