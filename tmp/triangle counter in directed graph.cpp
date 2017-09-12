
///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 05 |
///    | 01 |UC 2015 January 3 | 09 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Log(x,y) cerr<<x<<y<<endl;

const int MX = 2000 + 1000;
const int inf = 0x7FFFFFFF;
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int n ,m;
int mat[MX][MX];
int32_t main(){
    cin>>n;
    for(int i=0,u,v;i<n*n;i++){
        cin>>u>>v;
        if(u==v){break;}
        mat[u][v] = 1;
    }
    int cntr=0;
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            for(int k=0;k<n;k++){
                if((i!=j)&&(j!=k)&&(i!= k)){
                    if(mat[i][j] && mat[j][k] && mat[k][i]){
                            cntr++;
                    }
                }
            }
        }
    }
    cout<<cntr/3<<endl;
}
