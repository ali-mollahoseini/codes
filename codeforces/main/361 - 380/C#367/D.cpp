//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000 * 100 * 40 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int nx[MX][2],val[MX],cnt,q;
void add(int x){
    int p = 0;
    for(int i=30;i+1;i--){
        if(nx[p][x>>i&1]==-1)nx[p][x>>i&1]=++cnt;
        p=nx[p][x>>i&1],val[p]++;
    }
}
void  del(int x){
    int p = 0;
    for(int i=30;i>=0;i--){
        if(nx[p][x>>i&1]==-1)nx[p][x>>i&1]=++cnt;
        p=nx[p][x>>i&1],val[p]--;
    }
}
int get(int x){
    int p = 0,ret=0;
    for(int i=30 ;i>=0;i--){
        if(nx[p][x>>i&1^1]!=-1 && val[nx[p][x>>i&1^1]]>0){
            ret+=(1<<i),p=nx[p][x>>i&1^1];
        }else{
            p=nx[p][x>>i&1];
        }
    }
    return ret;
}
int32_t main(){
    Init
    memset(nx,-1,sizeof nx);
    add(0);
    cin>>q;
    req(i,0,q){
        char t;
        int x;
        cin>>t>>x;
        if(t=='+')add(x);
        if(t=='-')del(x);
        if(t=='?')cout<<get(x)<<endl;
    }
}


