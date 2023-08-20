#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int main() {
    ios;
    int t, n;
    cin >> t;
    while (t--) {
        string s;
        cin >> n;
        int c = 1;
        while ((n % c) == 0) c++;
        for (int i = 0; i < n; i++) s += 'a' + (i % c);
        cout << s << endl;
    }
    return 0;
}