/*
ID: ali.mol1
LANG: C++
TASK: frac1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MX1=160*160;
int m;
#define inf 1000*1000*1000
ifstream fin ("frac1.in");
ofstream fout ("frac1.out");
pair<double,pair<int,int> > nums[MX1];

int main (){
    fin>>m;
    int cntr=0;
    double ii=1;
    double jj=0;
    for(int i=1;i<=m;i++,ii++){
        for(int j=0;j<=i;j++,jj++){
            if(__gcd(i,j)==1){
                nums[cntr].first=jj/ii;
                cout<<jj<<" "<<ii;
                nums[cntr].second.first=j;
                nums[cntr].second.second=i;
                cntr++;
            }
        }
        jj=0;
    }
    sort(nums,nums+cntr);
    for(int i=0;i<cntr;i++){
        cout<<nums[i].second.first<<"/"<<nums[i].second.second<<endl;
        fout<<nums[i].second.first<<"/"<<nums[i].second.second<<endl;
    }
}
