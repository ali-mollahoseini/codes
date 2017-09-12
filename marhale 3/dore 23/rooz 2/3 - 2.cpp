#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=1000*1000;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("contact.in");
ofstream fout ("contact.out");

vector<int> bin;
void push(int num){
    int tmp=num;
    vector<int> tmpbin;
    vector<int> real;
    if(num<100){
        cout<<num<<" ";
    }
    while(tmp){
        tmpbin.insert(tmpbin.begin(),tmp%2);
        tmp/=2;
    }
    if(num<100){
        for(int i=0;i<tmpbin.size();i++){
                cout<<tmpbin[i];
        }
    }
    if(num<100){
        cout<<" ";
    }
    int cnt=0;
    for(int i=0;i<tmpbin.size();i++){
        int x=bin.size()-1-i;
        //cout<<x;
        if(x>-1){
            int ans=bin[x];
            real.insert(real.begin(),ans);
            bool tf=1;
            for(int j=0;j<=i;j++){
                if(tmpbin[j]!=real[j]){
                    tf=0;
                    break;
                }
            }
            if(tf){
                cnt=i+1;
            }
        }
    }
    if(num<100){
        cout<<cnt;
        cout<<endl;
    }
    for(int i=cnt;i<tmpbin.size();i++){
        bin.push_back(tmpbin[i]);
    }
}
int main(){
    bin.push_back(1);
   for(int i=2;i<1390;i++){
        push(i);
   }
   for(int i=0;i<bin.size();i++){
        cout<<bin[i];
        if(i%100==0){
            cout<<endl;
        }
   }
   cout<<'\n';
   int x=bin.size();
   x--;
   cout<<x<<endl;
   x*=1389;
   cout<<x<<endl;
   x%=10979;
   cout<<x<<endl;
}
