#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
ll a[200005], b[200005], nb[200005];
int main()
{
    int n, i;
    cin >> n;
    b[0] = 1;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
        b[i] = 1;
    }
    //b[i]表示在考虑到数组的第i个元素时，所有满足条件的子数组的异或值的和
    //nb[i]表示在考虑到数组的第i个元素时只考虑第j个元素，所有满足条件的子数组的异或值的和
    for (int o = 0; o < 3; o++)
    {
        for (int j = 31; j >= 0; j--)
        {
            ll p[2] = {b[0], 0};//p[0]表示当前位为止之前为0的元素数量，p[1]表示当前位为止之前1的元素数量
            for (i = 1; i <= n; i++)
            {
                nb[i] += (1 << j) * p[((a[i] >> j) & 1) ^ 1] % mod;
                (p[(a[i] >> j) & 1] += b[i]) %= mod;
            }
        }
        b[0] = 0;
        for (i = 1; i <= n; i++)
            b[i] = (b[i - 1] + nb[i]) % mod, nb[i] = 0;//nb[i]归0
    }
    cout << b[n];
}
