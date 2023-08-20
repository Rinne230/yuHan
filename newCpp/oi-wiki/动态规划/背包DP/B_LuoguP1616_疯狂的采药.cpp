#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e7 + 5;
int n, m, w[N], v[N], f[M];
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; ++i)
        for (int j = w[i]; j <= m; ++j)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    cout << f[m] << endl;
    return 0;
}