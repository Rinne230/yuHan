#include <bits/stdc++.h>
using namespace std;
struct dir {
    double fx,fy;
    dir operator - (const dir& v) const {
        return {fx - v.fx, fy - v.fy};
    }
    bool operator * (const dir& v) const {
        return fx * v.fy - fy * v.fx < 0;
    }
} S[4];
bool check(int u) {
    int a = (u + 1) % 3, b = (u + 2) % 3;
    dir x = S[3] - S[u], y =  S[u] - S[a], z = S[u] - S[b];
    return x * y != y * z;
}
void solve() {
    for(int i = 0; i < 4; i++) {
        cin >> S[i].fx >> S[i].fy;
    }
    for(int i = 0; i < 3; i++) {
        if(check(i)){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}