#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

void solve()
{
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;
		int len = s.length();
		s = " " + s;
		int l = 0, r = 0;
		for (int i = 1; i <= ((len + 1) >> 1); i++)
			if (s[i] == '1')
				l++;
		for (int i = (len >> 1) + 1; i <= len; i++)
			if (s[i] == '1')
				r++;
		if (m % 2 == 0)
		{
			if (abs(l - r) & 1)
			{
				ans ^= 1;
			}
		}
		if (m % 2 == 1)
		{
			if (s[len / 2 + 1] == '0')
			{
				if (abs(l - r) & 1)
				{
					ans ^= 1;
				}
			}
			else
			{
				l--, r--;
				if (l < r)
					swap(l, r);
				if (r == 0)
				{
					if (l % 2)
						ans ^= 1;
				}
				else if (r == 1)
				{
					if ((l + r) % 2 == 1)
						ans ^= 3;
					else
						ans ^= 2;
				}
				else
				{
					if ((l + r) % 2 == 0)
						ans ^= 1;
				}
			}
		}
	}
	if (ans)
		cout << "Alice" << endl;
	else
		cout << "Bob" << endl;
}

int main()
{
	ios;
	int t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}