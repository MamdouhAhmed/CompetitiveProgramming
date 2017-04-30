#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define OO (int)1e9
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define dist(x,y,xx,yy) sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))
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
	int N;
	cin>>N;
	while(N--)
	{
		int n;
		cin>>n;
		int x[n],y[n];
		double adj[100][100];
		forr(i,n)
			cin>>x[i]>>y[i];
		forr(i,n)forr(j,n) adj[i][j]= dist(x[i],y[i],x[j],y[j]);
		forr(k,n)forr(i,n)forr(j,n) adj[i][j]= min(adj[i][j], adj[i][k]+adj[k][j]);
		int maxx=0;
		forr(i,n)
		{
			int m=0;
			forr(j,n)
			{
				m+=adj[i][j];
				cout<<adj[i][j]<<" ";
			}
			cout<<"\n";
			//cout<<m<<" <\n";
			maxx = max(m,maxx);
		}
		cout<<maxx<<"\n";
	}
	return 0;
}