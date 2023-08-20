#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int f[maxn], n, m;
int find(int x){
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y){
    if (find(x) != find(y)) f[find(x)] = find(y);
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) f[i] = i;
    while (m--){
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) merge(x, y);
        else {
            if (find(x) == find(y)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}