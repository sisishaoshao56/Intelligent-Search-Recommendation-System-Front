#include<bits/stdc++.h> 
using namespace std;
#define MAXN 500005
#define lowbit(x) ((x) & (-x))
int n,m;
int tree[MAXN],num[MAXN];
void update(int i,int x){
	for(int pos=i;pos<=n;pos+=lowbit(pos)){
		tree[pos]+=x;
	}
}
int sum(int a){
	int ans=0;
	for(int pos=a;pos;pos-=lowbit(pos)){
		ans+=tree[pos];
	}
	return ans;
}
int query(int a,int b){
	return sum(b)-sum(a-1);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=m;i++){
		int a;
		cin>>a;
		if(a==1){
		int x,y,z;
		cin>>x>>y>>z;
		update(x,z);
		update(y+1,-z);
		}
		if(a==2){
			int x;
			cin>>x;
			cout<<num[x]+sum(x)<<endl;
		}
	}
	return 0;
}
