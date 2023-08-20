#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+100;
int main(){
    string s;
    cin>>s;
    vector<string> str;
    string tem;
    s += "A";
    str.push_back("*");
    tem += s[0];
    for(int i = 1; i < s.size(); i++){
        if(s[i] >= 'A'&& s[i] <= 'Z'){
            str.push_back(tem);
            tem = "";
            tem += s[i];
        }else{
            tem += s[i];
        }
    }
    vector<string> q;
    vector<int> len;
    q.push_back(str[1]);
    len.push_back(1);
    for(int i = 2; i < str.size(); i++){
        if(str[i] > q.back()){
            q.push_back(str[i]);
            len.push_back(q.size());//len[i]以i结尾的最长不下降子序列长度
        }
        else{
            int l = lower_bound(q.begin(), q.end(), str[i]) - q.begin();
            q[l] = str[i];
            len.push_back(l + 1);
        }
    }
    vector<string> res;
    for(int i = str.size() - 1, m = q.size(); m > 0; i--){
        if(len[i] == m){
            res.push_back(str[i + 1]);
            m--;
        }
    }
    for(int i = res.size() - 1; i >= 0; i--) cout << res[i];
    return 0;
}
