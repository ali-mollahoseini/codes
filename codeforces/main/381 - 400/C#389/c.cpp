//be name khoda
//8)
//;)

#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back

const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int n;
vector<pair<int,char> >du,rl;
string s;
bool okU(int f,int cur){
    if(cur==0){
        return 1;
    }
    if(du[cur-1].F<f){
        return 1;
    }else{
        if(du[cur-1].S==du[cur].S){
            return 1;
        }else{
            return 0;
        }
    }
}
bool okR(int f,int cur){
    if(cur==0){
        return 1;
    }
    if(rl[cur-1].F<f){
        return 1;
    }else{
        if(rl[cur-1].S==rl[cur].S){
            return 1;
        }else{
            return 0;
        }
    }
}
int32_t main(){
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='R'||s[i]=='L'){
            rl.pb({i,s[i]});
        }else{
            du.pb({i,s[i]});
        }
    }
    int ans=1;
    int stt=0, nxr=0,nxl=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R'||s[i]=='L'){
            //cout<<1<<" ";
            if(!okR(stt,nxr)){
                stt=i;
                ans++;
            }
            nxr++;
            //cout<<2<<endl;
        }else{
            if(!okU(stt,nxl)){
                stt=i;
                ans++;
            }
            nxl++;
        }
    }
    cout<<ans<<endl;
}
