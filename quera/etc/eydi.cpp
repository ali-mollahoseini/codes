//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
//#define  long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1=4000;
const int inf= 0x7FFFFFFF;
using namespace std;


int n , m;
char inp[MX1][MX1];
map<pair<int,int>, vector<pair<int,int> > > adj;

int  in[MX1][MX1];
bool mark[MX1][MX1];
int  len[MX1][MX1];
int dfs(pair<int,int> u, int depth){
    mark[u.F][u.S]=1;
    len[u.F][u.S] = max(depth,len[u.F][u.S]);
    depth = len[u.F][u.S];
    for(int i=0 ;i<adj[u].size();i++){
        pair<int,int> pt = adj[u][i];
        --in[pt.F][pt.S];
        len[pt.F][pt.S] = max(depth+1,len[pt.F][pt.S]);
        if(!in[pt.F][pt.S]){
            dfs(pt,depth+1);
        }
    }
}
bool ok(int y,int x, char c){
    if(x>-1 && y>-1){
        if(inp[y][x]==c){
            return 1;
        }
    }
    return 0;
}
void adjset(){
    pair<int,int> ways[4]= {{1,0},{-1,0},{0,1},{0,-1}};
    map<char,char> tail;
    tail['E']='Y';
    tail['Y']='D';
    tail['D']='I';
    tail['I']='E';
    char lst[4] = {'E','Y','D','I'};
    for(int a = 0;a < 4;a++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k =0;k<4;k++){
                    int y = i + ways[k].F, x = j + ways[k].S;
                    if(inp[i][j]==lst[a] && (inp[i][j]=='E' || in[i][j]) && ok(y, x, tail[inp[i][j]] )){
                        adj[{i,j}].pb({y,x});
                        in[y][x]++;
                    }
                }
            }
        }
    }
}
int mxMat(){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans= max(ans, len[i][j]);
            /*if(ans==13){cout<<i<<" "<< j<<endl;
                break;
            }*/
        }
    }
    return ans;
}
int32_t main(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> inp[i][j];
        }
    }
    adjset();
    bool tf =1;
    bool e = 1;
    while(tf){
        tf=0;
        e=0;
        for(int i=0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(inp[i][j]=='E' && !mark[i][j] && !in[i][j]){
                    dfs({i, j},1);
                    tf=1;
                }else if(inp[i][j]=='E' && !mark[i][j]){
                    //cout<<i<<" "<<j<<endl;
                    e=1;
                }
            }
        }
    }
    int ans=mxMat();
    //cout<<ans<<endl;
    if(e){
        cout << "Poor Uncle!" << endl;
    }else if((ans/4)==0){
        cout << "Poor Mobin!" << endl;
    }else {
        cout << ans/4 << endl;
    }
}
