#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int ar[MX2];
struct so{
    bool op(const int &a,const int &b){
        return a>b;
    }
};
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    sort(ar,ar+n);
}
