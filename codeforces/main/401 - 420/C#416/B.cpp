#include <bits/stdc++.h>

#define ll long long

const int inf=0x7FFFFFFF;
const int MX1=50*1000*+1000;

using namespace std;
int n,m;
int p[MX1];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0,l,r,x;i<m;i++){
        cin>>l>>r>>x;
        int cntr=0;
        for(int i=l-1;i<r;i++){
            if(p[i]<p[x-1]){
                cntr++;
            }
        }
        //cout<<cntr<<endl;
        if(cntr==x-l){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}

