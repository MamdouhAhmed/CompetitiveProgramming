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
	int p,q;
	while(cin>>p>>q)
	{
		int pp[6000],po=0;
		for(int i=1;i<=p;i++)
			if(p%i==0)
				pp[po++]=i;
		int qq[6000],qo=0;
		for(int i=1;i<=q;i++)
			if(q%i==0)
				qq[qo++]=i;
		for(int i=0;i<po;i++)
			for(int j=0;j<qo;j++)
				cout<<pp[i]<<" "<<qq[j]<<"\n";

	}
	return 0;
}
/*
I:
24 2
O:
1 1
1 2
2 1
2 2
3 1
3 2
4 1
4 2
6 1
6 2
8 1
8 2
12 1
12 2
24 1
24 2
*/