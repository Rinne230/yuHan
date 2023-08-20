#include <bits/stdc++.h>
using namespace std;
int dx[4]={1, 0, -1, 0},dy[4]={0, 1, 0, -1};
int ans = 0;
int vis[7][7];
void DFS(int x, int y)
{
	if(x == 0 || x == 6 || y == 0 || y == 6){
		ans++;
		return;
	}		
	for(int i = 0; i < 4; i++){
		int newx = x + dx[i];
		int newy = y + dy[i];
		if(vis[newx][newy] == 0){
			vis[newx][newy] = 1;
			vis[6 - newx][6 - newy] = 1;
			DFS(newx, newy);
			vis[newx][newy] = 0;
			vis[6 - newx][6 - newy] = 0;
		}	                           
	}
}
int main()
{
	vis[3][3] = 1;
	DFS(3, 3);
	cout << ans / 4 << endl;//注意结果除以4
	return 0;
}