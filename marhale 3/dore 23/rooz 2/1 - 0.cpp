#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int delta = 10181;
const int inf=0x7FFFFFFF;
//ifstream fin ("contact.in");
//ofstream fout ("contact.out");

int main(){
    ll cntr=0;
    for(int n=2;n<delta;n++){
        for(int i=1;i<delta;i++){
            for(int j=1;j<delta;j++){
                if(((ll)i*j)%n==0){
                    cntr++;
                    if(n%100==0){
                        cout<<n<<endl;
                    }
                }
            }
        }
    }
    cntr%=delta;
    cntr+=(delta-1)*(delta-1)-10180;
    cout<<cntr%delta;
}
