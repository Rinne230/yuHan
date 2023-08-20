#include <bits/stdc++.h>
using namespace std;
const int N = 111;
long long n, m, f[12][5111], v[5111], cnt;
//数字1表示竖着放置。0表示横放置
int main()
{
    while (cin >> n >> m)
    {
        if (!(n | m))
            return 0;
        memset(v, 0, sizeof(v));
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 0; i < (1 << m); i++)
        {
            cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (i & (1 << j))
                {
                    if (cnt & 1)
                    { // 左右的0成对出现
                        v[i] = 1;
                        break;
                    }
                    cnt = 0;
                }
                else
                    cnt++;
            }
            if (cnt & 1)
                v[i] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < (1 << m); j++)
            {
                for (int r = 0; r < (1 << m); r++)
                {
                    if (j & r)
                        continue; // 上下不能都为1
                    if (v[j | r])
                        continue; // 左右的0成对出现
                    f[i][j] += f[i - 1][r];
                }
            }
        }
        cout << f[n][0] << "\n"; // 最后一行全为0
    }
}
