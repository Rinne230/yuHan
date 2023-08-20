#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 1, data; i <= 100; ++i){
        cin >> data;
        while (data % 2 == 0){
            data /= 2;
            cnt1++;
        }
        while (data % 5 == 0){
            data /= 5;
            cnt2++;
        }
    }
    ans = min(cnt1, cnt2);
    cout << ans << endl;
    return 0;
}
