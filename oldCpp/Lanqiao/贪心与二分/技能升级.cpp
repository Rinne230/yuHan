#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll ans;
struct node{
    ll a; 
    ll b;
    friend bool operator < (node a, node b){
        return a.a < b.a;
    }
}e[1001];

priority_queue<node> q;

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> e[i].a >> e[i].b; 
        q.push({e[i].a, e[i].b});
    }
    for (int i = 1; i <= m; ++i)
        if(!q.empty()){
            ans += q.top().a;
            node tmp = q.top();
            q.pop();
            if (tmp.a - tmp.b >= 0)
                tmp.a -= tmp.b;
            q.push(tmp);
        }
    cout << ans << endl;
    return 0;
}
