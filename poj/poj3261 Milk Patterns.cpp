#include<cstdio>
#include<algorithm>
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
}
const int N=1e6+5;
int wa[N],wb[N],ws[N],Rank[N],r[N],sa[N],height[N];
inline bool cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
inline void da(int *r,int *sa,int n,int m)
{
	re int i,j,p;
	int *x=wa,*y=wb;
	for(i=0; i<m; ++i)
		ws[i]=0;
	for(i=0; i<n; ++i)
		++ws[x[i]=r[i]];
	for(i=1; i<m; ++i)
		ws[i]+=ws[i-1];
	for(i=n-1; i>=0; --i)
		sa[--ws[x[i]]]=i;
	for(j=1,p=1; p<n; j<<=1,m=p)
	{
		for(p=0,i=n-j; i<n; ++i)
			y[p++]=i;
		for(i=0; i<n; ++i)
			if(sa[i]>=j)
				y[p++]=sa[i]-j;
		for(i=0; i<m; ++i)
			ws[i]=0;
		for(i=0; i<n; ++i)
			++ws[x[i]];
		for(i=1; i<m; ++i)
			ws[i]+=ws[i-1];
		for(i=n-1; i>=0; --i)
			sa[--ws[x[y[i]]]]=y[i];
		for(swap(x,y),p=1,i=1,x[sa[0]]=0; i<n; ++i)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}
#define rank Rank
inline void calheight(int *r,int *sa,int n)
{
	re int i,j,k=0;
	for(i=1; i<=n; ++i)
		rank[sa[i]]=i;
	for(i=0; i<n; height[Rank[i++]]=k)
		for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; ++k);
}
int n,k;
inline bool check(int x)
{
	int sum=1;
	for(re int i=1; i<=n; ++i)
		if(height[i]>=x)
		{
			++sum;
			if(sum>=k)
				return true;
		}
		else
			sum=1;
	return false;
}
int main()
{
	read(n);
	read(k);
	for(re int i=0; i<n; ++i)
	{
		read(r[i]);
		++r[i]; 
 	}
	r[n]=0;
	da(r,sa,n,1e6);
	calheight(r,sa,n);
	int left=1,right=n;
	while(left<=right)
	{
		int mid=(left+right)>>1;
		if(check(mid))
			left=mid+1;
		else
			right=mid-1;
	}
	printf("%d\n",right);
}
