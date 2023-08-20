#include <bits/stdc++.h>
using namespace std;
#define maxn 105
#define maxm 200005
#define inf 600000005
#define ll long long
#define IOS ios::sync_with_stdio(false)

int ff[maxn][maxn];
int graph[maxn][maxn];
bool visited[maxn];
int n, m;


void dfs(int pre,int from)
{
    vis[from]=1;
    int sz=V[from].size();
    far(i,0,sz)
    {
        int v=V[from][i];
        if(pre==v||vis[v]==2)
            continue;
        if(vis[v]==1)
        {
            int l=0;
            int now=from;
            while(now!=v)
            {
                ++l;
                now=parent[now];
            }
            l++;
            len[cnt++]=l;
        }
        else
        {
            parent[v]=from;
            dfs(from,v);
        }
    }
    vis[from]=2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j)
                    ff[i][j] = inf, graph[i][j] = inf;
                else
                    ff[i][j] = 0, graph[i][j] = 0;

        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            ff[x][y] = graph[x][y] = z;
            // if(z<ff[x][y])
            // {
            //     ff[x][y]=z,ff[y][x]=z;
            //     graph[x][y]=z,graph[y][x]=z;
            // }
        }

        int ans = inf;
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i < k; i++)
                for (int j = i + 1; j < k; j++)
                    ans = min(ans, ff[i][j] + graph[j][k] + graph[k][i]);

            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (ff[i][k] + ff[k][j] <= ff[i][j])
                        ff[i][j] = ff[i][k] + ff[k][j];
        }
        if (ans == inf)
        {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        printf("%d ", ans);
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i] == 0)
            {
                dfs(0, i);
            }
        }
    }
    return 0;
}
