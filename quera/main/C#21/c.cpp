//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
int n;
int inp[MX1],pos[MX1];
vector<pair<int,int> > todo;
void swp(int i ,int j){
    int tmp= inp[i];
    inp[i]=inp[j];
    inp[j]=tmp;
    pos[inp[i]]=i;
    pos[inp[j]]=j;
    todo.pb({i,j});
}
int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i];
        inp[i]--;
        pos[inp[i]]=i;
    }
    for(int i=0;i<n;i++){
        if(pos[i]!=i){
            if(abs(pos[i]-i)>n/2+1){
                int x= pos[i]-(n/2+1);
                swp(x, pos[i]);
                swp(pos[i],i);
            }else {
                swp(pos[i],i);
            }
        }
    }
    int cnt=todo.size();
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<todo[i].F+1<<" "<<todo[i].S+1<<endl;
    }
    return 0;
}
