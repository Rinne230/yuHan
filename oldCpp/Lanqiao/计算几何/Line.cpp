#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double eps=1e-12;
struct point {  //定义点
    double x,y;
};
struct line {  //定义直线
    double a,b;
};
bool intersect(line L,line R) {   //判断两条直线是否相交
    if(fabs(L.a-R.a)<eps) {
        return false;
    }
    return true;
}
point inter_point(line L,line R) {  //求两条直线的交点
    point res;
    res.x=-(L.b-R.b)/(L.a-R.a);
    res.y=(L.a*R.b-L.b*R.a)/(L.a-R.a);
    return res;
}
bool collinear(point P,point C,point D) { //判断点P是否在线段CD上
    double CDx=D.x-C.x, CDy=D.y-C.y;
    double CPx=P.x-C.x, CPy=P.y-C.y;
    if(fabs(CPx)<eps && fabs(CPy)<eps) {  //P点与C点重合
        return true;
    }
    if(fabs(D.x-P.x)<eps && fabs(D.y-P.y)<eps) { //P点与D点重合
        return true;
    }
    if(fabs(CDy*CPx-CDx*CPy)<eps && P.x>=min(C.x,D.x) && P.x<=max(C.x,D.x) && P.y>=min(C.y,D.y) && P.y<=max(C.y,D.y)) {
        return true;
    }
    return false;
}
int main() {
    int k;
    cin>>k;
    while(k--) {
        int t;
        line L,R;
        point P,C,D;
        cin>>t;
        if(t==1) {
            cin>>L.a>>L.b>>R.a>>R.b;
            if(intersect(L,R)) {
                cout<<"yes"<<endl;
            } else {
                cout<<"no"<<endl;
            }
        } else if(t==2) {
            cin>>L.a>>L.b>>R.a>>R.b;
            if(intersect(L,R)) {
                point inp=inter_point(L,R);
                cout<<setprecision(2)<<fixed<<inp.x<<" ";
                cout<<setprecision(2)<<fixed<<inp.y<<endl;;
            } else {
                cout<<"no"<<endl;
            }
        } else if(t==3) {
            cin>>P.x>>P.y>>C.x>>C.y>>D.x>>D.y;
            if(collinear(P,C,D)) {
                cout<<"yes"<<endl;
            } else {
                cout<<"no"<<endl;
            }
        }
    }
    return 0;
}