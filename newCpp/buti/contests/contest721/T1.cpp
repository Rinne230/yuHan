#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(ll x) {
    string s = to_string(x);
    int len = s.length();
    bool flag = false;
    for (int i = 1; i + len <= 18; ++i){
        ll p = ksm(10, i);
        ll tx = x * p;
        ll y = sqrt(tx);
        if (y * y / p == x){
            flag = true;
            cout << y << endl;
            break;
        }else if ((y + 1) * (y + 1) / p == x){
            flag = true;
            cout << y + 1 << endl;
            break;
        }
    }
    if (!flag) cout << "-1" << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        solve(x);
    }
    return 0;
}
