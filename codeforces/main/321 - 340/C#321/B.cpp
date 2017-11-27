//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 1000*100 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;
pair<int,int> inp[MX];
int mx,n,d;
int32_t main(){
    Init
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>inp[i].F>>inp[i].S;
    }
    sort(inp,inp+n);
    queue<pair<int,int> > q;
    int sum = 0;
    for(int i=0;i<n;i++){
        q.push(inp[i]);
        sum+=inp[i].S;
        while(q.front().F+d<=inp[i].F){
            sum-=q.front().S;
            q.pop();
        }
        mx = max(mx,sum);
    }
    cout<<mx<<endl;
}


