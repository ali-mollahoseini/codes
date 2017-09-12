#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("contact.in");
ofstream fout ("contact.out");

int main(){
    int mx=0;
    for(int i=1;i<100;i++){
        int ans[200+10];
        int tmp[200+10][2];
        for(int k=0;k<210;k++){
                ans[k]=0;
        }
        ans[0]=i%10;ans[1]=(i/10)%10;
        int multiply[2];
        multiply[0]=i%10;multiply[1]=(i/10)%10;
        for(int j=0;j<100;j++){
            for(int k=0;k<210;k++){
                tmp[k][0]=0;
                tmp[k][1]=0;
            }
            for(int k=0;k<210;k++){
                tmp[k][0]+=ans[k]*multiply[0];
                if(tmp[k][0]>=10){
                    int x=tmp[k][0]/10;
                    tmp[k][0]-=10*x;
                    tmp[k+1][0]+=x;
                }
            }
            for(int k=1;k<210;k++){
                tmp[k][1]+=ans[k-1]*multiply[1];
                if(tmp[k][1]>9){
                    int x=tmp[k][1]/10;
                    tmp[k][1]-=10*x;
                    tmp[k+1][1]+=x;
                }
            }
            for(int k=0;k<210;k++){
                ans[k]=0;
            }
            for(int k=0;k<210;k++){
                ans[k]+=tmp[k][0]+tmp[k][1];
                if(ans[k]>9){
                    int x=ans[k]/10;
                    ans[k]-=10*x;
                    ans[k+1]+=x;
                }
            }
            int sum=0;
            for(int k=0;k<210;k++){
                sum+=ans[k];
                if(i==10&&j==20)
                    cout<<i<<" "<<ans[1]<<ans[0]<<endl;
            }
            for(int k=1;k<200;k++){
                tmp[k][0]=0;
                tmp[k][1]=0;
            }
            mx=max(mx,sum);
        }
    }
    cout<<mx;
}
