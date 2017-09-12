/*
ID: ali.mol1
LANG: C++
TASK: contact
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
const int MX1=10001;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
ifstream fin ("contact.in");
ofstream fout ("contact.out");


map<string,int> times;
pair<int,string> out[MX2];
string s;
int least,most,n;

bool myfunction (pair<int,string> i,pair<int,string> j) {
    if(i.first==j.first){
        if(i.second.size()<j.second.size()){
            return 0;
        }else if(i.second.size()>j.second.size()){
            return 1;
        }else{
            if (i.second<j.second){
                return 0;
            }else{
                return 1;
            }
        }
    }else{
        if(i<j){
            return 1;
        }else{
            return 0;
        }
    }
}

int main (){
    fin>>least>>most>>n;
    int size_s=0;
        string tmp;
    while(!fin.eof()){
       getline(fin,tmp);
       size_s+=tmp.size();
        s+=tmp;
    }

    for(int i=0;i<size_s-least+1;i++){
        int x=min(size_s,i+most);
        //cout<<x<<" ";
        tmp="";
        for(int j=i;j<x;j++){
            tmp.push_back(s[j]);
            if(j>=i+least-1){
                times[tmp]++;
            }
        }
    }
    int mx=0;
    int cntr=0;
    for(map<string,int>::iterator it=times.begin();it!=times.end();it++){
        out[cntr].first=it->second;
        out[cntr].second=it->first;
        mx=max(it->second,mx);
        cntr++;
    }
    sort(out,out+cntr,myfunction);
    int cnt=0;
    bool tf=1;
    int last=inf;
    int six=0;
    for(int i=cntr-1; i>0&&tf;i--){
        if(out[i].first==last){
            fout<<out[i].second;
            six++;
            if(six==6&&out[i-1].first==last){
                fout<<endl;
                six=0;
                continue;
            }else if(six==6){
                fout<<endl;
                six=0;
                if(cnt==n){
                    tf=0;
                }
                continue;
            }
            if(out[i-1].first==last){
                fout<<" ";
                continue;
            }
            if(cnt==n){
                tf=0;
            }

            fout<<endl;
        }else{
            six=0;
            fout<<out[i].first<<endl;
            fout<<out[i].second;
            cnt++;
            six++;
            last=out[i].first;
            if(out[i-1].first==last){
                fout<<" ";
                continue;
            }
            if(cnt==n){
                tf=0;
            }
            fout<<endl;
        }
    }
    if(tf==1){
        if(out[0].first==last){
            fout<<out[0].second<<endl;
        }else{
            fout<<out[0].first<<endl;
            fout<<out[0].second<<endl;
        }
    }
}
