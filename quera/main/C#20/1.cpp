#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX1=1000*100+10;
const int MX2= 39;
const int inf=0x7FFFFFFF;

int ar[MX1][2],n;
vector<int> vec;
int main (){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i][0];
    }
    for(int i=0;i<n;i++){
        cin>>ar[i][1];
    }
    for(int i=0;i<n;i++){
        if(ar[i][1]){
            vec.push_back(ar[i][0]);
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
