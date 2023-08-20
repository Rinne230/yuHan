#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll a[maxn];
ll ji[maxn], ou[maxn];

void solve(){
    int cnt1 = 0, cnt2 = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] % 2) ji[++cnt1] = a[i];
        else ou[++cnt2] = a[i];
    }
    sort(ji + 1, ji + cnt1 + 1);
    sort(ou + 1, ou + cnt2 + 1);
    for (int i = n; i >= 1; --i){
        if (a[i] % 2){
            if (ji[cnt1] < ou[cnt2]){
                cout << "NO" << endl;
                return;
            }
            cnt1--;
        }else{
            if (ou[cnt2] < ji[cnt1]){
                cout << "NO" << endl;
                return;
            }
            cnt2--;
        }
    }
    if (cnt1 == 0 && cnt2 == 0){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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