#include <iostream>
#include <cstring>
#define maxm 1205
using namespace std;
int g[maxm][maxm], d[maxm];
int t[maxm],vis[maxm];
int n, m;
int ans = 0;
void dfs(int i)
{
	for (int j = 1; j <= n; j++)
	{
		d[j] = g[i][j] + t[j];
	}
	vis[i] = 1;
	d[i] = 0;
	int k = 0;
	while (k < n)
	{
		int x = -1;
		int min = maxm;
		for (int j = 1; j <= n; j++)
		{
			if (vis[j] == 0 && d[j] < min)
			{
				x = j;
				min = d[j];
			}
		}
		if (x == -1)
			break;
		vis[x] = 1;
		for (int j = 1; j <= n; j++)
			if (vis[j] == 0 && d[j] > d[x] + g[x][j] + t[j])
				d[j] = d[x] + g[x][j] + t[j];
		k++;
	}
}
 
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
	}
	t[1] = 0;
	t[n] = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			g[i][j] = maxm;
		}
	for (int i = 1; i <= n; i++)
		    d[i] = maxm;
	for (int i = 0; i < m; i++)
	{
		int tx, ty, time;
		cin >> tx >> ty >> time;
		g[tx][ty] = g[ty][tx] = time;
	}
	dfs(1);
	cout <<d[n] << endl;
	return 0;
}