#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
#define rank rk
using namespace std;
const int N=(int)5e3+5<<1;
int r[N],ws[N],wa[N],wb[N],sa[N],len,n,rank[N],height[N],kase;
int ans;
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
		for(swap(x,y),i=1,p=1,x[sa[0]]=0; i<n; ++i)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}
inline void calheight(int *r,int *sa,int n)
{
	re int i,j,h=0;
	for(i=1; i<=n; ++i)
		rank[sa[i]]=i;
	for(i=0; i<n; height[rank[i++]]=h)
		for(h?h--:0,j=sa[rank[i]-1]; r[i+h]==r[j+h]; ++h);
}
char str1[N],str2[N],answer[N][N],anssum;
bool vis[N];
int main()
{
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	while(scanf("%s%s",str1,str2)==2)
	{
		anssum=0;
		if(kase++)
			putchar('\n');
		n=strlen(str1);
		len=0;
		for(re int i=0; str1[i]; ++i)
			r[len++]=str1[i];
		r[len++]=1;
		for(re int i=0; str2[i]; ++i)
			r[len++]=str2[i];
		r[len]=2;
		da(r,sa,len+1,130);
		calheight(r,sa,len);
		ans=0;
//		for(re int i=0; i<=len; ++i)
//			printf("%d ",r[i]);
		for(re int i=2; i<=len; ++i)
			if(height[i]>ans)
				if(sa[i-1]<n&&sa[i]>n||sa[i-1]>n&&sa[i]<n)
					ans=height[i];
		printf("%d\n",ans);
		for(re int i=2; i<=len; ++i)
			if(height[i]==ans&&(sa[i-1]<n&&sa[i]>n||sa[i-1]>n&&sa[i]<n))
			{
				++anssum;
				for(re int j=0; j<ans; ++j)
					answer[anssum][j]=r[sa[i]+j];
				answer[anssum][ans]=0;
			}
		memset(vis,0,sizeof(vis));
		for(re int i=1; i<=anssum; ++i)
			for(re int j=1; j<i; ++j)
				if(strcmp(answer[i],answer[j])==0)
				{
					vis[i]=true;
					break;
				}
		for(re int i=1; i<=anssum; ++i)
			if(!vis[i]&&answer[i][0])
				printf("%s\n",answer[i]);
	}
	return 0;
}
#undef rank
