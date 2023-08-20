#include <bits/stdc++.h>
using namespace std;
int n, e[301], f[301][301], maxn = -1;
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) {cin >> e[i], e[i + n] = e[i];}
    for (int L = 1; L <= n; ++L)
        for (int i = 1, j = i + L - 1; j <= (n << 1); ++j, ++i){
            for (int k = i; k < j; ++k)
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + e[i] * e[k + 1] * e[j + 1]);
            maxn = max(maxn, f[i][j]);
        }
    cout << maxn << endl;
    return 0;
} 