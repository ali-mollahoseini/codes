//in th name of Allah
#include <bits/stdc++.h>
using namespace std;

#define ll long long
//#define int long long
#define F first
#define S second
#define pb push_back

const ll MX1=300*1000+1000;
const ll inf= 0x77FFFFFF;
pair<int ,int> inp[MX1];
bool op(pair<int,int> a,pair<int,int> b){
    return a.S<b.S;
}
int main(){
    int n;
    cin>>n;
    for(int i=0,tmp;i<n;i++){
        cin>>tmp;
        inp[i].S=i;inp[i].F=tmp;
    }
    sort(inp,inp+n);
    int mn=0;
    for(int i=0;i<n;i++){
        if(inp[i].F>mn){
            mn=inp[i].F+1;
        }else{
            inp[i].F=mn;
            mn++;
        }
    }
    sort(inp,inp+n,op);
    for(int i=0;i<n;i++){
        cout<<inp[i].F<<" ";
    }
    cout<<endl;
}
