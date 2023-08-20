// 80pts
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
const int maxn = 1e5 + 10;
unordered_map<int, int> m;
int a[maxn], n;
int main(){
    IOS;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        while (m[a[i]])
            ++a[i];
        m[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    return 0;
}
