///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 05 |
///    | 01 |   CF Round 431   | 10 |
///    +----+------------------+----+

#include <bits/stdc++.h>
//#define ll long long
#define usi unsigned short int
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*1000 + 1;
const int inf = 0x7FFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;

struct LinkEdge{
    int vert;
    int next;
};

LinkEdge edge[MX];//8MB
int FEdge[MX],n,m;//4MB
int FEdge2[MX];//4MB
bool mohavate[MX];//1MB
bool used[MX];//1MB
int poshte[MX],head;//4MB
int mark[MX];//4MB

void input (){
    cin>>n>>m;
    for(int i=0;i<MX;i++){
        FEdge[i]  = -1;
        FEdge2[i] = -1;
    }
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        edge[i].vert = --u;
        edge[i].next = FEdge[--v];
        FEdge[v]  = i;
        //cout<<u<<v<<endl;
    }
}
void revdfs(int v){
    mohavate[v] = 1;
    int ind = FEdge[v];
    while(ind != -1){
        int e = edge[ind].vert;
        if(!mohavate[e]){
            revdfs(e);
        }
        ind = edge[ind].next;
    }
    poshte[head++]=v;
}
//*
void rev(int v,int ind,int u){//v : tail
    edge[ind].vert = v;
    edge[ind].next = FEdge2[u];
    FEdge2[u] = ind;
}
void adjrev(int v){
    used[v]=1;
    int ind  = FEdge[v];
    while(ind != -1){
        int e = edge[ind].vert;
        //cout<<"E"<<v<<edge[ind].vert<<" "<<edge[ind].next<<endl;
        int indp;
        if(mohavate[e]){
            if(!used[e]){
                adjrev(e);
            }
            indp = edge[ind].next;
            rev(v,ind,e);
        }
        //cout<<"D"<<e<<" "<<edge[ind].vert<<" "<<ind<<" "<<FEdge2[e]<<" "<<edge[ind].next<<endl;
        ind = indp;
    }
}

void dfs(int v){
    used[v] = 1;
    //cout<<v<<" begin"<<endl;
    //cout<<v<<" "<<adj[v].size()<<endl;
    int ind = FEdge2[v];
    while(ind!= -1){
        int e = edge[ind].vert;
        //cout<<v<<" "<<e<<" "<<used[e]<<" ";
        if(mohavate[e]){
            if(!used[e]){
                //cout<<"1: "<< mark[v];
                //cout<<endl;
                mark[v]=36501;
                dfs(e);
            }else if(e==v){
                //cout<<2;
                //cout<<endl;
                mark[v]=36501;//loop
            }else{
                //cout<<"3: "<<mark[v]<<" "<<mark[e];
                //cout<<endl;
                mark[v]=min(36501,mark[v]+mark[e]);
            }
        }
        ind = edge[ind].next;
        //cout<<edge[v].next<<endl;
    }
    //cout<<"end"<<endl;
}
//*/
int32_t main(){
    Init
    input();
    revdfs(n);
    adjrev(n);
    for(int i=0;i<MX;i++){
        mark[i]=0;
        used[i]=0;
    }
    mark[n]=1;
    while(head){
        int b = poshte[--head];
        if(!used[b]){
            //cout<<b<<" ";
            dfs(b);
        }
    }
    //cout<<endl;
    int mx=0;
    int cntr=0;
    for(int i=0;i<n;i++){
        mx = max(mx, mark[i]);
    }
    if(mx<36500){
        cout<<mx<<endl;
    }else{
        cout<<"zawsze"<<endl;
    }
    for(int i=0;i<n;i++){
        if(mark[i]==mx){
            cntr++;
        }
    }
    cout<<cntr<<endl;
    for(int i=0;i<n;i++){
        if(mark[i]==mx){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    //*/
}
