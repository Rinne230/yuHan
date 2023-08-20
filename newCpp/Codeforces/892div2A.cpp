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

    void solve(){
        int n;
        cin >> n;
        int mx = -inf;
        vector<int> a(n + 1);
        vector<int> b, c;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        bool flag = true;
        int chk = a[1];
        for (int i = 1; i <= n; ++i)
            if (a[i] != chk){
                flag = false;
                break;
            }
        if (flag) {
            cout << -1 << endl;
            return;
        }
        for (int i = 1; i <= n; ++i){
            if (a[i] == mx) c.push_back(a[i]);
            else b.push_back(a[i]);
        }
        cout << (int)b.size() << " " << (int)c.size()<< endl;
        for (auto x : b) cout << x << " ";
        cout << endl;
        for (auto x : c) cout << x << " ";
        cout << endl;
    }

    int main(){
        ios;
        int t = 1;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }