#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500002;
int c=0,st[MAXN],ed[MAXN],n,m,belong[MAXN],a[MAXN];
int sum[MAXN],mark[MAXN],size[MAXN],ans=0;
void init(){
	int sq=sqrt(n);
	for(int i=1;i<=n;i+=sq){
		st[++c]=i;
		ed[c]=min(i+sq-1,n);
	}
	for(int i=1;i<=c;i++){
		for(int j=st[i];j<=ed[i];j++){
			belong[j]=i;
			sum[i]+=a[j];
		}
	}
	for(int i=1;i<=c;i++)
    size[i]=ed[i]-st[i]+1;
}
void change(int x,int y,int k){
	if(belong[x]==belong[y]){
		for(int i=x;i<=y;i++){
			a[i]+=k;
			sum[belong[i]]+=k;
		}
	}
	for(int i=x;i<=ed[belong[x]];i++){
		a[i]+=k;
		sum[belong[i]]+=k;
	}
	for(int i=st[belong[y]];i<=y;i++){
		a[i]+=k;
		sum[belong[i]]+=k;
	}
	for(int i=belong[x]+1;i<=belong[y]-1;i++){
		mark[i]+=k;
	}
}
int query(int x,int y){
	ans=0;
	if(belong[x]==belong[y]){
		for(int i=x;i<=y;i++){
			ans+=a[i]+mark[belong[i]];
		}
		return ans;
	}
	for(int i=x;i<=ed[belong[x]];i++){
		ans+=a[i]+mark[belong[i]];
	}
	for(int i=st[belong[y]];i<=y;i++){
		ans+=a[i]+mark[belong[i]];
	}
	for(int i=belong[x]+1;i<=belong[y]-1;i++){
		ans+=sum[i]+mark[i]*size[i];
	}
	return ans;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	init();
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		if(x==1){
			int y,z,c;
			cin>>y>>z>>c;
			change(y,z,c);
		}
		if(x==2){
			int y,z;
			cin>>y>>z;
			cout<<query(y,z)<<endl;;
		}
	}
	return 0;
}
