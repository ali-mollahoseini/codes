#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=1000*1000+10;
const int MX2= 200*1000+10;
const int inf=0x7FFFFFF;
int n,r[MX1],l[MX1];

int main(){
	cin>>n;
	int sumr=0,suml=0;
	for(int i=0;i<n;i++){
		cin>>l[i]>>r[i];
		sumr+=r[i];
		suml+=l[i];
	}
	int ans=0;
	int mx=abs(sumr-suml);

	for(int i=0;i<n;i++){
		int tmpr=sumr-r[i]+l[i],tmpl=suml-l[i]+r[i];
		if(abs(tmpr-tmpl)>mx){
			mx=abs(tmpr-tmpl);
			ans=i+1;
		}
	}
	cout<<ans<<endl;
	cerr<<mx<<endl;
}
