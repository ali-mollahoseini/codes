//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=100+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
map<char,vector<char> > adj;
map<char,int > head;
map<int,bool >used;
string inp[MX1];
vector<char> lans;
void dfs(char v){
    used[v]=1;
    lans.pb(v);
    for(int i=0;i<adj[v].size();i++){
        head[adj[v][i]]--;
        if(head[adj[v][i]]==0&&used[adj[v][i]]==0){
            dfs(adj[v][i]);
        }
    }
}
void topoSort(){
    bool tf=1;
    while(tf){
        tf=0;
        for(int i=0;i<26;i++){
            if(head['a'+i]==0&&used['a'+i]==0){
                //cerr<<"topo"<<endl;
                dfs('a'+i);
                tf=1;
            }
        }
    }
}
int lcp(string str1, string str2){
    int ans=0;
    while(str1[ans]==str2[ans]){
        ans++;
    }
    return ans;
}
int32_t main(){
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    for(int i=0;i<26;i++){
        head['a'+i]=0;
        adj['a'+i].clear();
    }
    for(int i=1;i<n;i++){
        int tmp= lcp(inp[i-1], inp[i]);
        if(tmp==inp[i-1].size()){
            continue;
        }else if(inp[i].size()<inp[i-1].size()&&tmp==inp[i].size()){
            //cerr<<1<<endl;
            cout<<"Impossible"<<endl;
            return 0;
        }else {
            //cerr<<tmp<<endl;
            adj[inp[i-1][tmp]].pb(inp[i][tmp]);
            head[inp[i][tmp]]++;
        }
    }
    topoSort();
    //cerr<<lans.size()<<endl;
    if(lans.size()==26){
    for(int i=0;i<lans.size();i++){
        cout<<lans[i];
    }
    cout<<endl;
    }else {
        //cerr<<2<<endl;
        cout<<"Impossible"<<endl;
    }
    return 0;
}
