#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int ar[4][4];
int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>ar[i][j];
        }
    }
    for(int i=0;i<4;i++){
        if(ar[i][3]&&(ar[(i+1)%4][0] || ar[(i+2)%4][1] ||ar[(i+3)%4][2] || ar[i][0] || ar[i][1] || ar[i][2])){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}
