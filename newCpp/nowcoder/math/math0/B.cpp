/**
 * @file Sum of Consecutive Prime Numbers
 * @author atri
 * @brief
 * @version 0.1
 * @date 2023-08-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

int sum[3000000];
int prime[3000000];
bool vis[40000007];
int ans[40000007];
int cnt = 0;
int n;

void get_prime()
{
    for (int i = 2; i <= 40000007; i++)
    {
        if (!vis[i])
        {
            prime[cnt++] = i;
        }
        for (int j = 0; prime[j] <= 40000007 / i; j++)
        {
            vis[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void init(){
    get_prime();
    for (int i = 0; i < cnt; ++i){
        int sum = 0;
        for (int j = i; j < cnt; ++j){
            sum += prime[j];
            if (sum > 40000000) break;
            ans[sum]++;
        }
    }
}
void solve()
{
    int n; 
    cin >> n;
    cout << ans[n] << endl;
}

int main()
{
    ios;
    int t = 1;
    cin >> t;
    init();
    while (t--)
    {
        solve();
    }
    return 0;
}