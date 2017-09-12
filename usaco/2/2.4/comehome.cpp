/*
ID: ali.mol1
LANG: C++
TASK: comehome
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
const int MX1=101;
const int MX2= 39;
const int inf=1000*1000*1000;
ifstream fin ("comehome.in");
ofstream fout ("comehome.out");
map<char,bool> visited;
map<char,int> f_dis;
map<char,int> all_dis;
pair<int,int> source[2];
int n;
pair<char,int> ans;
map<char,vector<pair<char,int> > > adj;

void dijkstra();
void inp();

int main (){
    inp();
    dijkstra();
    fout<<ans.first<<" "<<ans.second<<endl;
}
void dijkstra(){
    bool tf=1;
    char tmp='Z';
    all_dis[tmp]=0;
    f_dis[tmp]=0;
    for(int i=0;i<n;i++){
        int mn=inf;
        for(vector<pair<char,int> >::iterator it=adj[tmp].begin();it!=adj[tmp].end();it++){
            if(visited[it->first]==0){
                f_dis[it->first]=min(all_dis[tmp]+it->second,f_dis[it->first]);
                all_dis[it->first]=f_dis[it->first];
            }
        }
        for(map<char,int>::iterator it=f_dis.begin();it!=f_dis.end();it++){
            cout<<2;
            if(it->second<mn){
                mn=it->second;
                tmp=it->first;
            }
        }
        visited[tmp]=1;
        f_dis[tmp]=inf;
    }
    ans.second=inf;
    for(map<char,int>::iterator it =all_dis.begin();it!=all_dis.end();it++){
            cout<<it->first<<" "<<it->second;
        if((int)it->first<96&&it->first!='Z'){
            if(it->second<ans.second){
                ans.first=it->first;
                ans.second=it->second;
            }
        }
    }
}
void inp(){
    fin>>n;
    cout<<1;
    for(int i=0;i<n;i++){
        cout<<1;
        char tmp[2];
        int weight;
        fin>>tmp[0]>>tmp[1]>>weight;
        adj[tmp[0]].push_back({tmp[1],weight});
        adj[tmp[1]].push_back({tmp[0],weight});
        f_dis[tmp[0]]=inf;
        f_dis[tmp[1]]=inf;
        all_dis[tmp[0]]=inf;
        all_dis[tmp[1]]=inf;
    }
}
