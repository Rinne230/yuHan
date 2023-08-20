#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 201;
typedef long long ll;

int x, y;
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    cin >> x >> y;
    bool flag = false;
    for (int i = 1; i <= k; ++i){
        int tx, ty;
        cin >> tx >> ty;
        if ((abs(tx - x) + abs(ty - y)) % 2 == 0){
            flag = true;
        }
    }
    if (flag) 
        cout << "NO" << endl; 
    else
        cout << "YES" << endl;
}

int main(){
   ios;
   int t;
   cin >> t;
   while(t--){
      solve();
   }
   return 0;
}