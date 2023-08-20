#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;

int qmi(int m, int k){
    int res = 1, t = m;
    while(k){
        if (k & 1) res = res * t;
        t = t * t;
        k >>= 1;
    }
    return res;
}

int main(){
    ios;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        bool flag = false;
        for (int k = 2; k <= sqrt(n); ++k){
            for (int m = 1; qmi(k, m) <= n * (k - 1) + 1; ++m)
                if ((n * (k - 1) + 1) == qmi(k, m)){
                    flag = true;
                    break;
                }
            if (flag) break;
        }
        if (!flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}