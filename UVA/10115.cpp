#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define OO (ll)1e18
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define dist(x,y,xx,yy) sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))
ull gcd (ull a,ull b){ull c;while(a!=0){c=a;a=b%a;b=c;}return b;}
///////////////////// Solution Code
ll sum(ll x)
{
	return (x*(x+1))/2;
}

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
	int r;
	while(cin>>r &&r )
	{
		cin.ignore();
		string one[12],two[12];
		forr(i,r)
		{
			getline(cin,one[i]);
			getline(cin,two[i]);
		}
		string my;
		getline(cin,my);
		int p;
		forr(i,r)
		{
			while((p = my.find(one[i])) != -1)

			{
				my.replace(p,one[i].length(),two[i]);
			}
		}
		cout<<my<<"\n";
	}
	return 0;
}