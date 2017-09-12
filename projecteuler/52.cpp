#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("contact.in");
ofstream fout ("contact.out");


bool law(int a,int b){
    vector<int> aa;
    vector<int> bb;
    while(b){
        bb.push_back(b%10);
        b/=10;
    }
    sort(bb.begin(),bb.end());
    while(a){
        aa.push_back(a%10);
        a/=10;
    }
    sort(aa.begin(),aa.end());
    for(int i=0;i<aa.size();i++){
        if(aa[i]!=bb[i]){
            return 0;
        }
    }
    return 1;
}
vector<int> prime;

int main(){
    int lowwer=100;
    bool tf=1;
    while(tf==1){
        for(int i=lowwer;i<lowwer*5/3;i++){
            if(law(i,i*2) && law(i,i*3) && law(i,i*4) && law(i,i*5) && law(i,i*6)){
                cout<<i;
                tf=0;
                break;
            }
        }
        if(tf)
            lowwer*=10;
    }
}
