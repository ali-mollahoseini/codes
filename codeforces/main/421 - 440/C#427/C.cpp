//in the name of Allah
//:V
//:D
//;)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,  q, c;

int sum[20][200][200];
vector<int> cor[20][200][200];
void make(int sec){
    for(int j =0;j<=100;j++){
        for(int k=0;k<=100;k++){
			int n = cor[sec-1][j][k].size();
            while(n){
                n--;
                cor[sec][j][k].push_back((cor[sec-1][j][k][n]+1)%(c+1));
			}
        }
    }
}
void smake(int sec){
    for(int i =1;i<=100;i++){
        for(int j=1 ; j<=100 ; j++){
            sum[sec][i][j]=sum[sec][i-1][j]+sum[sec][i][j-1]-sum[sec][i-1][j-1];
			int n=cor[sec][i][j].size();
            while(n){
				sum[sec][i][j]+=cor[sec][i][j][n-1];
                n--;
			}
		}
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> c;
    for(int i=0,x,y,s; i<n;i++){
        cin>>x>>y>>s;
        cor[0][y][x].push_back(s);
    }
    for(int i=1;i<=12;i++){
        make(i);
    }
    for(int i=0;i<=12;i++){
        smake(i);
    }
    for(int i=0,t,x1,y1,x2,y2;i<q;i++){
        cin>>t>>x1>>y1>>x2>>y2;
        //cout<<sum[t][y2][x2]<<endl;
        ll ans=sum[t%(c+1)][y2][x2]-sum[t%(c+1)][y2][x1-1]-sum[t%(c+1)][y1-1][x2]+sum[t%(c+1)][y1-1][x1-1];
        cout<<ans<<endl;
    }
    return 0;
}
