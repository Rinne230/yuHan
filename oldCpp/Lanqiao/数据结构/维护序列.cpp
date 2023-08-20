#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 1000010
ll n, m, p;
int ls(int u){return u << 1;}
int rs(int u){return u << 1 | 1;}
int mid(int l, int r) {return (l + r) >> 1;}
struct Node{
    ll ad;
    ll mu = 1;
}tag[maxn * 4];
ll a[maxn], w[maxn * 4];
void pushup(int u){w[u] = (w[ls(u)] + w[rs(u)]) % p;}
void build(int u, int L, int R){
    if (L == R) {
        w[u] = a[L] % p;
        return;
    }
    int M = mid(L, R);
    build(ls(u), L, M);
    build(rs(u), M + 1, R);
    pushup(u);
}
bool inRange(int L, int R, int l, int r){return (l <= L) && (R <= r);}//判断[L,R]是否被[l,r]包含
bool outofRange(int L, int R, int l, int r){return (L > r) || (R < l);}//判断[L,R]是否与[l,r]完全无交集
void pushdown(int u, int L, int R){
    int M = mid(L, R);
    if (tag[u].mu != 1){
        tag[ls(u)].ad = tag[ls(u)].ad * tag[u].mu % p;
        tag[rs(u)].ad = tag[rs(u)].ad * tag[u].mu % p;
        tag[ls(u)].mu = tag[ls(u)].mu * tag[u].mu % p;
        tag[rs(u)].mu = tag[rs(u)].mu * tag[u].mu % p;
        w[ls(u)] = w[ls(u)] * tag[u].mu % p;
        w[rs(u)] = w[rs(u)] * tag[u].mu % p;
        tag[u].mu = 1;
    }
    if (tag[u].ad){
        w[ls(u)] = (w[ls(u)] + (M - L + 1) * tag[u].ad) % p;
        tag[ls(u)].ad = (tag[ls(u)].ad + tag[u].ad) % p;
        w[rs(u)] = (w[rs(u)] + (R - M) * tag[u].ad) % p;
        tag[rs(u)].ad = (tag[rs(u)].ad + tag[u].ad) % p;
        tag[u].ad = 0;
    }
}
ll query(int u, int L, int R, int l, int r){
    if (inRange(L, R, l, r)) return w[u];
    else if (!outofRange(L, R, l, r)){
        int M = mid(L, R);
        pushdown(u, L, R);
        return (query(ls(u), L, M, l, r) + query(rs(u), M + 1, R, l, r)) % p;
    }else return 0;
}
void update1(int u, int L, int R, int l, int r, ll k){
    if (inRange(L, R, l, r)){
        tag[u].mu = tag[u].mu * k % p;
        tag[u].ad = tag[u].ad * k % p;
        w[u] = w[u] * k % p;
        return;
    }else if (!outofRange(L, R, l, r)){
        int M = mid(L, R);
        pushdown(u, L, R);
        update1(ls(u), L, M, l, r, k);
        update1(rs(u), M + 1, R, l, r, k);
        pushup(u);
    }
}
void update2(int u, int L, int R, int l, int r, ll k){
    if (inRange(L, R, l, r)){
        tag[u].ad = (tag[u].ad + k) % p;
        w[u] = (w[u] + (R - L + 1) * k) % p;
        return;
    }else if (!outofRange(L, R, l, r)){
        int M = mid(L, R);
        pushdown(u, L, R);
        update2(ls(u), L, M, l, r, k);
        update2(rs(u), M + 1, R, l, r, k);
        pushup(u);
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; ++i){
        int op, x, y;
        ll k;
        cin >> op >> x >> y;
        if (op == 1){
            cin >> k;
            update1(1, 1, n, x, y, k);
        }else if (op == 2){
            cin >> k;
            update2(1, 1, n, x, y, k);
        }else{
            cout << query(1, 1, n, x, y) % p << endl;
        }
    }
    return 0;
}


