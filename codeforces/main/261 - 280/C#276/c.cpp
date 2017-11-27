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
int per[61],n;
int32_t main(){
    Init
    per[0]=1;
    for(int i=1;i<61;i++){
        per[i]=per[i-1]*2LL;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int l , r,d;
        cin>>l>>r;
        int num =l;
        d= r-l+1;
        bool tf= 0;
        for(int j=60;j+1;j--){
            if(tf){
                num |=per[j];
            }
            if(per[j]<=d){
                tf =1;
            }
        }
        int j = 0;
        //cout<<num<<endl;
        while((num|per[j])<=r  && j<61){
            num|=per[j];
            j++;
        }
        cout<<num<<endl;;
    }

}


