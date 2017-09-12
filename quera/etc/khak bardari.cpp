///in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX1 = 100+100;
const int inf = 0x7FFFFFFF;
using namespace std;

set<pair<int ,pair<int, int> > > st;//s.F is more and s.S is less
int n , x , y , z;
pair<int ,int> inp[MX1];
vector<int> more;//onai k bishtar daran
int ans;
vector<pair<int,pair<int,int > > edges;
vector<int> edgescpy;
void optimizor(){
    bool tf = 1;
    while(tf){
        for(int i=0;i<edges.size();i++){
            for(int j=0;j<edges.size();j++){
                int fmn[]
                int asli = min(inp[edges[i]], mizout[1])
                pair<int,int> in[2] = {inp[edges[i].F] ,inp[edges[j].F]};
                pair<int,int> out[2] = {inp[edges[i].S.F] ,inp[edges[j].S.F]};
                int mizin[2] = {abs(in[0].S - in[0].F), abs(in[1].S - in[1].F)};
                int mizout[2] = {abs(out[0].S - out[0].F), abs(out[1].S - out[1].F)};
                int mn[2] = {min(mizin[0], mizout[1]),min(mizin[1], mizout[0])};
                int mnn[2] = {min(mizin[0], mizout[0])-mn[0],min(mizin[1], mizout[1])-mn[1]};
                int dis[2] = {abs( edges[i].F - edges[j].S), abs( edges[i].S - edges[j].F)};
                int price[2] = {z*dis[0]*mn[0],z*dis[1]*mn[1]};
                int tmp += price[0] + price[1];
                if(mnn[0]>0){
                    tmp += mnn[0]*z*abs(edges[i].S - edges[i].F);
                }else if(mnn[1]>0){
                    tmp += mnn[1]*z*abs(edges[j].S - edges[j].F);
                }
                if(tmp<asli){

                }
            }
        }
    }
}
int32_t main(){
    cin >> n >> x >> y >> z;
    for(int i = 0 ;i <  n; i++ ){
        cin >>  inp[i].F >> inp[i].S;
    }
    for(int i = 0 ;i < n; i++){
        if(inp[i].S - inp[i].F < 0){
            for(int j = 0;j < n; j++){
                if(inp[j].S - inp[j].F > 0){
                    int tmp = abs(i- j);
                    st.insert({tmp,{i , j}});
                }
            }
        }
    }
    for(auto e : st){
        auto p = e.S;
        int tmp[2] = {inp[p.F].S - inp[p.F].F, inp[p.S].S - inp[p.S].F} ;
        int price = z*e.F;
        if(price < x + y && tmp[0] < 0 && tmp[1] > 0){
            int mn = min(abs(tmp[0]), tmp[1]);
            //cout << "pos : " << p.F << " " << p.S << endl;
            //cout << "ans : "  << ans << " " ;
            ans += mn * price;
            edges.pb({p.F,{p.S,mn * price});
            //cout<<ans << endl;
            inp[p.F].F -= mn;
            inp[p.S].F += mn;
        }
    }
    for(int i = 0;i < n;i++){
        int price=0;
        int tmp = inp[i].S - inp[i].F;
        if(tmp>0){
            price = x;
        }else{
            price = y;
        }
        ans += price * abs(tmp);
    }
    cout<<ans<<endl;
}
