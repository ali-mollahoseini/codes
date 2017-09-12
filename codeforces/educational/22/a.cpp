//be name khoda
//8)
//;)
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int ar[MX1];
int32_t main(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
    }
    int t;
    int a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        if(b>=sum){
            cout<<max(a,sum)<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}

