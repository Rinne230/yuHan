#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 21, M = (1 << N);
bool e[N][N];
ll f[M][N];//fij表示走到j + 1状态为i的计数
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
int main(){
    for (int i = 1; i <= 21; ++i)
        for (int j = 1; j <= 21; ++j)
            if (gcd(i, j) == 1)
                e[i - 1][j - 1] = e[j - 1][i - 1] = 1;
    f[1][0] = 1;
    for (int i = 1; i <= M - 1; ++i)
        for (int j = 0; j <= 20; ++j)
            if (i >> j & 1)
                for (int k = 0; k <= 20; ++k)
                    if (i >> k & 1 && e[k][j])
                        f[i][j] += f[i - (1 << j)][k];
    ll ans = 0;
    for (int i = 1; i <= 20; ++i) ans += f[M - 1][i];
    cout << ans << endl;//881012367360
    return 0;
}