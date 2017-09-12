#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("contact.in");
ofstream fout ("contact.out");



vector<int> prime;
bool law1(int a,int b){
    vector<int> aa;
    vector<int> bb;

    aa.push_back(a%10);
    aa.push_back((a/10)%10);
    aa.push_back((a/100)%10);
    aa.push_back((a/1000)%10);
    sort(aa.begin(),aa.end());
    bb.push_back(b%10);
    bb.push_back((b/10)%10);
    bb.push_back((b/100)%10);
    bb.push_back((b/1000)%10);
    sort(bb.begin(),bb.end());
    for(int i=0;i<4;i++){
        if(aa[i]!=bb[i]){
            return 0;
        }
    }
    return 1;
}
bool law2(int a){
    bool tf=1;
    for(int i=2;i*i<a;i++){
        if (a%i==0){
            tf=0;
        }
    }
    return tf;
}
int main(){
    for(int i=1000;i<1000*10;i++){
        if(law2(i)){
            for(int j=1;j<=4500;j++){
                if(i+j<10000 && i+2*j<10000){
                    if(law1(i,i+j) && law2(i+j) && law1(i,i+2*j) && law2(i+2*j)){
                        cout<<i<<i+j<<i+j+j<<endl;
                    }
                }
            }
        }
    }
}
