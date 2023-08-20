#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[2023][11][2023];
int main(){
    for (int i = 0; i <= 2022; ++i)
        f[i][0][0] = 1;
    for (int i = 1; i <= 2022; ++i)
        for (int j = 1; j <= 10; ++j)
            for (int k = 1; k <= 2022; ++k){
                f[i][j][k] = f[i - 1][j][k];
                if (k >= i) f[i][j][k] += f[i - 1][j - 1][k - i];
            }
    cout << f[2022][10][2022];
    return 0;
}