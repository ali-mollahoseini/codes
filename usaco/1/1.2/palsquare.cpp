/*
ID: ali.mol1
LANG: C++
TASK: palsquare
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
ofstream fout ("palsquare.out");
ifstream fin ("palsquare.in");
vector<char> vec;
bool b[5000];
int n,s,ar[20],idle,busy;
 bool is_palindrome(){
     bool tf=true;
     vector<char>rev;
     for(int i=0;i<vec.size();i++){
        rev.push_back(vec.at(vec.size()-1-i));
     }
     for(int i=0;i<vec.size();i++){
        if(rev.at(i)!=vec.at(i)){
            tf =false;
        }
     }
     if(tf==true){
        return true;
     }else{
        return false;
    }
 }
 void change_radix(int input,int scndbase){
     string d = "0123456789ABCDEFGHIJ";
     while(input>0){
        vec.push_back(d.at(input%scndbase));
        input/=scndbase;
     }

     vector<char>rev2;
     for(int i=0;i<vec.size();i++){
        rev2.push_back(vec.at(vec.size()-1-i));
     }


 }
int main (){
    int x=0;
    fin>>n;
    for(int y=1;y<300;y++){
        int j=0;
            change_radix(y*y,n);
            (is_palindrome()==true)?j++:j=j;
             vec.clear();
        if(j==1){
        ar[x]=y;x++;
        }
    }
    for(int i=0;i<x;i++){
        change_radix(ar[i],n);
        for(int i=0;i<vec.size();i++){
        fout<<vec.at(vec.size()-i-1);
        }
        fout<<" ";
        vec.clear();
        change_radix(ar[i]*ar[i],n);
        for(int i=0;i<vec.size();i++){
        fout<<vec.at(i);
        }
        fout<<endl;
        vec.clear();
    }
    return 0;
}
