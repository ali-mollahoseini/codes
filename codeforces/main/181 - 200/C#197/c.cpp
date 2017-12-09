//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1<<20 ,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int seg[MX],inp[MX],n,q;
int xorr(bool tf, int a, int b){
    if(tf){
        return a|b;
    }else{
        return a^b;
    }
}
void bld(bool tf, int id =1, int l =0, int r= n){
    if(r-l<2){
        seg[id]=inp[l];
        return;
    }
    int mid= (l+r)/2;
    bld(!tf,id*2,l,mid);
    bld(!tf,id*2+1,mid,r);
    seg[id]=xorr(tf,seg[id*2],seg[id*2+1]);
}
void upd(bool tf,int ind, int val,int id=1,int l =0, int r=n){
    if(r-l<2){
        seg[id]=val;
        return ;
    }
    int mid =(l+r)/2;
    if(ind<mid){
        upd(!tf,ind,val,id*2,l,mid);
    }else{
        upd(!tf,ind,val,id*2+1,mid,r);
    }
    seg[id]=xorr(tf,seg[id*2],seg[id*2+1]);
}
int32_t main(){
    Init
    cin>>n>>q;
    bool tf= n%2;
    n=1<<n;
    req(i,0,n)
        cin>>inp[i];
    bld(tf);
    req(i,0,q){
        int p , b;
        cin>>p>>b;
        upd(tf,p-1,b);
        cout<<seg[1]<<endl;
    }
}


