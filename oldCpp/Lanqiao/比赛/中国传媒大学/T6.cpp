#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define ll long long
ll a[maxn], b[maxn], sum[maxn << 2], sum1[maxn << 2];
void pushup(int rt)
{
    sum[rt] = max(sum[2 * rt], sum[2 * rt + 1]);
    sum1[rt] = min(sum1[2 * rt], sum1[2 * rt + 1]);
}
void build(int l, int r, int rt)
{
    if (l == r)
    {
        sum1[rt] = b[l];
        sum[rt] = b[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * rt);
    build(mid + 1, r, 2 * rt + 1);
    pushup(rt);
}
int qurry(int x, int y, int l, int r, int rt)
{
    if (x <= l && y >= r)
    {
        return sum[rt];
    }
    int mid = (l + r) / 2;
    int ret = -1234567899;
    int ret1 = -1234567899;
    if (x <= mid) ret = max(ret, qurry(x, y, l, mid, 2 * rt));
    if (y > mid) ret1 = max(ret1, qurry(x, y, mid + 1, r, 2 * rt + 1));
    return max(ret1, ret);
}

int qurry1(int x, int y, int l, int r, int rt)
{
    if (x <= l && y >= r)
    {
        return sum1[rt];
    }
    int mid = (l + r) / 2;
    int ret = 1234567899;
    int ret1 = 1234567899;
    if (x <= mid) ret = min(ret, qurry1(x, y, l, mid, 2 * rt));
    if (y > mid) ret1 = min(ret1, qurry1(x, y, mid + 1, r, 2 * rt + 1));
    return min(ret1, ret);
}
int main()
{
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)scanf("%lld%lld",&a[i], &b[i]);
    build(1, n, 1);
    cin >> q;
    while (q--){    
        ll x, y;
        cin >> x >> y;
        int h = abs(qurry(x, y, 1, n, 1) - qurry1(x, y, 1, n, 1));
        cout << h * abs(a[x] - a[y]) << endl;
    }
    return 0;
}