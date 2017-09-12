/*
ID: ali.mol1
LANG: C++
TASK: humble
*/
#include <bits/stdc++.h>
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
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 1000*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;
ll n;
ll ar[MX2];
ll calc(int b){
    int kol=0;
    for(int i=0;i<n;i++){
        int x=(i+b)%n+1;
        kol+=abs(ar[i]-x);
    }
    return kol;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int sums[2]={calc(0),calc(n-1)};
    if(sums[0]>sums[1]){
        int first =n-1;
        int sum=calc(first);
        int last=0;
        int  x=(first+last)/2;
        int cntr=0;
        while(first>last){
                //cerr<<1;
            x=(first+last)/2;
            int tmp=calc(x);
            if(tmp<sum){
                sum=tmp;
                first = x;
            }else {
                last = x+1;
            }
            cntr++;
            if(cntr>20){
                if(calc(last)>sum){
                    break;
                }else{
                    sum=calc(last);
                    first=last;
                    break;
                }
            }
        }
        cout<<sum<<" "<<first;
    }else{
        int first =0;
        int sum=calc(first);
        int last = n-1;
        int  x=(first+last)/2;
        int cntr=0;
        while(first<last){
            x=(first+last)/2;
            int tmp=calc(x);
            if ( tmp<sum){
                sum=tmp;
                first = x;
            }else {
                last = x-1;
            }
            cntr++;
            if(cntr>20){
                if(calc(last)>sum){
                    break;
                }else{
                    sum=calc(last);
                    first=last;
                    break;
                }
            }
        }
        cout<<sum<<" "<<first;
    }

}
