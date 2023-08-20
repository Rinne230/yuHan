#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int n;
int main(){
    cin >> n;
    cout << "0";
    if (n)
    cout << ".";
    for (int i = 1; i <= n; ++i) cout << "0";
    return 0;
}