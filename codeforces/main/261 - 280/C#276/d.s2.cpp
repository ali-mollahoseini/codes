//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define LSB(i) ((i)&(-i));

const int inf= 0x77FFFFFF;
const int MX = 1000*1000+10;
using namespace std;
int n,tmp[MX];
pair<int,int> inp[MX];
map<int,int> mp;
int f[2][MX];///f[0]:1-i, f[1]:j-n;
int  inversions[MX];
void merg(int *a,int l ,int r){
    int m = (l+r)/2, lst = 0;
    int pt1 = l, pt2 =  m;
    while(pt1 !=  m || pt2 != r){
        int val1 =(pt1<m)? a[pt1] : inf;
        int val2 =(pt2<r)? a[pt2] : inf;
        if(val1<val2){
            tmp[lst++] = a[pt1++];
        }else{
            tmp[lst++] = a[pt2++];
        }
    }
    for(int i=l;i<r;i++){
        a[i] = tmp[i-l];
    }
}
int dAndc(int l, int r){
    if(l==r-1){return 0;}
    int m = (l+r)/2;
    int pt1 = l , pt2 = m;
    int ans = dAndc(l,m) + dAndc(m,r);
    while(pt1 != m || pt2 != r){
        int val1 =(pt1 < m? f[0][pt1] : inf);
        int val2 =(pt2 < r? f[1][pt2] : inf);
        //cout<<val1<<' '<<val2<<endl;
        if(val1>val2){
            pt2++;
        }else{
            pt1++;
            ans+= pt2-m;
        }
    }
    merg(f[0],l,r);
    merg(f[1],l,r);
    return ans;
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie();
    cin>>n;
    for(int i=0,u;i<n;i++){
        cin>>u;
        inp[i].F = u,inp[i].S = i;
        mp[u]++;
    }
    sort(inp ,inp+n);
    int lst=-1,cnt;
    for(int i=0;i<n;i++){
        if(inp[i].F == lst){
            cnt++;
        }else{
            cnt=1;
            lst = inp[i].F;
        }
        f[0][inp[i].S]=cnt;
        f[1][inp[i].S]=mp[inp[i].F]-cnt+1;
    }
    cout<<dAndc(0,n)<<endl;
}
