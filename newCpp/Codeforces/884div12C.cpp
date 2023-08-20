#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;

void solve(){
    int n;
    vector<ll> a;
    cin >> n;
    bool positive = false;
    for (int i = 0, tmp; i < n; ++i){
        cin >> tmp;
        positive |= (tmp >= 0);
        a.push_back(tmp);
    }
    if (!positive) cout << *max_element(a.begin(), a.end()) << endl;
    else{
        ll ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; ++i){
            if (i & 1) ans1 += max(0ll, a[i]);
            else ans2 += max(0ll, a[i]);
        }
        cout << max(ans1, ans2) << endl;
    }
}

int main(){
    ios;
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}