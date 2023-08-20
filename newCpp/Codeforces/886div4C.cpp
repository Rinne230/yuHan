#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve(){
    char ch;
    string ans = "";
    for (int i = 1; i <= 8; ++i){
        for (int j = 1; j <= 8; ++j){
            cin >> ch;
            if (ch >= 'a' && ch <= 'z')
                ans += ch;
        }
    }
    cout << ans << endl;
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