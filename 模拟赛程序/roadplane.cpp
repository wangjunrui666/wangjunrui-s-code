#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
#define re register
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(re int i=a;i<=b;++i)
#define per(i,a,b) for(re int i=a;i>=b;--i)
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
}
template<typename T,typename ...T1>
inline void read(T&x,T1&...x1)
{
	read(x);
	read(x1...);
}
template<typename T>
inline void clear(T*array,int l,int r,int val)
{
	memset(&array[l],val,sizeof(T)*(r-l+1));
}
using namespace std;
const ll INF=1e18;
const int N=2e6+5;
struct Edge
{
	int next,to,dis;
} edge[N];
int head[N],num_edge;
inline void add_edge(int from,int to,int dis)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
}
ll dis[N];
inline void spfa(int s)
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	deque<int>q;
	q.push_back(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop_front();
		for(int i=head[u]; i; i=edge[i].next)
		{
			int &v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].dis)
			{
				dis[v]=dis[u]+edge[i].dis;
				if(dis[v]<dis[q.front()])
					q.push_front(v);
				else
					q.push_back(v);
			}
		}
	}
}
signed main()
{
	freopen("roadplane.in","r",stdin),freopen("roadplane.out","w",stdout);
	int t,r,p,s;
	read(t,r,p,s);
	for(int i=1; i<=r; ++i)
	{
		int a,b,c;
		read(a,b,c);
		add_edge(a,b,c);
		add_edge(b,a,c);
	}
	for(int i=1; i<=p; ++i)
	{
		int a,b,c;
		read(a,b,c);
		add_edge(a,b,c);
	}
	spfa(s);
	for(int i=1; i<=t; ++i)
	{
		if(dis[i]>dis[0]/2)
			printf("NO PATH\n");
		else
			printf("%lld\n",dis[i]);
	}
	return 0;
}


