///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 06 |
///    | 17 |   CF Round 434   | 26 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0),cin.tie(0);

const int MX = 2000 + 1000, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n , m;
pair<int,int> inp[MX];
bool ok(int l ,int r,int x){
    if(l<=x && x<r){
        return 1;
    }
    return 0;
}
int32_t main(){
    Init
    cin>>n>>m;
    n--;
    if(n==0){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<m;i++){
        cin>>inp[i].F>>inp[i].S;
        inp[i].F--;
        if(inp[i].F==n){
            cout<<inp[i].S<<endl;
            return 0;
        }
    }
    sort(inp,inp+m);
    int cnt=0;
    int ind;
    for(int i=1;i<102;i++){
        bool is=1;
        for(int j=0;j<m;j++){
            /*
            if(i==3){
                cout<<inp[j].F<<' '<<inp[j].S<<' '<<inp[j].S*(i-1)<<' '<<inp[j].S*(i)<<' '<<ok(inp[j].S*(i-1),inp[j].S*(i),inp[j].F)<<endl;
            }
            */
            if(!ok((inp[j].S-1)*i,(inp[j].S)*(i),inp[j].F)){
                is=0;
            }
        }
        if(is){
            if(!cnt){
                ind = (n/i)+1;
            }
            cnt++;
        }
    }
    if(cnt==1){
        cout<<ind;
    }else if(n>inp[m-1].F){
        cout<<-1<<endl;
    }else{
        int cur =0;
        int floor=1;
        for(int i=0;i<m;i++){
            //cout<<n<<' '<<(cur<=n)<<' '<<(n<inp[i].F)<<' '<<(inp[i].S==floor)<<endl;
            if(cur<=n && n<inp[i].F &&inp[i].S==floor){
                cout<<floor<<endl;
                return 0;
            }else{
                cur = inp[i].F;
                floor = inp[i].S;
            }
        }
        cout<<-1<<endl;
    }
}

