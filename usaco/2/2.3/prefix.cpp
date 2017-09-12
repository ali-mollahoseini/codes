/*
ID: ali.mol1
LANG: C++
TASK: prefix
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
const int MX1=200*1000+100;
const int inf=1000*1000*1000;
#define inf 1000*1000*1000
ifstream fin ("prefix.in");
ofstream fout ("prefix.out");

int n,last=-1,fst;
bool ok[MX1];
string s;
map<string,bool> mp;

int main (){
    while(1==1){
        string tmp;
        fin>>tmp;
        if(tmp==".") break;
        mp[tmp]=1;
    }
    while(1==1){
        string tmp;
        fin>>tmp;
        if(tmp=="") break;
        s+=tmp;
    }
    bool tf=1;
    int cntr=0;
    string tmp;
    int si=s.size();
    int mn=min(10,si);
    for(int i=0;i<mn;i++){
        tmp.push_back(s[i]);
        cntr++;
        if(mp[tmp]==1){
            ok[i]=1;
            last=i;
            if(tf){
            fst=i;
            tf=0;
            }
        }
        if(cntr>20){
            break;
        }
    }
        for(int i=fst+1;i<s.size();i++){
            string tmp2;
            int mn2=max(i-11,-1);
            for(int j=i;j>mn2;j--){
                tmp2.insert(tmp2.begin(),s[j]);
                if(mp[tmp2]==1&&ok[j-1]){
                    ok[i]=1;
                    last=i;
                    break;
                }
            }
        }
    fout<<last+1<<endl;
}
