#include<cstdio>
#define re register
using namespace std;
template<typename T>
inline void read(T&x)
{
	x=0;
	char s=getchar();
	bool f=false;
	while(!(s>='0'&&s<='9'))
	{
		if(s=='-')
			f=true;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x<<1)+(x<<3)+s-'0';
		s=getchar();
	}
	if(f)
		x=(~x)+1;
	return;
}
int n;
double f[1000010],g[1000010];
int main()
{
	read(n);
	for(re int i=n-1; ~i; i--)
	{
		f[i]=f[i+1]+(double)n/(double)(n-i);
		g[i]=(double)i/(n-i)*(f[i]+1)+g[i+1]+f[i+1]+1;
	}
	printf("%.2lf\n",g[0]);
	return 0;
}

