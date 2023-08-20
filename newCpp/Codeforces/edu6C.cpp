#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
ll a[maxn];
vector<pair<ll, ll>> ans;
map<ll, int> m;
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; 
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int l = -1, r;
    for (int i = 1; i <= n; ++i){
        m[a[i]]++;
        if (l == -1) l = i;
        else if (m[a[i]] == 2){
            r = i;
            ans.push_back({l, r});
            for (int j = l; j <= r; ++j) m[a[j]]--;
            l = -1;
        }
    }
    if (ans.empty()){
        cout << -1;
        return 0;
    }
    cout << ans.size() << '\n';
    if (ans[ans.size() - 1].second != n) ans[ans.size() - 1].second = n;
    for (auto i : ans){
        cout << i.first << " " << i.second << '\n';
    }
    return 0;
}