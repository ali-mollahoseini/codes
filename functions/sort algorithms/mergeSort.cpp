#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
const int MX=1e6+1000;
int input[MX],sum;
int out[MX];
void merg(int st, int ed){
    int mid=(st+ed)/2;
    int pnt1=st,pnt2=mid,ind=st;
    while(pnt1<mid&&pnt2<ed){
        if(input[pnt1]>input[pnt2]){
            out[ind++]=input[pnt2++];
        }
        else{
            out[ind++]=input[pnt1++];
        }
    }
    while(pnt1<mid){
        out[ind++]=input[pnt1++];
    }
    while(pnt2<ed){
        out[ind++]=input[pnt2++];
    }
    for(int i=st; i<ed; i++){
        input[i]=out[i];
    }
}
void merge_sort(int st,int ed){
    if(ed-1==st){
        return;
    }
    int mid=(st+ed)/2;
    merge_sort(st,mid);
    merge_sort(mid,ed);
    //merg(st,ed);
    merge(input+st,input+mid,input+mid,input+ed,out);
    for(int i=st;i<ed;i++){
        input[i] = out[i-st];
    }
}

int32_t main(){
    int n;
    cin>>n;
    for(int i=0 ;i<n ; i++){
        cin>>input[i];
    }
    merge_sort(0,n);
    for(int i=0 ;i<n; i++){
        cout<<input[i]<<" ";
    }
    return 0;
}
