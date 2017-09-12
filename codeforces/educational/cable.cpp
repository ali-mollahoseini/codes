///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
//#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1=1000*1000;
const int inf= 0x7FFFFFFF;
using namespace std;
vector<int> anss;
int inp[MX1][2];
int n;
bool mark[MX1];

void fnd();
int diam(int v){
    if(n==1){
        return 0;
    }
    bool tf = 1;
    int mx = 0;
    while(tf){
        mark[v] = 1;
        tf=0;
        int ind=0;
        for(int i=0;i<n;i++){
            if(i!=v && !mark[i]){
                int tmp = abs(inp[i][0]-inp[v][0]) + abs(inp[i][1]-inp[v][1]);
                if(tmp>=mx){
                    tf = 1;
                    mx = tmp;
                    ind = i;
                }
            }
        }
        v = ind;
    }
    return mx;
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ;i < n;i++){
        cin >> inp[i][0] >> inp[i][1];
    }
    fnd();
    int ans=0;
    for(int i=0;i<anss.size();i++){
        ans= max(ans,diam(anss[i]));
    }
    cout<<ans<<endl;
    return 0;
}
void fnd(){
    int q[2]={-1,1};
    for(int i = 0;i<2;i++){
        for(int j=0;j<2;j++){
            int mn= inf;
            int ot = inf;
            int ind = -1;
            for(int k=0;k<n;k++){
                int tmp = q[j]*inp[k][i];
                if(tmp<mn){
                    mn = tmp;
                    ot = inp[k][(i+1)%2];
                    ind = k;
                }else if(tmp==mn && inp[k][(i+1)%2] < ot){
                    ot = inp[k][(i+1)%2];
                    ind = k;
                }
            }
            anss.pb(ind);
        }
    }
}
