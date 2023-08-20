#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const double eps = 1e-8;
double f[maxn][maxn];
/*
(1-p1)*f[i][1]=p4+f[i][i]*p2;
if(j>=2&&j<=k) (1-p1)*f[i][j]=p4+p3*f[i-1][j-1]+p2*f[i][j-1];
else if (j>k) (1-p1)*f[i][j]=p3*f[i-1][j-1]+p2*f[i][j-1];
*/
double p[maxn], c[maxn];
int main()
{
    int n, m, k;
    double p1, p2, p3, p4;
    scanf("%d%d%d%lf%lf%lf%lf", &n, &m, &k, &p1, &p2, &p3, &p4);
    if (p4 < eps)
    {
        printf("0.00000\n");
        return 0;
    }
    double p41 = p4 / (1 - p1), p21 = p2 / (1 - p1), p31 = p3 / (1 - p1);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] * p21;//p[i]表示当排队的人数为i的时候，发生自己没有带饭卡而需要回去拿并且排到队伍末尾的概率
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            if (j <= k)
                c[j] = p31 * f[i - 1][j - 1] + p41;
            else
                c[j] = p31 * f[i - 1][j - 1];
        double temp = 0;
        for (int j = 1; j <= i; j++)
            temp += c[j] * p[i - j];
        f[i][i] = temp / (1 - p[i]);    
        f[i][1] = p41 + p21 * f[i][i];
        for (int j = 2; j <= i; j++)
        {
            f[i][j] = c[j] + p21 * f[i][j - 1];
        }
    }
    printf("%.5lf\n", f[n][m]);
}