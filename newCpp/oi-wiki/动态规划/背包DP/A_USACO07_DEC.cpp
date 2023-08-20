#include <bits/stdc++.h>
using namespace std;
int w[3501], v[3501];
int f[15001];
int n, m;
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= w[i]; --j)
            f[j] = max(f[j - w[i]] + v[i], f[j]);
    cout << f[m] << endl;
    return 0;
}