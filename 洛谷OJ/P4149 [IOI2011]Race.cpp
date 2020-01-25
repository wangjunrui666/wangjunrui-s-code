#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define re register
using namespace std;



template<typename T>
inline void read(T&x)
{
	x=0;
	char s=(char)getchar();
	bool f=false;
	while(!(s>='0'&&s<='9'))
	{
		if(s=='-')
			f=true;
		s=(char)getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x<<1)+(x<<3)+s-'0';
		s=(char)getchar();
	}
	if(f)
		x=(~x)+1;
	return;
}



const int N=2e5+5,INF=0x3f3f3f3f;
struct Edge
{
	int next,to,dis;
	Edge() {}
	Edge(int x,int y,int z):next(x),to(y),dis(z) {}
};
Edge edge[N<<1];
int head[N],num_edge;
inline void add_edge(int from,int to,int dis)
{
	edge[++num_edge]=Edge(head[from],to,dis);
	head[from]=num_edge;
}



#define size sze
int size[N],f[N],sum,root;
bool vis[N];
inline void getroot(int u,int fa)
{
	size[u]=1;
	f[u]=0;
	for(re int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		if(vis[v]||v==fa)
			continue;
		getroot(v,u);
		size[u]+=size[v];
		f[u]=max(f[u],size[v]);
	}
	f[u]=max(f[u],sum-size[u]);
	if(f[root]>f[u])
		root=u;
}




int now1[N],now2[N],st[N],ans;
int n,k;
inline void getdeep(int u,int fa,int f1,int f2)
{
	if(f1>k)
		return;
	now1[++now1[0]]=f1;
	now2[now1[0]]=f2;
	for(re int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to,&w=edge[i].dis;
		if(vis[v]||v==fa)
			continue;
		getdeep(v,u,f1+w,f2+1);
	}
}
inline void calc(int u)
{
	queue<int>q;
	for(re int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to,&w=edge[i].dis;
		if(vis[v])
			continue;
		now1[0]=0;
		getdeep(v,u,w,1);
		for(re int j=1; j<=now1[0]; ++j)
			ans=min(st[k-now1[j]]+now2[j],ans);
		for(re int j=1; j<=now1[0]; ++j)
		{
			st[now1[j]]=min(st[now1[j]],now2[j]);
			q.push(now1[j]);
		}
	}
	while(!q.empty())
	{
		st[q.front()]=INF;
		q.pop();
	}
}
inline void solve(int u)
{
//	printf("%d\n",u);
	vis[u]=true;
	st[0]=0;
	calc(u);
	for(re int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		if(vis[v])
			continue;
		sum=size[v];
		root=0;
		getroot(v,0);
		solve(root);
	}
}



int main()
{
	read(n);
	read(k);
	memset(st,0x3f,sizeof(st));
	for(re int i=1; i<n; ++i)
	{
		int u,v,w;
		read(u),read(v),read(w);
		add_edge(u+1,v+1,w);
		add_edge(v+1,u+1,w);
	}
	ans=f[0]=INF;
	sum=n;
	getroot(1,0);
//	printf("%d\n",root);
	solve(root);
	printf("%d\n",ans>=n?-1:ans);
}
