#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX = 100*1000 + 1000,inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
string x[MX];
vector<pair<int,int> > rev;
map<string,bool> mp;
map<string,int> val;
int mx;
void bfs(){
    val["123456789"]=0;
    queue<string>q;
    q.push("12345678");
    mp["12345678"]=1;
    while(!q.empty()){
        string tmp = q.front();q.pop();
        int va =val[tmp];
        for(int i=0;i<13;i++){
            string  tmp2 =tmp;
            reverse(tmp2.begin()+rev[i].F,tmp2.begin()+rev[i].S);
            if(!mp[tmp2]){
                q.push(tmp2);
                mp[tmp2]=1;
                val[tmp2]=va+1;
                mx =max(mx, va+1);
            }
        }
    }
}
int32_t main(){
    for(int i=0;i<7;i++){
        rev.pb({i,i+2});
    }for(int i=0;i<5;i++){
        rev.pb({i,i+4});
    }    }

    for(int i=0;i<1;i++){
        rev.pb({i,i+8});
    bfs();
    cout<<mx<<endl;
}
