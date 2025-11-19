#include <bits/stdc++.h>
using namespace std;
const int INF=0x7f7f7f;
const int MAXN=50005;
int n,m,j,cnt,head[MAXN],dist[MAXN];
struct Edge{
	int from,to,w,next;
}edges[MAXN];
bool flag[MAXN];
void add(int from,int to,int w){
	edges[++cnt].from=from;
	edges[cnt].to=to;
	edges[cnt].w=w;
	edges[cnt].next=head[from];
	head[from]=cnt;
}
void SPAF(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		flag[p]=false;
		for(int e=head[p];e!=0;e=edges[e].next){
			int to=edges[e].to;
			if(dist[to]>dist[p]+edges[e].w){
				dist[to]=dist[p]+edges[e].w;
				if(!flag[to]){
					flag[to]=true;
					q.push(to);
				}
			}
		}
	}
}
int main(){
	cin>>n>>m>>j;
	for(int i=1;i<=MAXN;i++){
		dist[i]=INF;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	dist[j]=0;
	SPAF(j);
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	return 0;
}
