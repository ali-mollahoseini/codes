/*
ID: ali.mol1
LANG: C++
TASK: sprime
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
ifstream fin ("sprime.in");
ofstream fout ("sprime.out");


int ar[4]={1,3,7,9},ar2[4]={2,3,5,7},n;
vector<int> vec,vec1;
int poww(int a,int up){
    int tmp=1;
    for(int i=0;i<up;i++){
        tmp*=a;
    }
    return tmp;
}
bool aval(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
void avalmaker(int length){
    if(length==n){
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(5);
        vec.push_back(7);
        cout<<1;
        if(n!=1)
            avalmaker(n-1);
    }else{
        for(int it=0;it<vec.size();it++){
            int tmp=vec[it];
            for(int i=0;i<4;i++){
                vec1.push_back(10*tmp+ar[i]);
            }
        }
        vec.clear();
        for(int it=0;it<vec1.size();it++){
            vec.push_back(vec1[it]);
        }
        vec1.clear();
        if(length!=1){
            avalmaker(length-1);
        }
    }
}
int main (){
    fin>>n;
    avalmaker(n);
    sort(vec.begin(),vec.end());
    for(int it=0;it<vec.size();it++){
        int tmp=vec[it];
        bool tf=1;
        for(int i=n-1;i>-1;i--){
            if(aval(tmp/poww(10,i))==0){
                tf=0;
                break;
            }
        }
        if(tf==1){
            fout<<tmp<<endl;
        }
    }
}
