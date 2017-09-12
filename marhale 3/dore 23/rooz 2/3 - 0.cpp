#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int delta = 10181;
const int inf=0x7FFFFFFF;
//ifstream fin ("contact.in");
//ofstream fout ("contact.out");
int nm=11;
int permute[11]={11,1,2,3,4,5,6,7,8,9,10};
ll poww (ll a,int b){
    int ans=1;
    while(b){
        ans*=a;;
        ans%=delta;
        b--;
    }
    return ans;
}
bool check(int b){
    vector<int> tmp,tmp1;
    //cout<<1<<endl;
    for(int i=0;i<nm;i++){
        tmp.push_back(permute[i]);
        tmp1.push_back(permute[i]);
    }
    while(b){
        int cnt=0;
        for(int i=1;i<tmp.size();i++){
            if(tmp[i]<tmp[i-1]){
                tmp1.erase(tmp1.begin()+i-cnt);
                cnt++;
            }
        }
        tmp.clear();
        for(int i=0;i<tmp1.size();i++){
            tmp.push_back(tmp1[i]);
        }
        //cout<<cntr<<endl;
        //cntr++;
        b--;
    }
    if(tmp.size()==1){
        if(tmp[0]==nm){
            return true;
        }
    }
    return false;
}
void printar(){
    for(int i=0;i<nm;i++){
        cout<<permute[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int k=5;
    int cntr=0;
    int alk=0;
    do{
        if(permute[0]==nm){
            alk++;
            if(check(k)){
                cntr++;
                if(cntr<300){
                    printar();
                }
            }
        }
    }while(next_permutation(permute,permute+nm));
    cout<<cntr<<" "<<alk<<endl;
    cout<<poww(cntr,3);
}
