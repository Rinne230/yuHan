// HDU1536
// SG函数应用模版：
// 题意：给出s，表示可以移除的数目。
// 给出n，代表样例个数，每一个样例首先给出m-代表堆的个数。
// 可以看成是尼莫博弈，将每个堆的sg异或。
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxx 10005
#define maxn 110
using namespace std;
int f[maxn];
int sg[maxx];
bool mex[maxx];
void SG(int m)
{
    memset(sg, 0, sizeof(sg));
    for (int i = 1; i < maxx; i++)
    {
        memset(mex, false, sizeof(mex));
        for (int j = 0; j < m && f[j] <= i; j++)
            mex[sg[i - f[j]]] = true;
        for (int j = 0; j < maxx; j++)
        {
            if (!mex[j])
            {
                sg[i] = j;
                break;
            }
        }
    }
}

int main()
{
    int n, m, s;
    while (cin >> s)
    {
        if (s == 0)
            break;
        for (int i = 0; i < s; i++)
        {
            scanf("%d", &f[i]);
        }
        sort(f, f + s);
        SG(s);
        cin >> n;
        while (n--)
        {
            int ans = 0;
            cin >> m;
            for (int i = 0; i < m; i++)
            {
                int x;
                cin >> x;
                ans ^= sg[x];
            }
            if (ans)
                cout << 'W';
            else
                cout << 'L';
        }
        cout << endl;
    }
    return 0;
}
