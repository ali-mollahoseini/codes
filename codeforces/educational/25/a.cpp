//in the name of Allah
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
const int MX1=200*1000+1000;
const int inf= 0x7FFFFFFF;

using namespace std;

int n;
string s;
vector<int> kol;
int main(){
    cin>>n;
    int ans=0;
    cin>>s;
    reverse(s.begin(),s.end());
    int cntr=0,tmp=0;
    while(cntr<s.size()){
        while(cntr<s.size()&&s[cntr]=='1'){
            tmp++;
            cntr++;
        }
        kol.push_back(tmp);
        tmp=0;
        cntr++;
    }
    reverse(kol.begin(),kol.end());
    for(int i=0;i<kol.size();i++){
        cout<<kol[i];
    }
    cout<<endl;
}
