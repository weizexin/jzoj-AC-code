#include<vector>
#include<cstdio>
#define max(a,b) (a>b?a:b)
using namespace std;
int n,h,sum[100001];
double vng[100001],l,r;
vector<double> a[100001];
bool check(double nx)
{
	double an=0,mx,f;
	for(int i=1;i<=n;i++)
	{
		mx=-nx,f=0;
		for(int j=0;j<a[i].size();j++)
		{
			f+=a[i][j]-nx;
			mx=max(mx,f);
		}
		an+=mx;
	}
	return an>=0;
}
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=h;j++)
		{
			double t;
			scanf("%lf",&t);
			a[i].push_back(t);
			r=max(r,t);
		}
	}
	while(l+1e-6<r)
	{
		double mid=(l+r)/2.00;
		if(check(mid))l=mid;
		else r=mid;
	}
	if(check(l+0.0001))printf("%.4lf",(l+0.0001));
	else printf("%.4lf",l);
	return 0;
}
