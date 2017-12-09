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
int g1, p1, g2, p2;
int binmax(int per,int g){
    int l =0, r= g+1;
    while(r-l>1){
        int m = (l+r)/2;
        if(floor((double)m/g*100)>per){
            r= m;
        }else{
            l =m;
        }
    }
    return l;
}
int32_t main(){
    cin>>g1>>p1>>g2>>p2;
    int x= binmax(p1-1,g1)+1;
    int x2 = binmax(p2,g2);
    cout<<x2-x<<endl;
    return 0;
}


