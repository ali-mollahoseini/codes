//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=100*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int inp[MX1],pos[MX1];
int all[MX1];
vector<pair<int,int> > todo;
void seive(int lst){
    for(int i=2;i<lst;i++){
        if(!all[i]){
            for(int j=i*i;j<lst;j+=i){
                all[j]=i;
            }
        }
    }
}
int minp(int x){
    while(x){
        if(!all[x])
            break;
        x--;
    }
    return x;
}
void swp(int i,int j){
    int tmp=inp[i];
    inp[i]=inp[j];
    inp[j]=tmp;
    pos[inp[i]]=i;
    pos[inp[j]]=j;
    todo.pb({min(i,j)+1,max(i,j)+1});
}
int32_t main(){
    int n;
    cin>>n;
    seive(n+1);
    for(int i=0;i<n;i++){
        cin>>inp[i];
        inp[i]--;
        pos[inp[i]]=i;
    }
    for(int i=0;i<n;i++){
        while(pos[i]!=i){
            int dis=pos[i]-i+1;
            int d=minp(dis);
            //cout<<d<<endl;
            swp(pos[i]-(d-1),pos[i]);
        }
    }
    cout << todo.size() << endl;
    for(int i =0 ;i < todo.size(); i++){
        cout<<todo[i].F<<" "<<todo[i].S<<endl;
    }
}
