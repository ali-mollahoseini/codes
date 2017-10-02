//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int inf= 0x77FFFFFF;
const int MX = 2*1000*100+100;
using namespace std;
string s;
struct query{
    int t,l,r;
}q[MX];
int n , m , nq;
int a[MX],b[200];
int32_t main(){
    cin>>n>>nq>>m;
    for(int i=0;i<n;i++){cin>>a[i];}
    for(int i=0;i<nq;i++){cin>>q[i].t>>q[i].l>>q[i].r;}
    for(int i=0 ;i<m;i++){cin>>b[i];}
    for(int i=0;i<m;i++){
        int cur = b[i];
        //cout<<"cur"<<cur<<endl;
        for(int j=nq-1;j>=0;j--){
            if(q[j].l<=cur && q[j].r>=cur){
                    if(q[j].t==1){
                        cur--;
                        //cerr<<"a"<<endl;
                        if(cur<q[j].l){cur = q[j].r;}
                    }else{
                        //cerr<<"b"<<endl;
                        int dis = abs(q[j].l-cur);
                        cur = q[j].r - dis;
                    }
            }
        }
        //cout<<"cur"<<cur<<endl;
        cout<<a[cur-1]<<endl;
    }
}
