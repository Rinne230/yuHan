#include <bits/stdc++.h>
using namespace std;
const int N = 8, M = 5005, mod = 1e9 + 7;
int n, m, ans = 0;
int f[5005][10001];

bool check(int x){
    int pre = -1;
    for (int i = 0; i < n; ++i){
        if (x % 3 == pre) return false;
        pre = x % 3;
        x /= 3;
    }
    return true;
}
bool isTrue(int x, int y){
    for (int i = 0; i < n; ++i){
        if (x % 3 == y % 3)
            return false;
        x /= 3;
        y /= 3;
    }
    return true;
}
void work(){
    int ed = 1;
    for (int i = 1; i <= n; ++i) ed *= 3;
    for (int i = 0; i < ed; ++i)
        if (check(i)) f[1][i] = 1;
     for(int i = 2; i <= m; ++i)
            for(int j = 0; j < ed; ++j)
                if(check(j))
                    for(int k = 0; k < ed; k++){
                        if(!isTrue(j, k)) continue;
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                    }
    int ans = 0;
    for(int i = 0; i < ed; i++)
        ans = (ans + f[m][i]) % mod;
    cout << ans << endl;
}
int main() {
    cin >> n >> m;
    work();
    return 0;
}