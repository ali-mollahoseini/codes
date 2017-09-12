#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
ll n,m;
ll ar[MX2];
int ich[2];
queue<char> que;
int main(){
    int n;
    string s;
    cin>>n>>s;
    int r=0,d=0;
    for(int i=0;i<n;i++){
        if(s[i]=='D'){
            if(d>0){
                d--;
                continue;
            }
            que.push('D');
            ich[0]++;
            r++;
        }else{
            if(r>0){
                r--;
                continue;
            }
            que.push('R');
            ich[1]++;
            d++;
        }
    }
    while(ich[0] && ich[1]){
        if(que.front() == 'D'){
            if(d){
                d--;
                ich[0]--;
                que.pop();
                continue;
            }
            que.push('D');
            que.pop();
            r++;
        }else{
            if(r){
                r--;
                ich[1]--;
                que.pop();
                continue;
            }
            que.push('R');
            que.pop();
            d++;
        }
    }
    if(ich[0]){
        cout<<"D" << endl;
    }else{
        cout << "R" << endl;
    }
}
