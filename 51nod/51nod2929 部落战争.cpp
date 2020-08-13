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
inline void clear(T*a,int l,int r,int val)
{
	memset(&a[l],val,sizeof(T)*(r-l+1));
}
const int N=1e6+5;
std::bitset<N>vis;
int belong[N];
struct Edge
{
	int next,to;
} edge[N];
int head[N],num_edge;
inline void add_edge(int from,int to)
{
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
int n,m,r,c;
char mp[1005][1005];
inline bool check(int x,int y)
{
	return (x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]=='.');
}
inline int calc(int x,int y)
{
	return (x-1)*m+y;
}
inline bool find(int u)
{
	for(re int i=head[u]; i; i=edge[i].next)
	{
		int &v=edge[i].to;
		if(vis[v])
			continue;
		vis[v]=true;
		if(!belong[v]||find(belong[v]))
		{
			belong[v]=u;
			return true;
		}
	}
	return false;
}
signed main()
{
	read(n,m,r,c);
	for(re int i=1; i<=n; ++i)
		scanf("%s",mp[i]+1);
	int sum=0;
	for(re int i=1; i<=n; ++i)
		for(re int j=1; j<=m; ++j)
		{
			if(mp[i][j]=='x')
				++sum;
			if(check(i,j))
			{
				if(check(i+r,j+c))
					add_edge(calc(i,j),calc(i+r,j+c)+n*m);
				if(check(i+c,j+r))
					add_edge(calc(i,j),calc(i+c,j+r)+n*m);
				if(check(i+r,j-c))
					add_edge(calc(i,j),calc(i+r,j-c)+n*m);
				if(check(i+c,j-r))
					add_edge(calc(i,j),calc(i+c,j-r)+n*m);
			}
		}
	int ans=0;
//	for(re int u=1; u<=n*m; ++u)
//	{
//		printf("%d:",u);
//		for(re int i=head[u]; i; i=edge[i].next)
//			printf(" %d",edge[i].to-n*m);
//		putchar('\n');
//	}
	for(re int i=1; i<=n*m; ++i)
	{
		vis.reset();
		if(find(i))
			++ans;
	}
	printf("%d\n",n*m-ans-sum);
	return 0;
}


