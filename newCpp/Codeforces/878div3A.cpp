#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; 
    string s;
    cin >> n >> s;
    char ch = s[0];
    cout << ch;
    for (int i = 1; i < n; ++i){
        if (s[i] == ch && i + 1 < n){
            ch = s[i + 1];
            cout << ch;
            i++;
        }
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}   