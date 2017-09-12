//in the name of Allah
//:V
//:D
//;)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1 =200*1000+ 100;
int ar[MX1];
int n,m;
pair<int ,int>mx;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        if(b>mx.first){
            mx.first= b;
            mx.second = a;
        }else if(b==mx.first){
            mx.second= a;
        }
    }
    if(mx.second==1){
        sort(ar,ar+mx.first);
    }else{
        sort(ar,ar+mx.first,greater<int>());
    }
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}
