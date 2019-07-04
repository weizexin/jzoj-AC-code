#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e9+7;
long long fastpow(long long int a,long long int n)
{
	long long int an=1;
	while(n!=0)
	{
		if(n%2==1)
		{
			an*=a;an%=N;
		}
		n/=2;a*=a;a%=N;
	}
	return an;
}
int main()
{
	long long int n,m,ans;
	scanf("%lld%lld",&n,&m);
	ans=24*(fastpow(2,n-2)+fastpow(2,m-2)-1);
	ans%=N;
	printf("%lld",ans);
	return 0;
}
