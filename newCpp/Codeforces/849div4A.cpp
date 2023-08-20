#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

map<char, int> hs;

void solve(){
    char ch;
    cin >> ch;
    if (hs[ch]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios;
    string s = "codeforces";
    for (int i = 0; i < s.length(); ++i){
        hs[s[i]] = 1;
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}