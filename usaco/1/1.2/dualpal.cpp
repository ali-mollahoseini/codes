/*
ID: ali.mol1
LANG: C++
TASK: dualpal
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
ofstream fout ("dualpal.out");
ifstream fin ("dualpal.in");
vector<int> vec;
bool b[5000];
int n,s,ar[20],idle,busy;
 bool is_palindrome(){
     bool tf=true;
     vector<int>rev;
     for(int i=0;i<vec.size();i++){
        rev.push_back(vec.at(vec.size()-1-i));
     }
     for(int i=0;i<vec.size();i++){
        if(rev.at(i)!=vec.at(i)){
            tf =false;
        }
     }
     return(tf==true)? true : false;
 }
 void change_radix(int input,int scndbase){
     while(input>0){
        vec.push_back(input%scndbase);
        input/=scndbase;
     }
 }
int main (){
    int x=0;
    fin>>n>>s;
    s++;
    while(n>0){
        int j=0;
        for(int i=0;i<9;i++){
            change_radix(s,i+2);
            (is_palindrome()==true)?j++:j=j;
             vec.clear();
        }
        if(j>=2){
        n--;ar[x]=s;s++;x++;
        }else{
            s++;
        }
    }
    for(int i=0;i<x;i++){
        fout<<ar[i]<<endl;
    }
    return 0;
}
