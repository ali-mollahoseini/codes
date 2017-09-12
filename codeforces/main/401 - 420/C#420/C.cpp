#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
int n;
vector<int> stc;
int main(){
    int lok4=1;
    cin>>n;
    int cntr=0;
    for(int i=0;i<2*n;i++){
        string s;
        int a;
        cin>>s;
        if(s=="add"){
            cin>>a;
            stc.push_back(a);
        }else{
            if(!stc.empty()){
                if(stc.back()==lok4){
                    stc.pop_back();
                    lok4++;
                }else{
                    stc.clear();
                    cntr++;
                    lok4++;
                }
            }else{
                lok4++;
            }
        }
    }
    cout<<cntr;
}
