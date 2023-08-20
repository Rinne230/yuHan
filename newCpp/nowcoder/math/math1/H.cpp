#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#pragma warning(disable : 4996)
typedef long long LL;
LL gcd(LL a, LL b)
{ // 最大公因数
    return b == 0 ? a : gcd(b, a % b);
}
LL lcm(LL a, LL b)
{ // 最小公倍数
    return a / gcd(a, b) * b;
}
LL exgcd(LL a, LL b, LL &x, LL &y)
{ // 拓展欧几里得
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL q = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return q;
}
LL mul(LL x, LL p, LL mod)
{ // 防爆乘法
    if (p < 0)
        x = -x, p = -p;
    LL ret = 0;
    for (; p; p >>= 1, x = (x + x) % mod)
        if (p & 1)
            ret = (ret + x) % mod;
    return ret;
}
LL _x, _y, k;
LL m[10005], a[10005];
LL CRT()
{ // 拓展中国剩余定理
    LL m1, m2, a1, a2, x, y, c;
    m1 = m[1];
    a1 = a[1];
    bool flag = true;
    for (int i = 2; i <= k; i++)
    {
        m2 = m[i];
        a2 = a[i];
        c = exgcd(m1, m2, x, y);
        if ((a2 - a1) % c)
            flag = false;
        y = m2 / c;
        x = mul((a2 - a1) / c, x, y);
        x = (x % y + y) % y;
        a1 = x * m1 + a1;
        m1 = (m1 * m2) / c;
    }
    c = exgcd(1, m1, x, y);
    if (a1 % c)
        flag = false;
    if (!flag)
        return -1;
    x = a1 / c * x;
    y = m1 / c;
    x = (x % y + y) % y;
    return x == 0 ? y : x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _x >> _y >> k;
    LL Lcm = 1;
    for (int i = 1; i <= k; i++)
    {
        cin >> m[i];
        Lcm = lcm(Lcm, m[i]);
        if (Lcm > _x)
        {
            printf("NO\n");
            return 0;
        }
        a[i] = ((m[i] - i + 1) % m[i] + m[i]) % m[i];
    }
    LL ans = CRT();
    if (ans == -1 || ans + k - 1 > _y)
    {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= k; i++)
    {
        if (gcd(Lcm, ans + i - 1) != m[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}