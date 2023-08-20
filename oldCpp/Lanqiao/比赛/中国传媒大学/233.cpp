#include<bits/stdc++.h>
using namespace std;
int n[205]={0};
char a[205][10005];
int m[205]={0};
string c[205][10005];
int w[205][10]={0};
int u[205][10]={0};
int b[205][10]={0};
int g[205][10]={0};
int r[205][10]={0};
int o[205][10]={0};


int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i];
        for(int j=1;j<=n[i];j++){
            cin>>a[i][j];
        }
        cin>>m[i];
        for(int j=1;j<=m[i];j++){
            cin >> c[i][j];

        }
    }
    //for(int i=1;i<=t;i++){
    //    for(int j=1;j<=n[i];j++){
    //        cout<<a[i][j]<<endl;
    //    }
    //}
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n[i];j++){
            if(a[i][j]=='W')w[i][1]++;
            if(a[i][j]=='U')u[i][1]++;
            if(a[i][j]=='B')b[i][1]++;
            if(a[i][j]=='G')g[i][1]++;
            if(a[i][j]=='R')r[i][1]++;
        }
        for (int j = 1; j <= m[i]; ++j){
            string str = c[i][j];
            for (int k = 0; k < str.length(); ++k){
            if(str[k] =='W')w[i][2]++;
            if(str[k]=='U')u[i][2]++;
            if(str[k]=='B')b[i][2]++;
            if(str[k]=='G')g[i][2]++;
            if(str[k]=='R')r[i][2]++;
            if(str[k]=='O')o[i][2]++;
            }
        }
            //if(c[i][j]=='W')w[i][2]++;
            //if(c[i][j]=='U')u[i][2]++;
            //if(c[i][j]=='B')b[i][2]++;
            //if(c[i][j]=='G')g[i][2]++;
            //if(c[i][j]=='R')r[i][2]++;
            //if(c[i][j]=='O')o[i][2]++;
    }
    //for(int i=1;i<=t;i++){
    //    cout<<w[i][1]<<u[i][1]<<b[i][1]<<g[i][1]<<r[i][1]<<w[i][2]<<u[i][2]<<b[i][2]<<g[i][2]<<r[i][2]<<o[i][2]<<endl;
    //}
    for(int i=1;i<=t;i++){
        if(w[i][1]>=w[i][2]){
            if(u[i][1]>=u[i][2]){
                if(b[i][1]>=b[i][2]){
                    if(g[i][1]>=g[i][2]){
                        if(r[i][1]>=r[i][2]){
                            if(w[i][1]+u[i][1]+b[i][1]+g[i][1]+r[i][1]-w[i][2]-u[i][2]-b[i][2]-g[i][2]-r[i][2]>=o[i][2]){
                                cout<<"YES"<<endl;
                            }
                            else cout<<"NO"<<endl; 
                        }
                        else cout<<"NO"<<endl; 
                    }
                    else cout<<"NO"<<endl; 
                }
                else cout<<"NO"<<endl; 
            }
            else cout<<"NO"<<endl; 
        }
        else cout<<"NO"<<endl; 
    }
    return 0;
}
