/*
ID: ali.mol1
LANG: C++
TASK: zerosum
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MX1=30;
const int inf=1000*1000*1000;
#define inf 1000*1000*1000
ifstream fin ("zerosum.in");
ofstream fout ("zerosum.out");

int n,cntr;
int ways[MX1];
string nums="123456789",ans[7000];
map<string,bool> mp;
int cal(string s,int v){
    int ans=0,tmp=0;
    bool lst=1;
    for(int i=0;i<v;i++){
        int x=(int) s[i];
        if(x==43){
            if(lst==1){
                ans+=tmp;
            }else{
                ans-=tmp;
            }
            //cout<<tmp<<" ";
            tmp=0;
            lst=1;
        }else if(x==45){
            if(lst==1){
                ans+=tmp;
            }else{
                ans-=tmp;
            }
            //cout<<tmp<<" ";
            tmp=0;
            lst=0;
        }else if(x==32){
        }else{
            tmp*=10;
            tmp+=x-48;
        }
    }
    if(lst==1){
        ans+=tmp;
    }else{
        ans-=tmp;
    }
    return ans;
}
int poww(int a,int b){
    int ans=1;
    while(b!=0){
        ans*=a;
        b--;
    }
    return ans;
}
int main (){
    string space=" ";
    int spc=(int)space[0];
    cout<<spc<<endl;
    fin>>n;
    string tmp;
    int se=poww(3,n-1);
    for(int i=0;i<se;i++){
        for(int j=0;j<n-1;j++){
            tmp.push_back(j+1+48);
            int x=poww(3,j);
            if(i/x%3==0){
                tmp.push_back('-');
            }else if(i/x%3==1){
                tmp.push_back('+');
            }else{
                tmp.push_back(' ');
            }
        }
        tmp.push_back(n+48);
        int ca=cal(tmp,tmp.size());

        if(cal(tmp,tmp.size())==0){
            ans[cntr]=tmp;
            cntr++;
        }
        tmp.clear();
    }
    cout<<cntr;
    sort(ans,ans+cntr);
    for(int i=0;i<cntr;i++){
        fout<<ans[i]<<endl;
    }
}
