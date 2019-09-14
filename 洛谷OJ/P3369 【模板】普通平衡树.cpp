#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define lson ch[0]
#define re register
#define rson ch[1]
#define MAX 500100
int root=0,N,tot=0;
namespace IO
{
	const int SIZE=1<<30;
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
	char Out[1<<25],*fe=Out,ch[25];
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
struct Node
{
	int ch[2],father,cnt,val,son;
} tree[MAX];

inline void push_up(int u)
{
	tree[u].son=tree[tree[u].lson].son+tree[tree[u].rson].son+tree[u].cnt;
}

inline void rotate(int x)
{
	register int y=tree[x].father;
	register int z=tree[y].father;
	register int k=tree[y].rson==x;
	tree[z].ch[tree[z].rson==y]=x;
	tree[x].father=z;
	tree[y].ch[k]=tree[x].ch[k^1];
	tree[tree[x].ch[k^1]].father=y;
	tree[x].ch[k^1]=y;
	tree[y].father=x;
	push_up(y);
	push_up(x);
}

inline void Splay(int x,int goal)
{
	while(tree[x].father!=goal)
	{
		int y=tree[x].father;
		int z=tree[y].father;
		if(z!=goal)
			(tree[y].lson==x)^(tree[z].lson==y)?rotate(x):rotate(y);
		rotate(x);
	}
	if(goal==0)
		root=x;
}

inline void insert(int x)
{
	int u=root,father=0;
	while(u&&tree[u].val!=x)
	{
		father=u;
		u=tree[u].ch[x>tree[u].val];
	}
	if(u)
		tree[u].cnt++;
	else
	{
		u=++tot;
		if(father)
			tree[father].ch[x>tree[father].val]=u;
		tree[tot].lson=0;
		tree[tot].rson=0;
		tree[tot].father=father;
		tree[tot].val=x;
		tree[tot].cnt=1;
		tree[tot].son=1;
	}
	Splay(u,0);
}

inline void Find(int x)
{
	int u=root;
	if(!u)
		return;
	while(tree[u].ch[x>tree[u].val]&&x!=tree[u].val)
		u=tree[u].ch[x>tree[u].val];
	Splay(u,0);

}

inline int Next(int x,int f)
{
	Find(x);
	int u=root;
	if((tree[u].val>x&&f)||(tree[u].val<x&&!f))
	return u;
	u=tree[u].ch[f];
	while(tree[u].ch[f^1])
	u=tree[u].ch[f^1];
	return u;
}

inline void Delete(int x)
{
	int last=Next(x,0);
	int next=Next(x,1);
	Splay(last,0);
	Splay(next,last);
	int del=tree[next].lson;
	if(tree[del].cnt>1)
	{
		tree[del].cnt--;
		Splay(del,0);
	}
	else
		tree[next].lson=0;
}

inline int K_th(int x)
{
	int u=root;
	if(tree[u].son<x)
		return false;
	while(true)
	{
		int y=tree[u].lson;
		if(x>tree[y].son+tree[u].cnt)
		{
			x-=tree[y].son+tree[u].cnt;
			u=tree[u].rson;
		}
		else if(tree[y].son>=x)
			u=y;
		else
			return tree[u].val;
	}
}
int main()
{
	insert(-2147483647);
	insert(+2147483647);
	re int N;
	read(N);
	re int opt,x;
	while(N--)
	{
		read(opt);
		read(x);
		if(opt==1)
			insert(x);
		else if(opt==2)
			Delete(x);
		else if(opt==3)
		{
			Find(x);
			write(tree[tree[root].lson].son);
		}
		else if(opt==4)
			write(K_th(x+1));
		else if(opt==5)
			write(tree[Next(x,0)].val);
		else if(opt==6)
			write(tree[Next(x,1)].val);
	}
	flush();
	return 0;
}
