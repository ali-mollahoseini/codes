//in the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFFF;
int n,k;
pair<int,int> lr[30];
string s;
set<int> st;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    cin>>s;
    int cntr=0;
    for(int i=0;i<n;i++){
        int w=(int)(s[i]-'A');
        if(lr[w].first==0){
            lr[w].first=i+1;
            cntr++;
        }
        lr[w].second=i+1;
    }
    for(int  i=0;i<n;i++){
        int w=(int)(s[i]-'A');
        if(lr[w].first==i+1){
            //cout<<w<<" "<<lr[w].first<<endl;
            st.insert(w);
        }
        if(st.size()>k){
            cout<<"YES"<<endl;
            return 0;
        }
        if(lr[w].second==i+1){
            st.erase(w);
        }
    }
    cout<<"NO"<<endl;
}
