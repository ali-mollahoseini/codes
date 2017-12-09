//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 3*1000+10,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
string word;
int n;
string  mat[MX];
bool mark[MX][MX];
void bfs(){
    vector<pair<char,int> > cur;
    vector<pair<char,int> > nex;
    cur.pb({mat[0][0],0});
    for(int i=0;i<n;i++){
        sort(cur.begin(),cur.end());
        char f= cur[0].F;
        //cout<<cur.size()<<endl;
        word.pb(f);
        for(int j =0;j<cur.size();j++){
            if(f == mat[i][cur[j].S]){
                if(!mark[i+1][cur[j].S]){
                    mark[i+1][cur[j].S]=1;
                    nex.pb({mat[i+1][cur[j].S],cur[j].S});
                }
                if(!mark[i+1][cur[j].S+1]){
                    mark[i+1][cur[j].S+1]=1;
                    nex.pb({mat[i+1][cur[j].S+1],cur[j].S+1});
                }
            }else{
                break;
            }
        }
        cur.clear();
        for(int i=0;i<nex.size();i++){
            cur.pb(nex[i]);
        }
        nex.clear();
    }
}
int32_t main() {
    int a, b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>mat[i];
    }
    bfs();
    cout<<word<<endl;
    return 0;
}

