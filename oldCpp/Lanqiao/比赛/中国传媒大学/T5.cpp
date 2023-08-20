#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 9;
int start;
bool st[N];

int bfs() {
    queue<int> q;
    q.push(start);
    st[start] = true;
    int step = 0;
    while (!q.empty()) {
        int siz = q.size();
        while(siz--){
            int t = q.front();
            q.pop();
            if (t == 0) return step;
            for (int i = 0; i < 9; i++) {
                int x = i / 3, y = i % 3;
                int tt = t;
                tt ^= (1 << i);
                if (x > 0) tt ^= (1 << (i - 3));
                if (x < 2) tt ^= (1 << (i + 3));
                if (y > 0) tt ^= (1 << (i - 1));
                if (y < 2) tt ^= (1 << (i + 1));
                if (!st[tt]) {
                    //cout << step << endl;
                    // for (int i = 0; i < 9; ++i){
                    //     if (tt & (1 << i)) cout << "1";
                    //     else cout << "0"; 
                    //     if ((i + 1) % 3 == 0) cout << endl;
                    // }
                    q.push(tt);
                    st[tt] = true;  
                }
            }
        }
        step++;
    }
    return -1;
}

int main() {
    int x;
    for (int i = 0; i < 9; i++) {
        cin >> x;
        if (x) start += (1 << i);
    }
    cout << bfs() << endl;
    return 0;
}
