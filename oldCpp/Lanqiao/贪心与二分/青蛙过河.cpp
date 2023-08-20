#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
int n, x;
int a[M];

bool check(int mid){
    int sum = 0;
    for (int i = 1; i <= min(n - 1, mid); ++i) sum += a[i];
    if (sum < x) return 0;
    for (int i = mid + 1; i <= n - 1; ++i){
        sum -= a[i - mid];
        sum += a[i];
        if (sum < x)return 0;
    }   
    return 1;
}

int main(){
    cin >> n >> x;
    x <<= 1;
    for (int i = 1; i <= n - 1; ++i) cin >> a[i];
    int l = 0, r = n;
    while (l + 1 != r){
        int mid = (l + r) >> 1;
        if (check(mid))
             r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}