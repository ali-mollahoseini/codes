/*
ID: ali.mol1
LANG: C++
TASK: preface
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
const int MX1=25+20;
const int inf=1000*1000*1000;
int n;
string roman[3010],num[3500];
map<char,int> mp;
#define inf 1000*1000*1000
ifstream fin ("preface.in");
ofstream fout ("preface.out");
int rev(int a){
    int ans=0;
    while(a!=0){
        ans+=a%10;
        a/=10;
        if(a==0) continue;
        ans*=10;
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
    roman[0]="";roman[1]="I";roman[2]="II";roman[3]="III";roman[4]="IV";roman[5]="V";roman[6]="VI";roman[7]="VII";roman[8]="VIII";roman[9]="IX";
    roman[10]="X";roman[20]="XX";roman[30]="XXX";roman[40]="LX";roman[50]="L";roman[60]="XL";roman[70]="XXL";roman[80]="XXXL";roman[90]="CX";
    roman[100]="C";roman[200]="CC";roman[300]="CCC";roman[400]="DC";roman[500]="D";roman[600]="CD";roman[700]="CCD";roman[800]="CCCD";roman[900]="MC";
    roman[1000]="M";roman[2000]="MM";roman[3000]="MMM";
    fin>>n;
    for(int i=1;i<=n;i++){
        int ri=i;int cntr=0;
        while(ri!=0){
            cout<<ri<<" "<<(ri%10)<<" "<< poww(10,cntr)<<endl;
            cout<<roman[(ri%10)*poww(10,cntr)]<<endl;
            string s=roman[(ri%10)*poww(10,cntr)];
            num[i]+=s;
            ri/=10;
            cntr++;
        }
        for(int j=0;j<num[i].size();j++){
            mp[num[i][j]]++;
        }
    }
    if(mp['I']!=0){
        fout<<"I"<<" "<<mp['I']<<endl;
    }
    if(mp['V']!=0){
        fout<<"V"<<" "<<mp['V']<<endl;
    }
    if(mp['X']!=0){
        fout<<"X"<<" "<<mp['X']<<endl;
    }
    if(mp['L']!=0){
        fout<<"L"<<" "<<mp['L']<<endl;
    }
    if(mp['C']!=0){
        fout<<"C"<<" "<<mp['C']<<endl;
    }
    if(mp['D']!=0){
        fout<<"D"<<" "<<mp['D']<<endl;
    }
    if(mp['M']!=0){
        fout<<"M"<<" "<<mp['M']<<endl;
    }
}
