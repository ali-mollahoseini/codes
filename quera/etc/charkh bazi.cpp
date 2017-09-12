///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1=100000+100;
const int inf= 0x7FFFFFFF;
using namespace std;
map<int,vector<int>  > adj;
int ways[2]= {-1,1};
int n;
int que[MX1];
int head,tail;
int dis[MX1];
int fst,lst;
bool mark[MX1];

int mod(int l);
int poww(int x, int y);
int in();
void pop(int v);
void push(int v);
void bfs(int v);

int32_t main(){
    for(int i=0;i<100000;++i){
        push(i);
    }
    fst = in();
    lst = in();
    cin >> n;
    for(int i=0;i<n;i++){
        pop(in());
    }
    bfs(fst);
    if(fst!=lst && !dis[lst]){
        cout <<  -1<<endl;
    }else {
        cout << dis[lst] << endl;
    }
}
void bfs(int v){
    dis[v]=0;
    mark[v] = 1;
    que[tail++] = v;
    while(head<tail){
        int tmp = que[head++];
        for(int i=0;i<adj[tmp].size();i++){
            int pt = adj[tmp][i];
            if(!mark[pt]){
                mark[pt] = 1;
                dis[pt] = dis[tmp] + 1;
                que[tail++] = pt;
            }
        }
    }
}
int in(){
    int ans=0;
    for(int i=1, u;i<6;i++){
        cin>>u;
        ans += u*poww(10,5-i);
    }
    return ans;
}
void pop(int v){
    for(int i=0;i<adj[v].size();i++){
        int tmp = adj[v][i];
        for(int j=0;j<adj[tmp].size();j++){
            if(adj[tmp][j] == v){
                adj[tmp].erase(adj[tmp].begin()+j);
                break;
            }
        }
    }
    adj.erase(v);
}
void push(int v){
    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            int md= (v/poww(10,i))%10;
            int nmd= mod(md+ways[j]);
            int x=v-md*poww(10,i)+nmd*poww(10,i);
            adj[v].pb(x);
        }
    }
}
int poww(int x, int y){
    if(y == 0){
        return 1;
    }
    int ans = poww(x,y/2);
    ans*=ans;
    if(y&1){
        ans*=x;
    }
    return ans;
}
int mod(int x){
    if(x<0){
        x+=10;
    }
    x%=10;
    return x;
}
