/*
ID: ali.mol1
LANG: C++
TASK: pprime
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
const int MX1=200;
#define inf 1000*1000*1000
ifstream fin ("pprime.in");
ofstream fout ("pprime.out");


int ar[4]={1,3,7,9},r,l;
set<int> st;
bool mark [MX1][MX1][MX1];
bool aval(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
void avalmaker(){
    for(int i=5;i<10;i++){
        st.insert(i);
    }
    for(int i=0;i<4;i++){
        int tmp=10*ar[i]+ar[i];
            st.insert(tmp);
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            int tmp=100*ar[i]+10*j+ar[i];
                st.insert(tmp);
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            int tmp=1000*ar[i]+100*j+10*j+ar[i];
                st.insert(tmp);
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                int tmp=10000*ar[i]+1000*j+100*k+10*j+ar[i];
                    st.insert(tmp);
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                int tmp=100000*ar[i]+10000*j+1000*k+100*k+10*j+ar[i];
                    st.insert(tmp);
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int l=0;l<10;l++){
                    int tmp=1000000*ar[i]+100000*j+10000*k+1000*l+100*k+10*j+ar[i];
                        st.insert(tmp);
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int l=0;l<10;l++){
                    int tmp=10000000*ar[i]+1000000*j+100000*k+10000*l+1000*l+100*k+10*j+ar[i];
                        st.insert(tmp);
                }
            }
        }
    }
}
int main (){
    avalmaker();
    fin>>r>>l;
    for(set<int>::iterator it=st.begin();it!=st.end();it++){
        if(*it>=r&&*it<=l){
            if(aval(*it)){
                fout<<*it<<endl;
            }
        }
        if(*it>l){
            break;
        }
    }
}
