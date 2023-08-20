#include<iostream>
using namespace std;
const int N = 1e7 + 10, MOD = 1000000007;
int f[N];
int main(){
    f[1] = 1;
    f[2] = 2;
    f[3] = 5;
    int n;
    cin >> n;
    for(int i = 4; i <= n; i ++){
        f[i] = (2 * f[i - 1] % MOD + f[i - 3] % MOD) % MOD;
    }
    cout << f[n];
    return 0;
}