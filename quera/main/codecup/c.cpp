///        +====================+
///        "In The Name Of Allah"
///    +----+------------------+----+
///    |2017| Ali Mollahoseini |1396|
///    | 09 +------------------+ 06 |
///    | 19 |   CF Round 434   | 28 |
///    +----+------------------+----+


#include <bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
#define Init ios::sync_with_stdio(0);

const int MX = 1000*1000 + 100, inf = 0x7FFFFFFF, mod = 1000 * 1000 * 1000 + 7,pw = 1<<18;
using namespace std;
char mat[100][100];
pair<int,int>ways[4] ={{0,2},{-2,0},{2,0},{0,-2}};
bool ok(int x, int y, pair<int,int> a){
    if(x+a.F>=0 && x+a.F<7 &&y+a.S>=0 &&y+a.S<7 && mat[x+a.F][y+a.S]=='o'){
        return 1;
    }
    return 0;
}
int32_t main(){
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            cin>>mat[i][j];
        }
    }
    int ans=0;
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            for(int k=0;k<4;k++){
                if(mat[i][j]=='.' && ok(i,j,ways[i])){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}

