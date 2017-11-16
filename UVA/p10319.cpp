//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define rep(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 200 + 10,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
vector<int>adj[MX];
vector<int>revadj[MX];
int mark[MX],comp[MX];
stack<int> stk;
void dfs(int u){
    mark[u]=1;
    for(auto v: adj[u]){
        revadj[v].pb(u);
        if(!mark[v]){
            dfs(v);
        }
    }
    stk.push(u);
}
void revdfs(int  u,int col){
    comp[u]=col;
    for(auto v:revadj[u]){
        if(!comp[v]){
            revdfs(v,col);
        }
    }
}
void add(int s1,int s2, int a1, int a2){
    if(a1>a2){
        s1^=1;
        s2^=1;
    }
    if(s1>s2){
        a1^=1;
        a2^=1;
    }
    if(a1==a2){
        adj[a1^1].pb(a2);
    }
    if(s1==s2){
        adj[s1^1].pb(s2);
    }
    if(s1!=s2&&a1!=a2){
        adj[s1^1].pb(a1);
        adj[a1^1].pb(s1);

        adj[s2^1].pb(a2);
        adj[a2^1].pb(s2);

        adj[a1^1].pb(a2);
        adj[a2^1].pb(a1);

        adj[s2^1].pb(s1);
        adj[s1^1].pb(s2);    }
}
int32_t main(){
    Init
    int tc;
    cin>>tc;
    rep(k,0,tc){
        //fout<<"num :"<<k<<endl;
        int s,a,q;
        cin>>s>>a>>q;
        //fout<<s<<' '<<a<<' '<<q<<endl;
        rep(i,0,q){
            int s1,a1,a2,s2;
            cin>>s1>>a1>>s2>>a2;
            //fout<<s1<<' '<<a1<<' '<<s2<<' '<<a2<<endl;;
            s1--;s2--;a1--;a2--;
            a1*=2;a2*=2;s1*=2;s2*=2;
            s1+=a*2;
            s2+=a*2;
            add(s1,s2,a1,a2);
        }
        rep(i,0,(s+a)*2){
            if(!mark[i]){
                dfs(i);
            }
        }
        int cntr=1;
        while(!stk.empty()){
            int tmp = stk.top();stk.pop();
            if(!comp[tmp]){
                revdfs(tmp,cntr++);
            }
        }
        bool tf=1;
        rep(i, 0 , s+a ){
            if(comp[i*2]==comp[(i*2)^1]){
                tf=0;
            }
        }
        if(tf)  cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
        rep(i,0,200){
            adj[i].clear();
            revadj[i].clear();
            mark[i]=0;
            comp[i]=0;
        }
    }
}


