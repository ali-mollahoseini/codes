//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*100 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n;
struct dsu{
    int mx = 0;
    vector<int> sum,rank,p,mark;
    dsu(int N=MX){
        p.assign(N,0);rank.assign(N,0);sum.assign(N,0);mark.assign(N,0);
        for(int i=0;i<N;i++){
            p[i]=i;
        }
    }
    int par_k(int x){return ((p[x]==x)? x:p[x]=par_k(p[x]));}
    void Union(int y, int x){
        //cout<<x<<' '<<y<<endl;
        int px= par_k(x), py=par_k(y);
        if(px!=py && mark[y] && mark[x]){
            if(rank[px]>rank[py]){
                p[py]=px;
                sum[px]+=sum[py];
                mx= max(mx, sum[px]);
            }else{
                p[px]=py;
                sum[py]+=sum[px];
                mx = max(mx,sum[px]);
                if(rank[px]==rank[py])
                    rank[py]++;
            }
        }else if(mark[x]){
            mx= max(sum[px],mx);
        }
        mx= max(sum[py],mx);
    };
};
int32_t main(){
    Init
    dsu ds;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ds.sum[i];
    }
    vector<int>rev;
    vector<int>ans;
    req(i,0,n){
        int x;
        cin>>x;
        rev.pb(x);
    }
    while(!rev.empty()){
        int tmp = rev.back();rev.pop_back();
        ds.mark[tmp]=1;
        ds.Union(tmp,tmp+1);
        ds.Union(tmp,tmp-1);
        ans.pb(ds.mx);
    }
    while(!ans.empty()){
        cout<<ans.back()<<endl;
        ans.pop_back();
    }
}



