#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long int n,k[101],c[101],t,d[101],nk,nd=1,ans=0;
void px(long long int l,long long int r)
{
	long long int x=l,y=r,mid=c[(l+r)/2];
	while(x<=y)
	{
		while(c[x]<mid)x++;
		while(c[y]>mid)y--;
		if(x<=y)
		{
			int t=c[x];
			c[x]=c[y];
			c[y]=t;
			t=k[x];
			k[x]=k[y];
			k[y]=t;
			x++;y--;
		}
	}
	if(x<r)px(x,r);
	if(l<y)px(l,y);
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k[i],&c[i]);
	}
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld",&d[i]);
	}
	px(1,n);
	for(int i=1;i<=n;i++)
	{
		if(nk+k[i]<d[nd])
		{
			ans+=k[i]*c[i]*nd;
			nk+=k[i];
		}
		else if(nk+k[i]==d[nd])
		{
			ans+=k[i]*c[i]*nd;
			nk+=k[i];
			nd++;
		}
		else if(nd<=t)
		{
			ans+=(d[nd]-nk)*c[i]*nd;
			nd++;
			while(k[i]+nk>d[nd]&&nd<=t)
			{
				ans+=(d[nd]-d[nd-1])*c[i]*nd;
				nd++;
			}
			ans+=(nk+k[i]-d[nd-1])*c[i]*nd;
			nk+=k[i];
		}
		else
		{
			ans+=k[i]*c[i]*nd;
			nk+=k[i];
		}
	}
	printf("%lld",ans);
	return 0;
}
