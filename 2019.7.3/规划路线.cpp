#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100001],b[100001],n;
struct nod{int a,b,c;}c[100001];
int f[100001],tou=0;
bool cmp(nod x,nod y){return x.c<y.c;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]].a=i;
		c[a[i]].c=i;
		a[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		c[b[i]].b=i;
		b[i]=c[b[i]].c;
	}
	sort(c+1,c+1+n,cmp);
	f[++tou]=c[1].b;
	for(int i=2;i<=n;i++)
	{
		if(c[i].b>f[tou])
		{
			int l=1,r=tou;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(f[mid]>c[i].b)l=mid+1;
				else r=mid-1;
			}
			if(f[l]<c[i].b)f[l]=c[i].b;
			else f[l+1]=c[i].b;
		}
		else
		{
			f[++tou]=c[i].b;
		}
	}
	printf("%d",tou);
	return 0;
}
