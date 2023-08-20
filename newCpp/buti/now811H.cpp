#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

int f[maxn], nxt[maxn];
bool flag[maxn];
int n;
vector<pll> qu;
inline int read() {
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}
//快写
inline void write(ll x) {
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
void solve()
{
    n = read();
    vector<int> a(n + 1);
    vector<int> s;
    for (int i = 1; i <= n; ++i)
        a[i] = read(), nxt[i] = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
        {
            f[i] = i;
            vector<stack<int>> st(n + 1);
            st[a[i]].push(i);
            int j;
            for (j = i + 1; j <= n; ++j)
            {
                if (a[j] == 1)
                {
                    f[j] = j;
                    st[a[j]].push(j);
                }
                else if (!st[a[j] - 1].empty())
                {
                    int t = st[a[j] - 1].top();
                    st[a[j] - 1].pop();
                    f[j] = f[t];
                    st[a[j]].push(j);
                }
                else
                {
                    qu.push_back({i, j - 1});
                    i = j;
                    break;
                }
            }
            if (j == n + 1 && j != i)
                qu.push_back({i, j - 1});
            i = j;
        }
    }
    // for (int i = 1; i <= n; ++i) cout << f[i] << " \n"[i == n];
    ll ans = 0;
    stack<int> sta;
    for (int i = 1; i <= n; ++i)
    {
        if (sta.empty()){
            sta.push(f[i]);
        }
        else
        {
            while (!sta.empty() && sta.top() > f[i])
            {
                int num = sta.top();
    
                    nxt[num] = min(nxt[num], i);
                sta.pop();
            }
            sta.push(f[i]);
        }
    }
    // for (int i = 1; i <= n; ++i) cout << nxt[f[i]] << " \n"[i == n];
    for (auto [l, r] : qu)
    {
        ans += r - l + 1;
        // cout << l << " " << r << endl;
        for (int i = l + 1; i <= r; ++i)
        {
            if (a[i] == 1)
            {
                ans += nxt[f[i]] - i;
            }
        }
    }
    write(ans);
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