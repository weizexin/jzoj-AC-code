#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long int l1[2002],l2[2002],n1,n2,f[2002][2002];
int main()
{
	scanf("%lld%lld",&n1,&n2);
	for(int i=1;i<=n1;i++)
	{
		scanf("%lld",&l1[i]);
		l1[i]--;
	}
	for(int i=1;i<=n2;i++)
	{
		scanf("%lld",&l2[i]);
		l2[i]--;
	}
	memset(f,127,sizeof(f));
	f[n1][n2]=0;
	for(int i=n1-1;i>=0;i--)
	{
		for(int j=n2-1;j>=0;j--)
		{
			f[i][j]=min(f[i][j],min(f[i+1][j+1]+l1[i+1]*l2[j+1],min(f[i+1][j]+l1[i+1]*l2[j+1],f[i][j+1]+l1[i+1]*l2[j+1])));
		}
	}
	printf("%lld",f[0][0]);
	return 0;
}
