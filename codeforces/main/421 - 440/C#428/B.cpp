//in the name of Allah
//:V
//:D
//;)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF4;
int k;
string n;
map<int,int> mp;
int main(){
    cin>>k;
    cin>>n;
    int cur=0;
    while(n.size()){
        mp[((int)(n.back()-'0'))]++;
        cur+=((int)(n.back()-'0'));
        n.pop_back();
    }
    int cntr=0;
    bool tf=1;
    if(cur<k){
        for(int i=0;i<9;i++){
            while(mp[i]){
                cntr++;
                cur+=9-i;
                if(cur>=k){
                    tf=0;
                    break;
                }
                mp[i]--;
            }
            if (!tf){
                break;
            }
        }
    }
    cout<<cntr<<endl;
}
