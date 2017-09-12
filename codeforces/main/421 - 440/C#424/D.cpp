//in the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;


const int mod=1000*1000*1000+7;
const int MX1=1000+100;
const int MX2= 2000+100;
const int inf=0x7FFFFFFF;

int n,k,p;
int  a[MX1];
int  b[MX2];
vector<int> table[MX2];
int main(){
    cin>>n>>k>>p;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<k;i++){
        cin>>b[i];
    }
    sort(b,b+k);
    int mn=inf;
    for(int i=0;i<k-n+1;i++){
        //cerr<<2<<endl;
        int mx=0;
        for(int j=i;j<i+n;j++){
            int tmp=0;
            tmp+=abs(a[j-i]-b[j]);
            tmp+=abs(b[j]-p);
            mx=max(mx,tmp);
        }
        mn=min(mx,mn);
        //cerr<<3<<endl;
    }
    cout<<mn;
}
