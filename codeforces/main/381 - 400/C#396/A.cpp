#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=1000*100+100;
const int MX2= 1000*1000+100;
const int inf=2*1000*1000*100;
pair<int,int> ar[MX1];
int n;
string s1,s2;
int main(){
    cin>>s1>>s2;
    if(s1==s2){
        cout<<-1<<endl;
    }else{
        cout<<max(s2.size(),s1.size());
    }
}
