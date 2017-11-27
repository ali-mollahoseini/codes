//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX = 1000 + 1000, inf = 0x7FFFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
ofstream fout("moocast.out");
ifstream fin("moocast.in");
pair<int,int> inp[MX];
int  n, mark[MX];
int mat[MX][MX];
int adj[MX][MX];
void dfs(int u){
    mark[u]=1;
    for(int i=0;i<n;i++){
        if(!mark[i] && adj[u][i] ){
            dfs(i);
        }
    }
}
void build(int x){
    for(int i=0;i<n;i++){
        for(int j= i+1;j<n;j++){
            if(mat[i][j]<=x){
                adj[i][j]=1;
                adj[j][i]=1;
            }else{
                adj[i][j]=0;
                adj[j][i]=0;
            }
        }
    }
}
int bin(){
    int l=-1, r= 125*1000*1000*10+1;
    while(r-l>1){
        int mid =(l+r)/2;
        build(mid);
        dfs(0);
        bool tf=1;
        for(int i=0;i<n;i++){
            if(!mark[i]){
                tf=0;
            }
            mark[i]=0;
        }
        if(tf){
            r = mid;
        }else{
            l = mid;
        }
    }
    return r;
}
int32_t main(){
    ios::sync_with_stdio(0);
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>inp[i].F>>inp[i].S;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int val = abs(inp[i].F-inp[j].F)*abs(inp[i].F-inp[j].F) + abs(inp[i].S-inp[j].S)*abs(inp[i].S-inp[j].S);
            mat[i][j] =val;
            mat[j][i] =val;
        }
    }
    fout<<bin()<<endl;
}
