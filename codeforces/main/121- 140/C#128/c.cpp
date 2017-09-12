//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=100*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std ;
pair<int,int> inp[MX1];
vector<int> out;
int32_t main(){
    int n, d,a,b;
    cin>>n>>d>>a>>b;
    for(int i=0,tmp1, tmp2;i<n;i++){
        cin>>tmp1 >> tmp2;
        inp[i].F= tmp1 * a + tmp2 * b ;
        inp[i].S = i+1;
    }
    sort (inp, inp+n);
    int sum=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(sum+inp[i].F<=d){
            sum+=inp[i].F;
            cnt++;
            out.pb(inp[i].S);
        }else{
            break;
        }
    }
    cout<<out.size()<<endl;
    for(int i=0;i<out.size();i++){
        cout<<out[i]<< " ";
    }
    cout<<endl;
    return 0;

}

