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
	int X,Y;
	double R;
	while(cin>>X>>Y>>R)
	{
		if(R<0.0)break;
		int n;
		cin>>n;
		vector<double> dd;
		double ang ;
		int xvl, yvl;
		forr(i,n)
		{
			cin>>xvl>>yvl;
			xvl-=X;
			yvl-=Y;
			if(dist(xvl, yvl, 0, 0)<=R)
			{
				ang = atan2(yvl,xvl)*180.0/PI;
				if(ang < 0.0)ang = 360 + ang;
				dd.pb(ang);
				dd.pb((ang)+360.0);
			}
		}
		sort(dd.begin(),dd.end());
		int maxx = 0, kk;
		forr(i,(int)dd.size())
		{
			kk = distance(dd.begin(), upper_bound(dd.begin(),dd.end(),dd[i]+180))-i;
			maxx = max(maxx, kk);
		}
		cout<<maxx<<"\n";

	}
	return 0;
}