#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 1510;
int f[N][2];
int h[N],e[N*2],ne[N*2],idx;
void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u,int fa){
	f[u][0] = 0;
	f[u][1] = 1;
	for(int i=h[u];i!=-1;i=ne[i]){
		int j = e[i];
		if(j == fa) continue;
		dfs(j,u);
		f[u][0] += f[j][1];//他的子节点一定要有
		f[u][1] += min(f[j][0],f[j][1]);//可以有也可以没有
	}
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	while(~scanf("%d",&n)){
		memset(h,-1,sizeof h);
		idx=0;
		for(int i=1;i<=n;i++){
			int x,k,y;
			scanf("%d:(%d)",&x,&k);
			while(k--){
				scanf("%d",&y);
				add(x,y);
				add(y,x);
			}
		}
		dfs(0,0);
		int ans = min(f[0][0],f[0][1]);
		cout<<ans<<endl;
	}
	return 0;
}
