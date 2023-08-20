#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
int T, N, M;
int cnt[6], cost[7];

int main(){
    IOS;
    cin >> T;
    while (T--){
        memset(cnt, 0, sizeof(cnt));
        memset(cost, 0, sizeof(cost));
        cin >> N;
        for (int i = 1; i <= N; ++i){
            char ch;
            cin >> ch;
            if (ch == 'W') cnt[1]++;
            else if (ch == 'U') cnt[2]++;
            else if (ch == 'B') cnt[3]++;
            else if (ch == 'G') cnt[4]++;
            else cnt[5]++;
        }
        cin >> M;
        for (int i = 1; i <= M; ++i){
            string str;
            cin >> str;
            for (int i = 0; i < str.length(); ++i){
                if (str[i] == 'W') cost[1]++;
                else if (str[i] == 'U') cost[2]++;
                else if (str[i] == 'B') cost[3]++;
                else if (str[i] == 'G') cost[4]++;
                else if (str[i] == 'R') cost[5]++;
                else cost[6]++;
            }
        }
        bool flag = true;
        for (int i = 1; i <= 5; ++i){
            if (cost[i] > cnt[i]){
                flag = false;
                break;
            }else{
                cnt[i] -= cost[i];
            }
        }
        int sum = 0;
        for (int i = 1; i <= 5; ++i)
            sum += cnt[i];
        if (cost[6] > sum) flag = false;
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}