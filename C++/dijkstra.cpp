#include<bits/stdc++.h>
using namespace std;
const int MAXN=300002;
int n,m,s,cnt,head[MAXN],dist[MAXN];
struct Edge{
	int to,w,next;
}edges[MAXN];
void add(int from,int to,int w){
	edges[++cnt].to=to;
	edges[cnt].w=w;
	edges[cnt].next=head[from];
	head[from]=cnt;
}
bool flag[MAXN];
void dijkstra(){
	priority_queue<pair<int ,int >,vector<pair<int ,int > >,greater<pair<int ,int > > > q;
	//或者 priority_queue<pair<int ,int > > q 然后看下一处注释 
	dist[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(flag[x]){
			continue;
		}
		flag[x]=true;
		for(int i=head[x];i;i=edges[i].next){
			int p=edges[i].to;
			if(dist[p]>dist[x]+edges[i].w){
				dist[p]=dist[x]+edges[i].w;
				if(!flag[p]){
					q.push(make_pair(dist[p],p));
					//然后q.push(make_pair(-dist[p],p)); 
				}
			}
		}
	}
}

signed main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	for(int i=1;i<=n;i++){
		dist[i]=2147483647;
	}
	dijkstra();
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	return 0;
}
