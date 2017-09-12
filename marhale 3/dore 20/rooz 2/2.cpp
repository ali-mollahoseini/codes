#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=1000*1000;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("contact.in");
ofstream fout ("contact.out");

int haft[7];
int num=MX1;
int main(){
    int cnt=0;
    while(num<7801389){
        int tmp=num;
        bool tf=0;
        for(int i=6;i>-1;i--){
            haft[i]=tmp%10;
            tmp/=10;
        }
        if(haft[0]==haft[1] && haft[1]==haft[2] && haft[3]==haft[4] && haft[4]==haft[5]){
            if(cnt<1000){
                cout<<num<<" ";
            }
            tf=1;
        }else if(haft[0]==haft[1] && haft[1]==haft[2] && haft[4]==haft[5] && haft[5]==haft[6]){
            tf=1;
        }else if(haft[1]==haft[2] && haft[2]==haft[3] && haft[4]==haft[5] && haft[5]==haft[6]){
            tf=1;
        }else if(haft[0]==haft[1] && haft[2]==haft[3] && haft[4]==haft[5] && haft[5]==haft[6] ){
            tf=1;
        }else if(haft[0]==haft[1] && haft[2]==haft[3] && haft[3]==haft[4] && haft[5]==haft[6] ){
            tf=1;
        }else if(haft[0]==haft[1] && haft[1]==haft[2] && haft[3]==haft[4] && haft[5]==haft[6] ){
            tf=1;
        }else if(haft[0]==haft[2]&& haft[2]==haft[4] &&haft[4]==haft[6] && haft[1]==haft[3] && haft[3]==haft[5] ){
            tf=1;
        }
        if(tf){
            if(cnt<1000){
                cout<<haft[0]<<" "<<num<<endl;
            }
            cnt++;
        }
        num++;
    }
    cout<<cnt<<" "<<(ll)cnt*cnt<<" ";
    ll x=(ll)cnt*cnt;
    x%=10979;
    cout<<x<<endl;
}
