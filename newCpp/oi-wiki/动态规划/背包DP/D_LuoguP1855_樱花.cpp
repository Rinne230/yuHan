#include <bits/stdc++.h>
using namespace std;
int a[10001], b[10001], c[10001], f[1000010], n, m;
int x1, yy, x2, y2;
int co[1000001], v[1000001], top;
void aaa()
{
	for (int i = 1; i <= n; i++)
	{
		int aa = 1;
		while (c[i] != 0)
		{
			co[++top] = a[i] * aa;
			v[top] = b[i] * aa;
			c[i] -= aa;
			aa *= 2;
			if (c[i] < aa)
			{
				co[++top] = a[i] * c[i];
				v[top] = b[i] * c[i];
				break;
			}
		}
	}
}
int main()
{
	scanf("%d:%d %d:%d", &x1, &yy, &x2, &y2);
	if (yy > y2)
	{
		y2 += 60;
		x2--;
	} 
	m = (x2 - x1) * 60 + y2 - yy;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		if (!c[i])
			c[i] = 9999999;
	}
	aaa();
	for (int i = 1; i <= top; i++)
		for (int j = m; j >= co[i]; j--)
			f[j] = max(f[j], f[j - co[i]] + v[i]);
	printf("%d\n", f[m]);
}