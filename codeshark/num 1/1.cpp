//in the name of god;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX1=1000*1000*1000;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=145253;

#define int long long
ofstream fout("1.txt");
vector<int> ones[21];

ll tables;
int pyr[1000];
int l=111111 ,r=111111*2;

int bp(int a,int b){
    if(b==0)return 1;
    if(b==1)return a;
    int nesf=bp(a,b/2);
    nesf=(nesf*nesf)%delta;
    if(b&1)nesf=(nesf*a)%delta;
    return nesf;
}

int n=1e17+1;

int32_t main(){
    int ans=0;
    int t=1;
    while(t<=n/2){
        ans=(ans+(t%delta)*(t%delta)%delta)%delta;
        //cout<<t<<endl;
        t=(t*2);
        cout<<t<<endl;
    }
    n++;
    cerr<<n<<endl;
    int a1=(n-t)%delta;
    cout<<a1<<endl;
    ans=(ans+((a1%delta)*(a1%delta)%delta))%delta;
    cout<<ans<<endl;
}
