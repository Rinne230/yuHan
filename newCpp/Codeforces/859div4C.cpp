#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void solve(){
    int n;
        string s;
        cin >> n >> s;
        set<char> st;
        for (int i = 0; i < n; i++){
            if (!st.count(s[i])){
                st.insert(s[i]);
                for (int j = i + 1; j < n; j += 2){
                    if (s[i] == s[j]){
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
        cout << "YES" << endl;
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