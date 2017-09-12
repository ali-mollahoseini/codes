#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=1000+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF;
int n,k,a[MX1],b[MX1], c[MX1];
bool used[MX1];
vector<int> aft;
int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]==b[i] && !used[a[i]]){
            c[i]=a[i];
            used[a[i]]=1;
        }else{

        }
    }
    for(int i=0;i<aft.size();i++){
        if(a[aft[i]]!=b[aft[i]]){
            if((used[a[aft[i]]]==1 && used[b[aft[i]]]==0) || (used[a[aft[i]]]==0 && used[b[aft[i]]]==1)){
                c[i]=b[aft[i]];
                used[b[aft[i]]] = 1;
                aft.erase(aft.begin()+i);

            }
        }
    }
}
