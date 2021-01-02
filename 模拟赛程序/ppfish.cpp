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
const int N=1005,M=1e6+5;
int ch[N*20][260],tott,cnt[M],nxt[M],pos[N];
inline void insert(string str,int id)
{
	int u=0;
	for(auto s:str)
	{
		int c=s;
		if(!ch[u][c])
			ch[u][c]=++tott;
		u=ch[u][c];
	}
	pos[id]=u;
}
int q[N*2],head,tail;
inline void build()
{
	head=1,tail=0;
	for(int i=0; i<250; ++i)
		if(ch[0][i])
			q[++tail]=ch[0][i];
	while(head<=tail)
	{
		int u=q[head];
		++head;
		for(int c=0; c<250; ++c)
			if(!ch[u][c])
				ch[u][c]=ch[nxt[u]][c];
			else
			{
				nxt[ch[u][c]]=ch[nxt[u]][c];
				q[++tail]=ch[u][c];
			}
	}
}
inline void work(string str)
{
	int u=0;
	for(auto s:str)
	{
		int c=s;
		u=ch[u][c];
		++cnt[u];
	}
	for(int i=tail; i>=1; --i)
		cnt[nxt[q[i]]]+=cnt[q[i]];
}
int n;
string t[N];
int a[N],p[N],c[N];
double f[N][N];
signed main()
{
	freopen("ppfish.in","r",stdin);
	freopen("ppfish.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>t[i];
		insert(t[i],i);
	}
	string str;
	cin>>str;
	build();
	work(str);
	for(int i=1; i<=n; ++i)
	{
		a[i]=cnt[pos[i]];
		p[i]=a[i];
	}
	sort(p+1,p+1+n);
	int tot=(int)(unique(p+1,p+1+n)-p-1);
	for(int i=1; i<=n; ++i)
		c[i]=(int)(lower_bound(p+1,p+1+tot,a[i])-p);
	double val;
	int len;
	cin>>val>>len;
	f[0][0]=1;
	for(int i=1; i<=len; ++i)
		for(int j=0; j<=len&&j<=tot; ++j)
		{
			f[i][j]=f[i-1][j]*val;
			if(j)
				f[i][j]+=f[i-1][j-1]*(1-val);
		}
	for(int i=1; i<=len; ++i)
	{
		for(int j=1; j<=len&&j<=tot; ++j)
			f[i][j]+=f[i][j-1];
//		for(int j=0; j<=len&&j<=tot; ++j)
//			printf("f[%d][%d]=%lf ",i,j,f[i][j]);
//		putchar('\n');
	}
//	for(int i=1; i<=n; ++i)
//		printf("%d ",c[i]);
//	putchar('\n');
	for(int i=1; i<=n; ++i)
		printf("%.3lf ",f[len][c[i]-1]);
	return 0;
}


