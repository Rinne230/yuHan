#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
typedef unsigned long long ull;
vector<int> prime;
int vis[5001], cnt;
void getprime(){
    for (int i = 2; i <= 4500; ++i){
        if (!vis[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] <= 4500; ++j){
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

ll cbr(ll x){
    return 1ll * x * x * x;
}

bool check(ll x){
    ll a = (int)sqrt(x);
    if (1ll * a * a == x) return 1;
    ll b = (int)cbrt(x);
    if (cbr(b) == x || cbr(b - 1) == x || cbr(b + 1) == x) return 1;
    return 0;
}

void solve(){
    ll n;
    cin >> n;
    for (int i = 0; i < prime.size(); ++i){
        ll cur = 0, x = prime[i];
        if (n % x == 0)
            while (n % x == 0){
                n /= x;
                cur++;
            }
        if (cur == 1){
            cout << "no" << endl;
            return;
        }
    }
    if (check(n))
        cout << "yes" << endl;
    else
        cout << "no" << endl;   
}

int main(){
    int t;
    cin >> t;
    getprime();
    while (t--) solve();
    return 0;
}