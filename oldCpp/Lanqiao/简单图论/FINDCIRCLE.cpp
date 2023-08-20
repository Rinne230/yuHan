#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int to[maxn], head[maxn], nxt[maxn], cnt, n, in[maxn];

void addedge(int u, int v){
    to[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

void topsort(){
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(in[i] == 1) q.push(i);
	}
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = nxt[i]){
			int v = to[i];
			in[v]--;
			if(in[v] == 1) q.push(v);
		}
	}
}

int main(){
    cin >> n;
    for (int i = 1, v, u; i <= n; ++i){
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
        in[u]++;
        in[v]++;
    }
    topsort();
    vector<int> ans;
    for(int i = 1; i <= n; i++)
	    if(in[i] == 2) 
            ans.push_back(i);
	for (int i = 0; i < ans.size(); i++){
		if(i == ans.size() - 1) cout << ans[i] << endl;
		else cout << ans[i] << " ";
	}
    return 0;
}