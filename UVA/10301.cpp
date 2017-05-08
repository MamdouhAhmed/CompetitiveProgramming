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
bool get(double x,double y,double r,double xx,double yy,double R)
{
	return ((dist(x,y,xx,yy) > (r+R) )||(R >= (dist(x,y,xx,yy) + r) )||(r >= (dist(x,y,xx,yy) + R) ));
}
int adj[120][120];
bool vis[120];
int n;
int dfs(int i)
{
	vis[i]=1;
	int rr= 0;
	for(int k=0;k<n;k++)
	{
		if(adj[i][k] && !vis[k])
		{
			vis[k]=0;
			rr+=dfs(k);
		}
	}
	return 1+rr;

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
	while(cin>>n &&(n!= -1))
	{
		memset(adj, 0, sizeof adj);
		memset(vis, 0, sizeof vis);
		double xx[n],yy[n],rr[n];
		forr(i, n)
			cin>>xx[i]>>yy[i]>>rr[i];
		forr(i,n)
			forr(j,n)
				if(!get(xx[i],yy[i],rr[i],xx[j],yy[j],rr[j]))
					adj [i][j] =  1;
		int maxx=0;
		forr(i,n)
		{
			if(!vis[i])
			{
				maxx = max(maxx, dfs(i));
			}
		}
		cout<<"The largest component contains "<<maxx<<" ring"<<((maxx!=1)?"s.\n":".\n");
	}
	return 0;
}