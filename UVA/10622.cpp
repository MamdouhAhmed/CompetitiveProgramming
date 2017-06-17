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
	unordered_map<ll, int> ha;
	for(int i=2;i<47100;i++)
	{
		ll r=i;
		int cnt=0;
		while(r<= (1LL<<32))
		{
			ha[r]=max(ha[r], cnt++);
			r*=i;
		}

	}
	for(int i=2;i<47100;i++)
	{
		ll r=-i;
		int cnt=0;
		while(r>= -(1LL<<32))
		{
			ha[r]=max(ha[r], cnt++);
			r*=-i;
		}
	}
	ll n;
	while(cin>>n && n)
	{
		cout<<ha[n]+1<<"\n";
	}
	return 0;
}