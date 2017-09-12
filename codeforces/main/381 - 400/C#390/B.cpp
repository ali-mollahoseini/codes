#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF;
int ar[5][5];
bool tf[5][5];
int main(){
    for(int i=0;i<4;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<4;j++){
            if(tmp[j]=='x'){
                ar[i][j]=1;
            }else if(tmp[j]=='o'){
                ar[i][j]=-1;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            int sum;
            sum=ar[i][j]+ar[i][j+1]+ar[i][j+2];
            if(sum==2){
                tf[i][j] = 1;
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            int sum;
            sum=ar[i][j]+ar[i+1][j]+ar[i+2][j];
            if(sum==2){
                tf[i][j] = 1;
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            int sum;
            sum=ar[i][j]+ar[i+1][j+1]+ar[i+2][j+2];
            if(sum==2){
                tf[i][j] = 1;
            }
        }
    }
    for(int i=3;i>1;i--){
        for(int j=0;j<2;j++){
            int sum;
            sum=ar[i][j]+ar[i-1][j+1]+ar[i-2][j+2];
            if(sum==2){
                tf[i][j] = 1;
            }
        }
    }
    bool ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            ans= ans || tf[i][j];
        }
    }
    if(ans){
        cout<<"YES"<<endl;
    }else{
        cout<< "NO" <<endl;
    }
}
