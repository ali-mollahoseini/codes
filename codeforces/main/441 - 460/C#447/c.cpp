//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define req(i,s,e) for(int i=s;i<e;i++)
#define Init ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int MX = 2000 + 1000,inf = 0x7FFFFFFF,mod = 1000 * 1000 * 1000 + 7;
using namespace std;

int n;
set<int> st;
int inp[MX];
map<int,int>mp;
int32_t main(){
    Init
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i];
        st.insert(inp[i]);
    }
    for(int i=n-1;i+1;i--){
        int x=inp[i];
        for(int j =i;j<n;j++){
            if(st.find(__gcd(x,inp[j]))==st.end()){
                cout<<-1<<endl;
                return 0;
            }else{
                x= __gcd(x,inp[j]);
            }
        }
    }
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<inp[i]<<' ';
    }
}


