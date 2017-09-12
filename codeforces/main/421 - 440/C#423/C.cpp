#include<bits/stdc++.h>
using namespace std;
const int N=3e6+20;
int t,i,k,l,x;
char a[N];
string ans;
set <int> s;
int main()
{
	for(i=0;i<N;i++) ans+='#', s.insert(i);

	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s%d",a,&k);
		l=strlen(a);

		for(i=0;i<k;i++)
		{
			scanf("%d",&x);
			x--;

			while(true)
			{
				auto it=s.lower_bound(x);
				if(it==s.end() or *it>x+l-1) break;

				int pos=*it;
				ans[pos]=a[pos-x];
				s.erase(it);
			}
		}
	}

	while(!ans.empty() and ans.back()=='#') ans.pop_back();
	for(auto &i:ans) i=(i=='#'?'a':i);
	cout<<ans;
}
