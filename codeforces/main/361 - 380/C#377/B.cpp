#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=500+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF;
int n,k,a[MX1],b[MX1];

int main(){
	cin>>n>>k;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>0){
            b[i]=max(k-b[i-1],a[i]);
            ans+=max(max((k-b[i-1]),0)-a[i],0);
		}else{
            b[i]=a[i];
		}
	}
	    cout<<ans<<endl;
	for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
	}
	cout<<endl;
}
