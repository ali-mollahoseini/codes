
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
#define Init ios::sync_with_stdio(0);

using namespace std;

const int mod=1000*1000*1000+7;
const int MX=100*1000+10;
const int inf=0x7FFFFFFF;
int n , m;
struct reigon{
    vector<pair<int,string> > vec;
} reigons[MX];
int main(){
    Init
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int r, sc;
        string name;
        cin>>name>>r>>sc;
        reigons[--r].vec.pb({sc,name});
    }
    for(int i=0;i<m;i++){
        sort(reigons[i].vec.begin(),reigons[i].vec.end());
    }
    for(int i=0;i<m;i++){
        if()
    }


}
