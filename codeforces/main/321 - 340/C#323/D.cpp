#include <iostream>

using namespace std;

int n ;
int inp[10];
int main() {
    cin>>n;
    for(int i=0;i<10;i++){
        if(i==0){
            cout<<"Q 1";
            for(int j=0;j<n-1;j++){
                cout<<0;
            }
            cout<<endl;
            cout<<flush;
        }else{
            cout<<"Q ";
            for(int j=0;j<n;j++){
                cout<<i;
            }
            cout<<endl;
            cout<<flush;
        }
        cin>>inp[i];
    }
    cout<<"A ";
    for(int i=9;i+1;i--){
        while(inp[i]--){
            cout<<i;
        }
    }
    cout<<endl;
}
