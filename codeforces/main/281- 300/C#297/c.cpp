//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=100*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
vector<int> inp;
int32_t main(){
    int n;
    cin>>n;
    if(n<4){
        cout<<0<<endl;
        return 0;
    }
    for(int i =0,tmp;i<n;i++){
        cin>>tmp;
        inp.pb(tmp);
    }
    sort(inp.rbegin(),inp.rend());
    int w=0,md=1;
    int sum=0;
    for(int i=0;i<n-1;i++){
        if(inp[i]-inp[i+1]<2&&md==1){
            w=inp[i+1];
            md++;
            i++;
        }else if(inp[i]-inp[i+1]<2&&md!=1){
            md=1;
            sum+=w*inp[i+1];
            i++;
        }
    }
    cout<<sum<<endl;
}
