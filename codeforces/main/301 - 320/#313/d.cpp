///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 05 |
///    | 15 |   CF Round 431   | 24 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 2*100*1000 + 10;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
string s,t;
string out;
void merg2(int st, int ed){
    int mid=(st+ed)/2;
    int pnt1=st,pnt2=mid,ind=st;
    while(pnt1<mid&&pnt2<ed){
        if(s[pnt1]>s[pnt2]){
            out[ind++]=s[pnt2++];
        }
        else{
            out[ind++]=s[pnt1++];
        }
    }
    while(pnt1<mid){
        out[ind++]=s[pnt1++];
    }
    while(pnt2<ed){
        out[ind++]=s[pnt2++];
    }
    for(int i=st; i<ed; i++){
        s[i]=out[i];
    }
}
void merg1(int st, int ed){
    int mid=(st+ed)/2;
    int pnt1=st,pnt2=mid,ind=st;
    while(pnt1<mid&&pnt2<ed){
        if(t[pnt1]>t[pnt2]){
            out[ind++]=t[pnt2++];
        }
        else{
            out[ind++]=t[pnt1++];
        }
    }
    while(pnt1<mid){
        out[ind++]=t[pnt1++];
    }
    while(pnt2<ed){
        out[ind++]=t[pnt2++];
    }
    for(int i=st; i<ed; i++){
        t[i]=out[i];
    }
}
bool dandc(int l, int r,int l1,int r1){
    int dis = r-l;
    if((r-l)%2==1){return s.substr(l,dis) == t.substr(l1,dis);}
    int m = (r+l)/2;
    int m1 = (r1+l1)/2;
    dis = r-m;
    bool tk=0;
    bool t1 = dandc(l,m,l1,m1);
    bool t2 = dandc(m,r,m1,r1);
    bool t3 = dandc(l,m,m1,r1);
    bool t4 = dandc(m,r,l1,m1);
    if(t1 && t2 ){
        tk = 1;
    }else if(t3 && t4){
        tk = 1;
    }
    //cout<<1<<endl;
    return tk;
}
int32_t main(){
    Init
    cin>>s>>t;
    out = s;
    if(dandc(0,s.size(),0,t.size())){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
