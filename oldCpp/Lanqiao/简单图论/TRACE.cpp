#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 0x3f3f3f3f
#define N 2025
int edges[N][N];
int d[N];
bool vis[N];

int gcd(int a, int b){return b==0? a : gcd(b, a%b);}
int lcm(int a, int b){return a / gcd(a, b) * b;}
int main(){
    memset(edges, INF, sizeof(edges));//edges数组所有元素初始化为INF
    //邻接矩阵
	for(int i = 1;i<N;i++){
        edges[i][i] = 0;
        for(int j = i+1;j < N;j++){
            int w = lcm(i, j);
            edges[i][j] = edges[j][i] = w;
        }
    }
    memset(d, INF, sizeof(d));  //d数组所有元素初始化为INF
    memset(vis, false, sizeof(vis));    //vis数组所有元素初始化为false
    d[1] = 0;
    //Dijkstra
    for(int i = 1;i < N;i++){
        int x = 0;  //找到下一个未确定的最短路径的点
        for(int j = 1;j<N;j++) if(!vis[j] && d[j] < d[x]) x= j;
        vis[x] =1;//标记为已确定
        for(int j = max(1, x-21); j<=min(N, x +21);j++){    //用该点更新连通的点
            d[j] = min(d[j] , d[x] + edges[x][j]);
        }
    }
    cout<< d[2021] <<endl;
    return 0;
}
