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
#define dist(x,y,xx,yy) (x-xx)*(x-xx)+(y-yy)*(y-yy)
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
	int n;
	while(cin>>n)
	{
		ll x,y,xx,yy;
		cin>>x>>y>>xx>>yy;
		ll xrr[n], yrr[n];
		map<ll, vector<ll> >mp1;
		vector<ll> mpp(n);  
		forr(i, n)
		{
			cin>>xrr[i]>>yrr[i];
			mp1[dist(xrr[i],yrr[i],x,y)].pb(i);
			mpp[i]= dist(xrr[i],yrr[i],xx,yy);
		}
		vector<pair<ll, vector<ll > > > vve;
		for(pair<ll, vector<ll > > p : mp1 )
		{
			vve . pb(p);
		}
		vve.pb({0,{}});
		ll minn = 1e18, curr;
		sort(vve.begin() , vve.end());
		forr(i, (int)vve.size())
		{
			curr = 0;
			for(int j=i+1; j < (int)vve.size();j++ )
			{
				forr(k,(int) vve[j].se.size())
				{
					curr = max(curr,mpp[vve[j].se[k]]);
				}
			}
			minn = min(minn, curr + vve[i].fr);
		}
		cout<<minn<<"\n";
		
	}
	return 0;
}