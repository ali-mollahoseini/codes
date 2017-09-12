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
const int MX1=101;
const int MX2= 100*1000+10;
const int inf=2*1000*1000*1000*1000*1000*1000;

string s;
pair<int,int> a[24];
bool  is(string str){
    bool tf=1;
    if(str[0]!=str[4]){
        tf=0;
    }
    if(str[1]!=str[3]){
        tf=0;
    }
    return tf;
}
int main(){
    cin>>s;
    char c='a';
    c++;
    int cntr=0;
    bool tff=1;
    while(tff){
        if(is(s)){
            break;
        }else{
            if(s[4]=='9'){
                s[4]='0';
                if(s[3]=='5'){
                    s[3]='0';
                    if(s[1]=='3'&&s[0]=='2'){
                        s[1]='0';
                        s[0]='0';
                    }else if(s[1]=='9'){
                        s[1]='0';
                        s[0]=s[0]+1;
                    }else{
                        s[1]=s[1]+1;
                    }
                }else{
                    s[3]=s[3]+1;
                }
            }else{
                s[4]=s[4]+1;
            }
            cntr++;
        }
        //cout<<s<<endl;
    }
    cout<<cntr;
}
