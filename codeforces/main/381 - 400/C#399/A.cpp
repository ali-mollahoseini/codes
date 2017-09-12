
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=1000*100+100;
const int MX2= 1000*1000+100;
const int inf=2*1000*1000*1000+100;
pair<int,int> ar[MX1];
int n;
map<int,int> ich;
int main(){
    int mn=inf,mx=0;
    cin>>n;
    for(int i =0;i<n;i++){
        int a;
        cin>>a;
        ich[a]++;
        mn = min(mn, a);
        mx  = max(mx, a);
    }
    //cout<<mn;
    int sum=0;
    for(auto u : ich){
        if(u.first == mn || u.first == mx){
            continue;
        }
        sum+=u.second;
    }
    cout<< sum << endl;
}
