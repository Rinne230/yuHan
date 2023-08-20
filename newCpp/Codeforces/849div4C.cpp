#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = n - 1;
    while ((s[l] - '0') ^ (s[r] - '0') && l <= r) {
        n -= 2;
        l++, r--;
    }
    cout << n << endl;
}

int main(){
    ios;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}