#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define OO (ll)1e18
#define PI 3.14159265358979323846264
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define dist(x,y,xx,yy) sqrt(((x-xx)*(x-xx))+((y-yy)*(y-yy)))
ull gcd (ull a,ull b){ull c;while(a!=0){c=a;a=b%a;b=c;}return b;}
///////////////////// Solution Code
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	#ifdef _WIN64
	freopen("C:\\Users\\mamdouh\\Desktop\\a1.in","r",stdin);
	freopen("C:\\Users\\mamdouh\\Desktop\\A2.out","w",stdout);
	#elif __linux__
	freopen("/media/mamdouh/System/Users/Mamdouh/Desktop/a1.in","r",stdin);
	freopen("/media/mamdouh/System/Users/Mamdouh/Desktop/A2.out","w",stdout);
	#endif
	#endif
	int a,b;
	vector<bool> p(1000010,1);
	std::vector<int> primes;
	p[0]=p[1]=0;
	for(int i=2;i<1000010;i++)
	{
		if(p[i])
		{
			primes.pb(i);
			for(int j=i*2;j<1000010;j+=i)
				p[j]=0;
		}
	}
	int cnt=1;
	while(cin>>a>>b && (a||b))
	{
		cout<<cnt++<<". ";
		int X=0,D=0,r,rr;
		for(int i=0;i<primes.size();i++)
		{
			r=0,rr=0;
			while(a%primes[i] == 0)
				r++, a/=primes[i];
			while(b%primes[i] == 0)
				rr++,b/=primes[i];
			if(r||rr)
				X++;
			D+=abs(r-rr);
		}
		cout<<X<<":"<<D<<"\n";
	}
	return 0;
}