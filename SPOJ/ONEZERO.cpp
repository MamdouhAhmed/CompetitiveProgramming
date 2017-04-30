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
ll sum(ll x){return (x*(x+1))/2;}
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
	int T;
	cin>>T;
	while(T--)
	{
		int x;
		cin>>x;
		queue<pair <string , int> > q;
		string res= "";
		q.push({"1", 1%x});
		while(!q.empty())
		{
			pair<string, int > p = q.front();
			q.pop();
			if(p.se == 0) {
				res = p.fr;
				break;
			}			
			pair<string, int > pp = p ;
			pp.fr += '0';
			pp.se = ((pp.se*10) + 0)%x;
			q.push(pp);
			pp = p ;
			pp.fr += '1';
			pp.se = ((pp.se*10) + 1)%x;
			q.push(pp);
		}
		cout<<res<<"\n";
	}
	return 0;
} 