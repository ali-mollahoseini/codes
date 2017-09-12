#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("p081_matrix_v1.txt");
ofstream fout ("contact.out");

ll ar[80][80];
ll dp[80][80];
int main(){
    for(int i=0;i<80;i++){
        for(int j=0;j<80;j++){
            fin>>ar[i][j];
        }
    }
    for(int i=0;i<80;i++){
        for(int j=0;j<80;j++){
            dp[i][j]=inf;
        }
    }
    dp[0][0]=ar[0][0];
    for(int k=0;k<90;k++){
        for(int i=0;i<80;i++){
            for(int j=0;j<80;j++){
                int u=max(0,i-1),l=max(0,j-1),d=min(79,i+1),r=min(79,j+1);
                int x=min(min(min(dp[d][j],dp[i][r]),dp[i][l]),dp[u][j]);
                dp[i][j]=min(x+ar[i][j],dp[i][j]);
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
    }
    cout<<dp[79][79];
}
