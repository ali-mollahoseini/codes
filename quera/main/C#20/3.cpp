#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=1000*100+10;
const int MX2= 39;
const int inf=0x7FFFFFFF;
int n;
map<int,vector<int> > adj;
int ras[2];
int dis;
bool visited[MX1];
void dfs(int v,int deph){
    if(visited[v]==1){
        return ;
    }
    visited[v]=1;
    for(int i=0;i<adj[v].size();i++){
        if(adj[v][i]==ras[1]-1){
            dis=deph;
        }else if(visited[adj[v][i]]==0){
            dfs(adj[v][i],deph+1);
        }
    }
    return;
}
int main (){
    dis=inf;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    cin>>ras[0]>>ras[1];
    dfs(ras[0]-1,0);
    if(dis%2==0){
        cout<<"karakter e komaki_2";
    }else{
        cout<<"karakter e komaki_1";

    }
}
