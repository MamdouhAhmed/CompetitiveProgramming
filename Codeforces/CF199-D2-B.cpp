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
bool get(int x,int y,int r,int xx,int yy,int R,int RR)
{
	return (
		(dist(x,y,xx,yy) >= (r+R) && dist(x,y,xx,yy) >= (r+RR) )
		||
		(R >= (dist(x,y,xx,yy) + r) && RR >= (dist(x,y,xx,yy) + r))
		||
		(r >= (dist(x,y,xx,yy) + R) && r >= (dist(x,y,xx,yy) + RR))
		);
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
	int x,y,r,R,xx,yy,rr,RR;
	while(cin>>x>>y>>r>>R>>xx>>yy>>rr>>RR)
	{
	cout<<	get(x,y,r,xx,yy,rr,RR) + 
			get(x,y,R,xx,yy,rr,RR) + 
			get(xx,yy,rr,x,y,r,R ) + 
			get(xx,yy,RR,x,y,r,R )<<"\n";
	}
	return 0;
}