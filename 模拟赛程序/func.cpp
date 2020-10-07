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
const int N=1e7;
int phi[N],prime[664579+5],tot,ans[N][3];
bitset<N>vis;
inline void getprime(int n)
{
	memset(ans,0x3f,sizeof(ans));
	phi[1]=1;
	ans[1][0]=ans[1][1]=ans[1][2]=0;
	for(int i=2; i<=n; ++i)
	{
		if(!vis[i])
		{
			prime[++tot]=i;
			phi[i]=i-1;
		}
		ans[i][0]=ans[phi[i]][0]+1;
		ans[i][1]=min(ans[i/2+1][0],ans[phi[i]][1])+1;
		ans[i][2]=min(ans[i/2+1][1],ans[phi[i]][2])+1;
		for(int j=1; j<=tot; ++j)
		{
			if(prime[j]*i>n)
				break;
			vis.set(i*prime[j]);
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
//	for(int i=1; i<=11; ++i)
//		printf("%d %d %d %d %d\n",i,phi[i],ans[i][0],ans[i][1],ans[i][2]);
}
inline int getphi(int n)
{
	int res=n,i;
	for(i=1; i<=tot&&prime[i]*prime[i]<=n; ++i)
		if(n%prime[i]==0)
		{
			do
				n/=prime[i];
			while(n%prime[i]==0);

			res=res/prime[i]*(prime[i]-1);
		}
	if(n>1)
		res=res/n*(n-1);
	return res;
}
inline int dfs(int n,int k)
{
	if(n<=N-5)
		return ans[n][k];
	if(k==0)
		return dfs(getphi(n),0)+1;
	else if(k==1)
		return min(dfs(getphi(n),1),dfs(n/2+1,0))+1;
	else
		return min(dfs(getphi(n),2),dfs(n/2+1,1))+1;
}
signed main()
{
	freopen("func.in","r",stdin),freopen("func.out","w",stdout);
	getprime(N-5);
//	for(int i=1; i<=1e5; ++i)
//	{
////		if(getphi(i)!=phi[i])
////		{
////			printf("%d\n",i);
////			return 0;
////		}
//		assert(getphi(i)==phi[i]);
//	}
	int T;
	read(T);
	while(T--)
	{
		int n,k;
		read(n,k);
		printf("%d\n",dfs(n,k));
	}
//	printf("%d %d\n",(sizeof(ans)+sizeof(phi)+sizeof(prime))/(1<<20),tot);
	return 0;
}


