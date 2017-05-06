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
		int m, k;
		cin>>m>>k;
		pair<ll,ll> arr[n];
		forr(i,n)
			cin>>arr[i].fr>>arr[i].se;
		pair<pair<ll,ll>, int> reg[m];
		forr(i,m)
			cin>>reg[i].se>>reg[i].fr.fr>>reg[i].fr.se;
		bitset<1010> bbb[n],hhh;
		forr(i,m)
		{
			forr(j,n)
			{
				if(sqrt(dist(reg[i].fr.fr, reg[i].fr.se, arr[j].fr, arr[j].se)) <= reg[i].se)
				{
					bbb[j].set(i);
				}
			}
		}
		int x,y;
		forr(i, k)
		{
			cin>>x>>y;
			x--;y--;
			hhh = bbb[x];
			hhh &= bbb[y];
			//cout<<bbb[x]<<" "<<bbb[y]<<"\n";
			cout<<((bbb[x]|bbb[y]).count() - hhh.count())<<"\n";
		}
	}
	return 0;
}