#include <bits/stdc++.h>
#define eps 1e-6
#define LL long long
#define pii pair<int, int>
// #pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

const int MAXN = 100100;
const int MOD = 1e9 + 7;
const int base = 97;
LL bit[MAXN], pre[MAXN];
LL setv[4 * MAXN], sumv[4 * MAXN];
int n, q1, q2, q;
char str[MAXN];
void pushdown(int o)
{
    int lc = o * 2, rc = o * 2 + 1;
    if (setv[o] >= 0)
    { // 本节点有标记才传递
        setv[lc] = setv[rc] = setv[o];
        setv[o] = -1;
    }
}
void maintain(int o, int L, int R)
{
    int lc = 2 * o, rc = 2 * o + 1, M = (L + R) >> 1;
    sumv[o] = 0;
    if (R > L)
    {
        sumv[o] = (sumv[lc] * bit[R - M] + sumv[rc]) % MOD;
    }
    if (setv[o] >= 0)
        sumv[o] = pre[R - L] * setv[o] % MOD;
}
void update(int o, int L, int R, int y1, int y2, int v)
{
    int lc = o * 2, rc = o * 2 + 1;
    if (y1 <= L && y2 >= R)
    {
        setv[o] = v;
    }
    else
    {
        pushdown(o);
        int M = (L + R) >> 1;
        if (y1 <= M)
            update(lc, L, M, y1, y2, v);
        else
            maintain(lc, L, M);
        if (y2 > M)
            update(rc, M + 1, R, y1, y2, v);
        else
            maintain(rc, M + 1, R);
    }
    maintain(o, L, R);
}
LL query(int o, int L, int R, int y1, int y2)
{
    if (setv[o] >= 0)
        return setv[o] * pre[min(R, y2) - max(L, y1)] % MOD;
    else if (y1 <= L && y2 >= R)
        return sumv[o];
    else
    {
        int M = (L + R) >> 1;
        LL ans;
        if (y1 <= M && y2 > M)
            ans = query(o * 2, L, M, y1, M) * bit[y2 - M] + query(o * 2 + 1, M + 1, R, M + 1, y2);
        else if (y1 > M)
            ans = query(o * 2 + 1, M + 1, R, y1, y2);
        else
            ans = query(o * 2, L, M, y1, y2);
        return ans % MOD;
    }
}
void build(int o, int L, int R)
{
    setv[o] = -1;
    if (L == R)
        sumv[o] = str[L - 1] - '0', setv[o] = sumv[o];
    else
    {
        int M = (L + R) >> 1;
        build(2 * o, L, M);
        build(2 * o + 1, M + 1, R);
        sumv[o] = (sumv[o * 2] * bit[R - M] + sumv[o * 2 + 1]) % MOD;
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &q1, &q2);
    scanf("%s", str);
    bit[0] = 1, pre[0] = 1;
    for (int i = 1; i <= n; i++)
        bit[i] = bit[i - 1] * base % MOD;
    for (int i = 1; i <= n; i++)
        pre[i] = (pre[i - 1] + bit[i]) % MOD;
    build(1, 1, n);
    q = q1 + q2;

    for (int i = 1; i <= q; i++)
    {
        int op, l, r, c;
        scanf("%d%d%d%d", &op, &l, &r, &c);
        if (op == 1)
            update(1, 1, n, l, r, c);
        else
        {
            // cout << query(1, 1, n, l, r-c) << endl << query(1, 1, n, l+c, r) << endl;
            if (query(1, 1, n, l, r - c) == query(1, 1, n, l + c, r))
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}
