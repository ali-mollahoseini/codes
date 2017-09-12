#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=100+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFFF;
string s;
int n;
int main(){
    cin>>n>>s;
    string dec=s;

	int cur=((n+1)/2)-1,way,miz=0;
	if(n%2==0){
		way=-1;
	}else{
		way=1;
	}
	for(int i=0;i<n;i++){
		//cerr<<cur<<" "<<miz;
		cur+=miz*way;
		//cerr<<cur<<endl;
		dec[cur]=s[i];
		way*=-1;
		miz++;
	}
	cout<<dec;
}
