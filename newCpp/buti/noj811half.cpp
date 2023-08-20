#include <bits/stdc++.h>
using namespace std;
int a[910], tot;
int main()
{
    for (int i = 0; i <= 30; i++)         // 预先处理出所有特殊数字
        for (int j = i + 1; j <= 30; j++) // i和j不同
            a[tot++] = (1 << i) + (1 << j);
    sort(a, a + tot); // 二分之前先排序
    int T;
    cin >> T;
    while (T--)
    {
        int x;
        cin >> x;
        int p = lower_bound(a, a + tot, x) - a; // 查找第一个大于等于x的位置p，即a[p]>=x
        int ans = 0;
        if (a[p] == x)
            ans = 0;
        else
        {
            ans = a[p] - x; // a[p]比x大
            if (p - 1 > 0)
                ans = min(ans, x - a[p - 1]); // 比x大和比x小的最近2个数
        }
        cout << ans << endl;
    }
    return 0;
}
