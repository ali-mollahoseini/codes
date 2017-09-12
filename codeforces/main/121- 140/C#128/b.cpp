//in the name of Allah
#include <bits/stdc++.h>

#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back

const int MX1=1000+1000;
const int inf= 0x7FFFFFFF;
using namespace std;
bool inp [MX1][MX1];
bool ok(int x, int y){
    int sum=0;
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            sum+=inp[i][j];
        }
    }
    return (sum==9);
}
int32_t main(){
    int n, m;
    cin>>n>>m;
    for(int i=0,x,y;i<m;i++){
        cin>>x>>y;
        inp[--x][--y]=1;
        for(int j=max(0LL,x-2);j<=x;j++){
            for(int k = max(0LL,y-2); k<=y;k++ ){
                if(ok(j,k)){
                    cout<<i+1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;
}
