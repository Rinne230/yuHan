#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector <int> G[100010];
int sg[100010];
int dfs(int x, int f)
{
	if(sg[x] != -1)
		return sg[x];
	if(!G[x].size())
		return 0;
	int ans = 0;
	for(int i = 0; i < G[x].size(); i++)
	{
		int v = G[x][i];
		if(v == f)
			continue;
	ans ^= dfs(v, x)+1;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(sg, -1, sizeof(sg));
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			G[i].clear();
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int ans = dfs(1, -1);
		if(ans)
			puts("Alice");
		else
			puts("Bob");
	}
	return 0;
}