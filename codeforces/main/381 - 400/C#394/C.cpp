#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define FR(n)ss
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*100;
int alph[MX1],sym[MX1],num[MX1];
int n,m;
int main(){
    cin>>n>>m;
    for(int i = 0;i < 60; i++){
        alph[i] = inf;
        sym[i] = inf;
        num[i] = inf;
    }
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        for(int j = 0; j < m; j++){
            if(isalpha(tmp[j])){
                alph[i]=min(min(j,m-j),alph[i]);
            }else if( isdigit(tmp[j]) ){
                num[i]=min(min(j,m-j),num[i]);
            }else{
                sym[i]=min(min(j,m-j),sym[i]);
            }

        }
    }
    int mn = inf;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k = 0 ;k< n;k++){
                if(i!=j && j!=k && i!= k){
                    int sum=alph[i]+num[j]+sym[k];
                    mn=min(mn,sum);
                    //cout<<i <<" "  <<j<< " " <<k<< " " <<endl;
                    //cout<<"Sum : "<<sum<<endl;8;
                }
            }
        }
    }
    cout<<mn<<endl;
}
