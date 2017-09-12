#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define FR(n)ss
const int mod=1000*1000*1000+7;
const int MX1=60;
const int MX2= 200*1000+10;
const int inf=2*1000*1000*1000;
string s;
string ans;
int n;
int main(){
	cin>>n;
	cin>>s;
	int flg=0;
	for(int i=0;i<n;i++){
		if(s[i]=='o'){
			while(i+2<n){
                //cout<<s[min(i+1,n-1)]<<" "<<s[min(i+2,n-1)]<<endl;;
				if(s[min(i+1,n-1)]=='g'&&s[min(i+2,n-1)]=='o'){
					i+=2;
					flg=1;
					continue;
				}
				break;
			}
			if(flg){
				ans.push_back('*');
				ans.push_back('*');
				ans.push_back('*');
				flg=0;
			}else{
				ans.push_back(s[i]);
			}
		}else{
			ans.push_back(s[i]);
		}
	}
	cout<<ans;
}

