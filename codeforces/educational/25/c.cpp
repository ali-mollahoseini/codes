//in the name of Allah
#include <bits/stdc++.h>
#define ll long long
const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;

using namespace std;
int n,k;
set<int> st;
int main(){
    cin>>n>>k;
    k*=2;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        st.insert(a);
    }
    int cntr=0;
    for(auto a : st){
        while(a>k){
            k*=2;
            cntr++;
        }
        if(a*2>k){
            k=a*2;
        }
    }
    cout<<cntr;
}
