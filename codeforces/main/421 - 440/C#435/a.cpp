///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 06 |
///    | 19 |   CF Round 434   | 28 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);

const int MX = 70000 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7;
using namespace std;
vector<int> divv;
void update(int x)
{
    for(int i=1;i<x+1;i++){
        if(!(x%i)){
            divv.pb(i);
        }
    }
}
int rander(int x){
    if(x==1){return 1;}
    int ans=1;
    divv.clear();
    update(x);
    int rnd = rand()%divv.size();
    int f = divv[rnd];
    while(f==x){
        ans++;
        rnd = rand()%divv.size();
        f = divv[rnd];
    }
    //cout<<rand()<<endl;
    ans += rander(f);
    return ans;
}
int32_t main(){
    Init
    int n;
    cin>>n;
    int times = 1000*1000*10;
    int sum=0;
    for(int i=0;i<times;i++){
        sum+=rander(n);
    }
    cout<<(double)sum/(double)times;
}

