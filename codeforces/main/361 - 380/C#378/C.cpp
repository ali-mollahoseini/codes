#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000*1000*1000+7;
const int MX1=8*1000*1000+100;
const int MX2= 2*1000+100;
const int inf=100*1000*1000*100;
int n,nlst;
struct pre{
	char way;
	int rpnt;
	int mxb;
	int s;
};
vector<int> lst;
vector<int> lst2;
vector<int> nat;
vector<pre> p;
vector<pair<int,char> > todo;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		lst.push_back(tmp);
		lst2.push_back(tmp);
	}
	cin>>nlst;
	for(int i=0;i<nlst;i++){
		int tmp;
		cin>>tmp;
		nat.push_back(tmp);
	}
	int sum=0;
	int cntr=0;
	int mx=0;
	int cnt=0;
	bool tf=0;
	int r,l;
	for(int i=0;i<n;i++){
		if(cnt>0&& !tf){
			if(lst[i]!=lst[i-1]){
				tf=1;
			}
		}
		sum+=lst[i];
		mx=max(lst[i],mx);
		cnt++;
		if(nat[cntr]==sum){
			if(!tf&&cnt>1){
				cout<<"NO";
				return 0;
			}
			if(lst[i]==mx){
				p.push_back({'L',i,mx,r});
			}else if(lst[i]!=mx){
				p.push_back({'R',i,mx,l});
			}
			l=inf;
			tf=0;
			sum=0;
			mx=0;
			cnt=0;
			cntr++;
		}else if(nat[cntr]<sum||(nat[cntr]>sum&&i==n-1)){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	//cout<<1;
	cntr=0;
	for(int i=0;i<nlst;i++){
        int num=p[i].mxb,rp=p[i].rpnt,l=-1,r=inf;
        if(p[i].way=='L'){
            cntr++;
            while(cntr<=rp){
                if(lst[cntr]==num&& lst[cntr-1]!=lst[cntr]){
                    l=max(cntr,l);
                }
                cntr++;
            }
            p[i].s=l;
        }else{
            while(cntr<rp){
                while(cntr<rp){
                    if(lst[cntr]==num&& lst[cntr+1]!=lst[cntr]){
                        r=min(cntr,r);
                    }
                    cntr++;
                }
            }
            p[i].s=r;
        }
	}
	cout<<"YES"<<endl;
	cntr=0;
	for(int i=nlst-1;i>-1;i--){
		int cur=p[i].s;
		int curr=p[i].rpnt;
		int tmp;
		if(i==0){

			tmp=0;
		}else{
			tmp=p[i-1].rpnt+1;
		}
		if(curr-tmp==0){
            continue;
		}
		int tmpcnt=0;
		//cout<<tmp;
		if(p[i].way=='L'){
            while(cur!=tmp){
                //cout<<1<<" "<<i<<"L";
                todo.push_back({cur,'L'});
                lst.erase(lst.begin()+cur-1);
                cur--;
                curr--;
            }
            while(curr!=tmp){
                //cout<<1<<" "<<i<<"R";
                todo.push_back({tmp,'R'});
                lst.erase(lst.begin()+i+1);
                curr--;
            }
		}else {
            while(curr!=p[i].s){
                //cout<<1<<" "<<i<<"R";
                todo.push_back({p[i].s,'R'});
                lst.erase(lst.begin()+i+1);
                curr--;
            }
            while(cur!=tmp){
                todo.push_back({cur,'L'});
                lst.erase(lst.begin()+cur-1);
                cur--;
                curr--;
            }
		}
	}
        //cout<<todo.size()<<endl;
	for(int i=0;i<todo.size();i++){
		cout<<todo[i].first+1<<" "<<todo[i].second<<endl;
	}
    return 0;
}
