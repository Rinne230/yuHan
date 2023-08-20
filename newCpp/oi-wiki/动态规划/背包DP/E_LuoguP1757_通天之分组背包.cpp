#include <bits/stdc++.h>
using namespace std;
int v, n, t, x, g[201][201], w[10001], z[10001], b[10001], f[10001];
int main(){
    cin >> v >> n;
    for (int i = 1; i <= n; ++i){
        cin >> w[i] >> z[i] >> x;
        t = max(t, x);
        g[x][++b[x]] = i;
    }
    for (int i = 1; i <= t; ++i)
        for (int j = v; j >= 0; --j)
            for (int k = 1; k <= b[i]; ++k)
                if (j >= w[g[i][k]])
                    f[j] = max(f[j], f[j - w[g[i][k]]] + z[g[i][k]]);
    cout << f[v] << endl;
    return 0;
}