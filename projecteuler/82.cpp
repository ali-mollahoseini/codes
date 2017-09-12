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
    dp[0][0]=ar[0][0];
    for(int j=1;j<80;j++){
        dp[0][j]=ar[0][j]+dp[0][j-1];
        dp[j][0]=ar[j][0]+dp[j-1][0];
    }
    for(int i=1;i<80;i++){
        for(int j=1;j<80;j++){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+ar[i][j];
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[79][79];
}
