//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 4*1000*100+1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n , m, mn[MX];
pair<int,int>inp[MX];
bool comp(pair<int,int>  a, pair<int,int> b){
    int la = a.S-a.F,lb = b.S-b.F;
    return la<lb;
}
int32_t main(){
    Init
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>inp[i].F>>inp[i].S;
        inp[i].F=inp[i].F*2-1;
        inp[i].S=inp[i].S*2-1;
        if(inp[i].F>inp[i].S){
            swap(inp[i].F,inp[i].S);
        }
    }
    sort(inp,inp+m,comp);
    for(int i=0;i<m;i++){
        int mm = (inp[i].S+inp[i].F)/2;
        int dis =(inp[i].S-mm+1)/2;
        //cout<<mm<<' '<<dis<<' '<<inp[i].F<<' '<<inp[i].S<<endl;
        if(mn[mm]+1==dis){
            mn[mm]++;
        }
    }
    int mx=1;
    for(int i=1;i<2*n+1;i++){
        if(i%2){
            mx = max(mn[i]*2+1,mx);
        }else{
            mx = max(mn[i]*2,mx);
        }
    }
    cout<<mx<<endl;
}


