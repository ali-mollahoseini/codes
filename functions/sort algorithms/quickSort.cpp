#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
const int MX=1e7;
int inp[MX];

int par(int st, int ed){
    int x=inp[st],pnt1=st,pnt2=ed-1;
    while(pnt1<=pnt2){
        if(inp[pnt1]>=x){
            if(inp[pnt2]<=x){
                swap(inp[pnt1],inp[pnt2]);
                pnt1++;
                pnt2--;
            }
            else pnt2--;
        }
        else pnt1++;
    }
    return pnt1;
}

void quickSort(int st,int ed){
    if(st==ed-1) return;
    int pt=par(st,ed);
    quickSort(st,pt);
    quickSort(pt,ed);
}
int32_t main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i];
    }
    quickSort(0,n);
    for(int i=0; i<n; i++){
        cout<<inp[i]<<" ";
    }
    return 0;
}
