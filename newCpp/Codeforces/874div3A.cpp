#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<string> st;
        for (int i = 1; i < n; ++i){
            string a = s.substr(i - 1, 2);
            st.insert(a);
        }
        cout << st.size() << endl;
    }
    return 0;
}
