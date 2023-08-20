#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;
    set<int> se;
    for (int i = 0; i < n; i++){
        if (s[i] != "()"[i % 2]){
            se.insert(i);
        }
    }
    while (q--){
        int p;
        cin >> p;
        s[--p] ^= 1;
        if (s[p] != "()"[p % 2]){
            se.insert(p);
        }
        else{
            se.erase(p);
        }
        if (n % 2){
            cout << "NO" << endl;
            continue;
        }
        if (se.empty())
            cout << "YES" << endl;
        else{
            if (*se.begin() % 2 == 1 && *se.rbegin() % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
