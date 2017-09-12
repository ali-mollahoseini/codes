#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MX1=50*1000*1000;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("p081_matrix_v1.txt");
ofstream fout ("contact.out");

bool ar[MX1*3];
int main(){
    ios_base::sync_with_stdio(0);
    int cntr=0;

    for(int i=2;i<85;i++){
        ll x=i*i*i*i;
        if(x<MX1){
            for(int j=2;j<369;j++){
                x=i*i*i*i+j*j*j;
                if(x<MX1){
                    for(int k=2;k<7073;k++){
                        x=i*i*i*i+j*j*j+k*k;
                        if(x<MX1){
                            if(ar[x]==0){
                                cntr++;
                                ar[x]=1;
                                if(j>350){
                                    //cout<<i<<" "<<j<<" "<<k<<endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<cntr<<endl;
}
