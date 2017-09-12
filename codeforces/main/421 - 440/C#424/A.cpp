#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define FR(n)ss
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int n;
int ar[200];
int main(){
    cin>>n;
    bool tf=1;
    int x=0;
    int last;
    cin>>last;
    ar[0]=last;
    for(int i=1;i<n;i++){
        cin>>ar[i];
        if(x==0){
            if(ar[i]>last){
                last=ar[i];
                continue;
            }else if(ar[i]==last){
                x++;
            }else{
                last=ar[i];
                x+=2;
            }
        }else if(x==1){
            if(ar[i]>last){
                tf=0;
                break;
            }else if(ar[i]<last){
                last=ar[i];
                x++;

            }
        }else if(x==2){
            if(ar[i]>last){
                tf=0;
                break;
            }else if(ar[i]==last){
                tf=0;
                break;
            }else{
                last=ar[i];
                continue;
            }
        }
    }
    if(tf){
        cout<<"YES";
    }else{
        cout<<"NO"<<endl;
    }
}
