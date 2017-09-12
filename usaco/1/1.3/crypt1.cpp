/*
ID: ali.mol1
LANG: C++
TASK: crypt1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MX1=100+10;
ofstream fout ("crypt1.out");
ifstream fin ("crypt1.in");
int n,ans,ans2[2],sum;
int ar[MX1];
int  st[4],st2[2],cntr[2];
bool kochektar(int a,int b){
    return (a>b);
}
int Nargham(int a){
    int cntrx=0;
    while(a!=0){
        a/=10;
        cntrx++;
    }
    return cntrx;
}
bool anscheck(int w,int te){
    int tedad=Nargham(w);
    //fout<<tedad<<" "<<w<<endl;
    bool tf=0;
    if(tedad!=te){
        return false;
    }
    for(int i=0;i<tedad;i++){
        int md=w%10;
        for(int j=0;j<n+1;j++){
            if(ar[j]==md){
                tf=1;
            }
        }
        if(tf==1){
            tf=0;
            w/=10;
            continue;
        }
        return false;
    }
    return true;
}
int main (){
    fin>>n;
    for (int i=0;i<n;i++){
        fin>>ar[i];
        //fout<<ar[i]<<" ";
    }
    //fout<<endl;
    sort(ar,ar+n);
    n--;
    int x=100*ar[n]+10*ar[n]+ar[n];
    //fout<<x<<endl;
    int cnt1=0,cnt2=0,cnt3=0;
    ans=100*ar[cnt1]+10*ar[cnt2]+ar[cnt3];
    while(ans!=x){
        ans=100*ar[cnt1]+10*ar[cnt2]+ar[cnt3];
        //fout<<ans<<endl;
        for(int i=0;i<n+1;i++){
            ans2[0]=ar[i];
            for(int j=0;j<n+1;j++){
                ans2[1]=ar[j];
                //fout<<ans2[0]<<ans2[1]<<endl;
                int tmp=10*ans2[1]*ans+ans2[0]*ans;
                if(anscheck(ans2[1]*ans,3)&&anscheck(ans2[0]*ans,3)&&anscheck(tmp,4)){
                    //fout<<tmp<<"la la"<<endl;
                    sum++;
                }
            }
        }
        cnt3++;
        if(cnt3>n){
            cnt2++;
            cnt3=0;
            if(cnt2>n){
                cnt1++;
                cnt2=0;
            }
        }
    }
    fout<<sum<<endl;
}
