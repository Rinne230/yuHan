#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("test.txt","w",stdout);
    while(1){//拍到错为止
        system("datas.exe");
        system("testin.exe");
        system("testot.exe");
        double ed2=clock();
        if(system("fc right.txt wrong.txt")){
            printf("WA");return 0;//此时input.txt里就是错误数据
        }
    }
    return 0;
}
//生成名为check