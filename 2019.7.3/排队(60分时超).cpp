#include<vector> 
#include<cstdio>
#include<cstring>
#include<algorithm>
#define min(a,b) (a<b?a:b)
using namespace std;
int n,t,last[100001];
struct nod{int to,next;}d[200001];
struct node{int father;vector<int> son;}f[100001];
int dui[100001],duitou,b[100001],shan[100020],tou1,wei1,so[100001],sotou;
bool bz[100001];
bool cmp(int x,int y){return x<y;}
void px(int l,int r)
{
	int x=l,y=r,mid=so[(l+r)/2];
	while(x<=y)
	{
		while(b[so[x]]<b[mid])x++;
		while(b[so[y]]>b[mid])y--;
		if(x<=y)
		{
			int t=so[x];
			so[x]=so[y];
			so[y]=t;
			x++;y--;
		}
	}
	if(x<r)px(x,r);
	if(l<y)px(l,y);
}
void dfs(int sx)
{
	for(int i=last[sx];i!=0;i=d[i].next)
	{
		if(f[sx].father!=d[i].to)
		{
			f[sx].son.push_back(d[i].to);
		}
	}
	sort(f[sx].son.begin(),f[sx].son.end(),cmp);
	for(int i=0;i<f[sx].son.size();i++)
	{
		f[f[sx].son[i]].father=sx;
		dfs(f[sx].son[i]);
	}
	dui[++duitou]=sx;
}
int dfs2(int sx,int nx)
{
	if(bz[f[sx].father]==false)
	{
		printf("%d\n",nx);
		return sx;
	}
	return dfs2(f[sx].father,nx+1);
}
int main()
{
	freopen("queue2.in","r",stdin);
	scanf("%d%d",&n,&t);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		d[2*i-1].to=y;d[2*i-1].next=last[x];last[x]=2*i-1;
		d[2*i].to=x;d[2*i].next=last[y];last[y]=2*i;
	}
	dfs(1);
	for(int i=1;i<=duitou;i++)
	{
		b[dui[i]]=i;
//		printf("%d ",dui[i]);
	}
	duitou=0;tou1=0;wei1=0;
	for(int i=1;i<=t;i++)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
//			if(i==39)
//			{
//				for(int j=1;j<=n;j++)
//				{
//					if(dui[j]==1||dui[j]==3||dui[j]==14)printf("%d ",dui[j]);
//				}
//			}
			int x,an=0,xc;
			scanf("%d",&x);
			an=tou1-wei1;
			if(an!=0)
			{
				if(x>an)
				{
					x-=an;
					for(int j=wei1+1;j<=tou1;j++)
					{
						bz[shan[j]]=true;
					}
					wei1=tou1;
				}
				else
				{
					for(int j=wei1+1;j<=tou1;j++)
					{
						so[++sotou]=shan[j];
					}
					px(1,sotou);
					for(int j=1;j<=(sotou-x);j++)
					{
						shan[j]=so[j+x];
					}
					for(int j=1;j<=x;j++)
					{
						bz[so[j]]=true;
					}
					xc=so[x];
					wei1=0;tou1=sotou-x;
					sotou=0;x=0;
				}
			}
			for(int j=duitou+1;j<=duitou+x;j++)
			{
				bz[dui[j]]=true;xc=dui[j];
			}
			duitou+=x;
			printf("%d\n",xc);
		}
		else
		{
			int x;
			scanf("%d",&x);
			int nx=dfs2(x,0);
			shan[++tou1]=nx;
			bz[nx]=false;
		}
	}
	return 0;
}
