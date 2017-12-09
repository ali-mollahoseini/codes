//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define pii pair<int,int>
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*100 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n,inp[MX];
bool mark[MX];
bool comp(pii a, pii b){
    if(a.F==b.F)
        return a.S>b.S;
    return a.F<b.F;
}
struct fenwick{
    vector<int> fen;
    fenwick(int N = MX):fen(N,0){}
    void upd(int k, int val){
        while(k<MX){
            fen[k]+=val;
            k+=(k&(-k));
        }
    }
    int query(int k){
        int ret= 0;
        while(k){
            ret+= fen[k];
            k-=k&(-k);
        }
        return ret;
    }
}fen;
pair<int,int> seg[MX*4];
void build(int id = 1,int l= 0, int r=n){
    if(r-l<2){
        seg[id]={inp[l],l};
        return;
    }
    int m= (l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m,r);
    seg[id] =max(seg[id*2],seg[id*2+1],comp);
}
int kth(int k){
    int l=k,r = n;
    while(r-l>1){
        int m =(r+l)/2;
        if(fen.query(m)>=k){
            r= m;
        }else{
            l =m;
        }
    }
    return r;
}
void upd(int ind, int id= 1, int l=0, int r=n){
    if(r-l<2){
        seg[id] = {0,ind};
        return;
    }
    int m= (l+r)/2;
    if(ind<m)
        upd(ind, val, id*2, l,m);
    else
        upd(ind, val, id*2+1, m,r);
    seg[id]=max(seg[id*2],seg[id*2+1],comp);
}
pii rmq(int l ,int r,int id= 1, int s=0, int e=n){
    if(e<=l || r<=s){
        return {0,n};
    }
    if(l<=s &&e<=r){
        return seg[id];
    }
    int m = (s+e)/2;
    pii ans1= rmq(l,r,id*2, s,m);
    pii ans2= rmq(l,r,id*2+1,m,e);
    return max(ans1,ans2,comp);
}
int32_t main(){
    Init
    int k;
    cin>>n>>k;
    vector<int> ans;
    for(int i=0;i<n;i++){
        fen.upd(i+1,1);
        cin>>inp[i];
    }
    build();
    for(int i=0;i<n && k ;i++){
        int r =kth(min(k,n));
        pair<int,int>  tmp = rmq(0,r);
        upd(tmp.S);
        mark[tmp.S]=1;
        ans.pb(tmp.F);
        fen.upd(tmp.S+1,-1);
        cout<<"r k "<<tmp.S<<' '<<k<<' '<<r<<' '<<tmp.F<<' ' << (n-fen.query(n)) - (i+1-fen.query(i+1))<<endl;
        //cout<<1<<endl8;
        k-=fen.query(tmp.S+1);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    for(int i=0;i<n;i++){
        if(!mark[i]){
            cout<<inp[i]<<' ';
        }
    }
}
