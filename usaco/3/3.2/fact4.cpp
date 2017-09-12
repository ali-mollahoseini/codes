/*
ID: ali.mol1
LANG: C++
TASK: fact4
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
ifstream fin ("fact4.in");
ofstream fout ("fact4.out");

int n,sum=1;


int main (){
    fin>>n;

    for(int i=2;i<=n;i++){
        sum*=i;
        int tmp=sum;
        while(tmp%10==0){
            tmp/=10;
        }
        sum=tmp%10+(tmp/10)%10*10+((tmp/100)%10)*100+((tmp/1000)%10)*1000;
        cout<<sum<<endl;
    }
    fout<<sum%10<<endl;
}
