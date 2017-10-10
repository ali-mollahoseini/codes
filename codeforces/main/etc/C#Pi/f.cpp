///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 07 |
///    | 25 |   CF Round 436   | 03 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define old (0)
#define cur (1)
#define new (2)
#define pb push_back
#define Init ios::sync_with_stdio(0);

const int MX = 100 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n, k;
int dp[MX][MX]= {-1};

enum{
    Old,Cur,New
};
struct req{
    int x,y;
    string sign;
}reqs[MX];
int get_type(int l ,int r , int f,int s,int x){
    if(x<l|| x>r){
        return Old;
    }
    else if(x==s || x==f){
        return Cur;
    }
    return New;
}
bool compare(int a, int b,string s){
    if(s=="="){
        return (a==b);
    }else if(s==">"){
        return (a>b);
    }else if(s=="<"){
        return (a<b);
    }else if(s==">="){
        return (a>=b);
    }else if(s=="<="){
        return (a<=b);
    }
}
bool is_good(int l, int r , int f, int s){
    for(int i=0;i<k;i++){
        int x = get_type(l,r,f,s,reqs[i].x);
        int y = get_type(l,r,f,s,reqs[i].y);
        if(x!=Cur && y!= Cur )
            continue;
        if(!compare(x,y,reqs[i].sign)){
            return 0;
        }
    }
    return 1;
}
void mark(){
    for(int i=0;i<200;i++){
        for(int j =0;j<200;j++){
            dp[i][j]=-1;
        }
    }
}
int calcdp(int l,int r){
    int &ret = dp[l][r];
    if(ret!=-1){
        //cout<<ret<<' '<< l<< ' '<<r<<endl;
        //cout<<1<<endl;
        return ret;
    }
    ret = 0;
    if(l+1==r){
        if(is_good(l,r,l,r))
            ret++;
    }else{
        if(is_good(l,r,l,r)){
            ret+=calcdp(l+1,r-1);
        }
        if(is_good(l,r,r-1,r)){
            ret+=calcdp(l,r-2);
        }
        if(is_good(l,r,l,l+1)){
            ret+=calcdp(l+2,r);
        }
    }
    //dp[l][r]=ret;
    return ret;
}
int32_t main(){
    Init
    cin>>n>>k;
    n*=2;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<k;i++){
        cin>>reqs[i].x>>reqs[i].sign>>reqs[i].y;
        reqs[i].x--;reqs[i].y--;
    }
    cout<< calcdp(0,n-1);
}

