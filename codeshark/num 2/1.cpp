//in the name of god;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX1=1000*1000*1000;
const int MX2= 8193;
const int inf=0x7FFFFFFF;
const int delta=145253;

#define int long long
ofstream fout("1.txt");
vector<int> ones[21];

ll tables;
int pyr[1000];
int l=111111 ,r=111111*2;

int bp(int a,int b){
    if(b==0)return 1;
    if(b==1)return a;
    int nesf=bp(a,b/2);
    nesf=(nesf*nesf)%delta;
    if(b&1)nesf=(nesf*a)%delta;
    return nesf;
}
vector<int> maghsoms;
int32_t main(){
    int ans=0;
    int n=1234;
    for(int i=1;i<n;i++){
        int num= i;
        int tmp[n+10];
        bool tf=1;
        int cntr;
        while(tf&&cntr<n+1){;
            tmp[i]++;
            if(tmp[i]>1){
                tf=0;
            }
            cntr++;
        }
        cntr
    }
}
