#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#define re register
using namespace std;
namespace IO
{
	const int SIZE=1<<25;
	char ibuf[SIZE],*iS,*iT;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),iS==iT?EOF:*iS++):*iS++)
	template<typename T>
	inline void read(T & x)
	{
		x=0;
		bool b=false;
		char ch=gc();
		while(!isdigit(ch)&&ch^'-')
			ch=gc();
		if(ch=='-')
		{
			b=true;
			ch=gc();
		}
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^'0');
			ch=gc();
		}
		if(b)
			x=~x+1;
		return;
	}
#undef gc
	char Out[1<<30],*fe=Out,ch[25];
	int num=0;
	template<typename T>
	inline void write(T x)
	{
		if(!x)
			*fe++='0';
		if(x<0)
		{
			*fe++='-';
			x=-x;
		}
		while(x)
		{
			ch[++num]=x%10+'0';
			x/=10;
		}
		while(num)
			*fe++=ch[num--];
		*fe++='\n';
	}
	inline void write_str(char *s)
	{
		for(re int i=0; s[i]; i++)
			*fe++=s[i];
		*fe++='\n';
	}
	inline void flush()
	{
		fwrite(Out,1,fe-Out,stdout);
		fe=Out;
	}
}
using namespace IO;
const int N=1010,INF=0x3f3f3f3f;
int l,n,a[N],dp[101][101];
int main()
{
	while(read(l),l)
	{
		read(n);
		memset(dp,INF,sizeof(dp));
		for(re int i=1; i<=n; i++)
		{
			read(a[i]);
			dp[i][i+1]=0;
		}
		a[++n]=l;
		dp[0][1]=0;
#define j (i+len)
		for(re int len=2; len<=n; len++)
			for(re int i=0; i+len<=n; i++)
			{
				for(re int k=i+1; k<j; k++)
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[j]-a[i]);
			}
#undef j
		printf("The minimum cutting is %d.\n",dp[0][n]);
	}
	return 0;
}

