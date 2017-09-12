//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;

const int inf= 0x7F7FFFFF;
const int MX1 = 2000;
typedef pair<int,int> pii;
vector<pair<int, int> >que;
int n, m;
bool mark[MX1][MX1];
int head, tail;
int table[MX1][MX1];
pii ways[4] = {{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x, int y){
    int sum=0;
    for(int i=0 ;i<4 ;i++){
        //cout<<x+ways[i].F<<" "<<x+ways[i].F<<" ";
        if(x+ways[i].F<n && x+ways[i].F>-1 && y+ways[i].S<m && y+ways[i].S>-1 && table[x+ways[i].F][y+ways[i].S] ){
            //cout<<1<<endl;
            sum ++ ;
        }
    }
    if(sum > 1){
        return 1;
    }
    return 0;
}
bool ok(int x, int y){
    if(x<n && x>-1 && y<m && y>-1 && !mark[x][y] && check(x, y)){
        return 1;
    }
    return 0;
}
int bfs(){
    while(tail<head){
        pair<int,int> tmp= que[tail++];
        mark[tmp.F][tmp.S] = 1;
        for(int i = 0;i < 4;i++){
            if(ok(tmp.F+ways[i].F, tmp.S+ways[i].S) && !table[tmp.F+ways[i].F][tmp.S+ways[i].S] ){
                //cout<<1<<endl
                table[tmp.F+ways[i].F][tmp.S+ways[i].S] = 1;
                que.pb({tmp.F+ways[i].F, tmp.S+ways[i].S});
                mark[tmp.F+ways[i].F][tmp.S+ways[i].S] = 1;
                head++;
            }
        }
    }
}
int32_t main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='X'){
                table[i][j]=1;
                que.pb({i,j});
                head++;
            }
        }
    }
    bfs();
    cout<<que.size()<<endl;
}
