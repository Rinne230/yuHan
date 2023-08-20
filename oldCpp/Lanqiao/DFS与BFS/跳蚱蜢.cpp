#include <bits/stdc++.h>
using namespace std;
int to[4] = {-2, -1, 1, 2};
struct node{
    int step;
    string s;
};
string start = ".87654321";
string ed = ".12345678";
map<string, int> vis;

int bfs(){
    queue<node> q;
    node s;
    s.step = 0;
    s.s = start;
    q.push(s);
    while (!q.empty()){
        node temp = q.front();
        q.pop();
        if (temp.s == ed) return temp.step;
        int pos = temp.s.find(".");
        for (int i = 0; i < 4; ++i){
            string str = temp.s;
            int tpos = (pos + to[i] + 9) % 9;
            swap(str[pos], str[tpos]);
            if (vis[str] == 0){
                vis[str] = 1;
                s.s = str;
                s.step = temp.step + 1;
                q.push(s);
            }
        }
    }
}

int main(){
    int ans = bfs();
    cout << ans << endl;
    return 0;
}