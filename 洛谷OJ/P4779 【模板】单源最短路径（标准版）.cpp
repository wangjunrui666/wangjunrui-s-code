#include <bits/stdc++.h>
#define re register
using namespace std;

inline int read()
{
	int X=0,w=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-') w=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9') X=(X<<3)+(X<<1)+c-'0',c=getchar();
	return X*w;
}

struct Edge
{
	int v,w,nxt;
};
Edge e[500010];
int head[100010],cnt=0;

inline void addEdge(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}

int n,m,s;
int dis[100010];

struct node   //¶Ñ½Úµã
{
	int u,d;
	bool operator <(const node& rhs) const
	{
		return d>rhs.d;
	}
};

inline void Dijkstra()
{
	for (re int i=1; i<=n; i++) dis[i]=2147483647;
	dis[s]=0;
	priority_queue<node> Q; //¶Ñ
	Q.push((node){s,0});
	while (!Q.empty())
	{
		node fr=Q.top();
		Q.pop();
		int u=fr.u,d=fr.d;
		if (d!=dis[u]) continue;
		for (re int i=head[u]; i; i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if (dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				Q.push((node)
				{
					v,dis[v]
				});
			}
		}
	}
}

int main()
{
	n=read(),m=read(),s=read();
	for (re int i=1; i<=m; i++)
	{
		int X=read(),Y=read(),Z=read();
		addEdge(X,Y,Z);
	}
	Dijkstra();
	for (re int i=1; i<=n; i++) printf("%d ",dis[i]);
	return 0;
}
