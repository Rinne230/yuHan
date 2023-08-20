#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int tim[maxn], dis[maxn], vis[maxn], h[maxn], hav[maxn], to[maxn << 1], nxt[maxn << 1], w[maxn << 1], cnt;
int n, m, k, t;

void add(int a, int b, int c){
    to[++cnt] = c;
    nxt[cnt] = h[a];
    w[cnt] = b;
    h[a] = cnt;
}

int spfa(){
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(hav[i]){
            q.push(i);
            vis[i] = true;
            dis[i] = 0;
        }
    }
 
    while(q.size()){
        int x = q.front();
        q.pop();
        vis[x] = false;
        for(int i = h[x]; i; i = nxt[i]){
            int z = to[i], y = w[i];
            if(hav[x] && hav[y]){
                hav[z] = true;
                int cost = max(dis[x], dis[y]) + max(tim[x], tim[y]);
                if(dis[z] > cost){
                    dis[z] = cost;
                    if(!vis[z]){
                        q.push(z);
                        vis[z] = true;
                    }
                }
            }
        }
    }
    return dis[t];
}

int main(){
    cin >> n >> m >> k >> t;
    for (int i = 1; i <= n; ++i) cin >> tim[i];
    for (int i = 1, x; i <= m; ++i){
        cin >> x;
        hav[x] = 1;
    }
    for (int i = 1, a, b, c; i <= k; ++i){
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    cout << spfa() << endl;
    return 0;
}