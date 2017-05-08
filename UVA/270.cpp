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
	int n;
	cin>>n;

	string stt;
	cin.ignore();
	getline(cin,stt);
	stt="*";
	while(n--)
	{
		vector<int> xrr, yrr;
		int x,y;
		while(getline(cin,stt) && stt!="")
		{
			stringstream ss(stt);
			ss>>x>>y;
			xrr.pb(x);
			yrr.pb(y);
		}
		int maxx=0;
		forr(i, xrr.size())
		{
			unordered_map<double, int> mmp;
			forr(j, xrr.size())
			{
				if(i==j) continue;
				x= xrr[j]-xrr[i];
				y= yrr[j]-yrr[i];
				double ang = atan2(y,x)*180.0/PI;
				if(ang <0) ang+=180;
				mmp[ang]++;
				maxx= max(maxx, mmp[ang]);
			}
		}
		cout<<maxx+1<<"\n";
		if(n) cout<<"\n";
	}
	return 0;
}