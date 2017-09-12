#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFFF;
int a[MX1],n,m;
int sum;
pair<int,int> rl[MX1];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i =0;i<m;i++){
        cin>>rl[i].first>>rl[i].second;
        int tmp=0;
        for(int j=rl[i].first-1;j<rl[i].second;j++){
            tmp+=a[j];
        }
        if(tmp>0){
            //cout<<tmp<<endl;;
            sum+=tmp;
        }
    }
    cout<<sum;

}
