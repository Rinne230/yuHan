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
    vector<string> s;
    vector<string> ans;
    map<string, int> cnt;
    int n;
    cin >> n;
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        string str;
        cin >> str;
        cnt[str] = 1;
        ans.push_back(str);
    }
    for (int i = 2; i <= n; ++i){
        cin >> t;
        for (int j = 1; j <= t; ++j){
            string str;
            cin >> str;
            if (cnt[str] == i - 1){
                cnt[str]++;
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i){
        if (cnt[ans[i]] == n) s.push_back(ans[i]);
    }
    sort(s.begin(), s.end());
    cout << (int)s.size() << endl;
    for (auto i : s){
        cout << i << endl;
    }
}

int main(){
    ios;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}