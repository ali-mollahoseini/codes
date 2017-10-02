//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define LSB(i) ((i)&(-i));

const int inf= 0x77FFFFFF;
const int MX = 1000*1000+10;
using namespace std;
int n;
pair<int,int> inp[MX];
map<int,int> mp;
int f[2][MX];///f[0]:1-i, f[1]:j-n;
int Fen[MX];
int  Fen_getsum(int ind){
    int sum = 0;
    while(ind){
        sum += Fen[ind];
        ind -= LSB(ind);
    }
    return sum;
}
void Fen_update(int ind,int delta){
    while(ind<n+1){
        //cout << ind << delta <<endl;
        Fen[ind] += delta;
        ind += LSB(ind);
    }
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie();
    cin>>n;
    for(int i=0,u;i<n;i++){
        cin>>u;
        inp[i].F = u,inp[i].S = i;
        mp[u]++;
    }
    sort(inp ,inp+n);
    int lst=-1,cnt;
    for(int i=0;i<n;i++){
        if(inp[i].F == lst){
            cnt++;
        }else{
            cnt=1;
            lst = inp[i].F;
        }
        f[0][inp[i].S]=cnt;
        f[1][inp[i].S]=mp[inp[i].F]-cnt+1;
        Fen_update(f[1][inp[i].S],1);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        //cout<<f[0][i]-1 << ' ' << f[1][i] <<endl;;
        Fen_update(f[1][i],-1);
        ans += Fen_getsum(f[0][i]-1);
    }
    cout<<ans<<endl;
}
