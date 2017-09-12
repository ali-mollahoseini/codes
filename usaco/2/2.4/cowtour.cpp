/*
ID: ali.mol1
LANG: C++
TASK: cowtour
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int MX1=150+3;
const int MX2= 39;
const int inf=1000*1000*1000;
ifstream fin ("cowtour.in");
ofstream fout ("cowtour.out");



bool visited[MX1];
pair<int,pair<int,int> > pa;
map<int,double> mx_dis;
map<int,double> all_dis;
map<int,double> f_dis;
pair<int,int> diam[2];
int ldiam;
int num[2];
pair<int,int> pasture[MX1];
int n;
map<int,vector<int> > adj;
int visit[MX1];
vector<int> groups[MX1];
double maxfield[MX1];

void dijkstra(int source,int mark);
void inp();
void dfs(int v,int mark);
double dabs(double x);
double dist(pair<int,int> a,pair<int,int> b);
double max_double(double a,double b);
double min_double(double a,double b);

int main (){
    inp();
    cout<<1;
    int rang=1;
    for(int i=0;i<n;i++){
        if(visit[i]==0){
            dfs(i,rang);
            rang++;
        }
    }
    cout<<2;
    for(int j=1;j<rang;j++){
        for(int i=0;i<groups[j].size();i++){
            cout<<groups[j][i]<<endl;
            dijkstra(groups[j][i],j);
            maxfield[j]=max_double(mx_dis[groups[j][i]],maxfield[j]);
        }
    }
    cout<<maxfield[1]<<" "<<maxfield[2]<<endl;

    double minans=inf;
    for(int x=0;x<rang;x++){
        for(int y=x+1;y<rang;y++){
            for(int i=0;i<groups[x].size();i++){
                for(int j=0;j<groups[y].size();j++){
                    double tmp;
                    double anss=mx_dis[groups[x][i]]+mx_dis[groups[y][j]]+ dist(pasture[groups[y][j]],pasture[groups[x][i]]);
                    tmp=max_double(anss,maxfield[x]);
                    tmp=max_double(tmp,maxfield[y]);
                    minans=min_double(tmp,minans);
                }
            }
        }
    }
    fout << std::fixed << std::setprecision(6);
    fout<<minans<<endl;
}



double dabs(double x){
    if(x<0){
        x*=-1;
    }
    return x;
}
double dist(pair<int,int> a,pair<int,int> b){
    return sqrt((double)(b.first-a.first)*(b.first-a.first)+(double)(b.second-a.second)*(b.second-a.second));
}

double max_double(double a,double b){
    if(a>b)
        return a;
    return b;
}

double min_double(double a,double b){
    if(a<b)
        return a;
    return b;
}

void dfs(int v,int mark){
    groups[mark].push_back(v);
    visit[v]=mark;
    for(vector<int>::iterator it=adj[v].begin();it!=adj[v].end();it++){
        if(visit[*it]==0){
            dfs(*it,mark);
        }
    }
}



void dijkstra(int source,int mark){
    int last=source;
    f_dis[source]=0;
    all_dis[source]=0;
    visited[source]=1;
    double mx=-1;
    int adad;
    for(int i=0;i<groups[mark].size();i++){
        double mn =inf;
        for(vector<int>::iterator it=adj[last].begin();it!=adj[last].end();it++){
            int x=*it;
            if(visited[x]==0){
                double tmpdis=dist(pasture[x],pasture[last]);
                f_dis[x]=min(f_dis[x],all_dis[last]+tmpdis);
                all_dis[x]=f_dis[x];
            }
        }
        for(map<int,double>::iterator it=f_dis.begin();it!=f_dis.end();it++){
            if(it->second<mn){
                mn=it->second;
                last=it->first;
            }
        }
        visited[last]=1;
        f_dis[last]=inf;
        if(all_dis[last]>mx){
            mx=all_dis[last];
            cout<<source<<" "<<mx<<" "<<endl;
            adad=last;
        }
    }
    mx_dis[source]=mx;
    for(int i=0;i<n;i++){
        f_dis[i]=inf;
        all_dis[i]=inf;
        visited[i]=0;
    }
}




void inp(){
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>pasture[i].first>>pasture[i].second;
    }
    for(int i=0;i<n;i++){
        string tmp;
        fin>>tmp;
        for(int j=0;j<n;j++){
            if(tmp[j]=='1'){
                adj[i].push_back({j});
            }
        }
        f_dis[i]=inf;
        all_dis[i]=inf;
    }
}
