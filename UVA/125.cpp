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
	int n,cnt=0;
	while(cin>>n)
	{
		cout<<"matrix for city "<<cnt++<<"\n";
		int x[n],y[n];
		int maxx=0;
		forr(i,n)
		{
			cin>>x[i]>>y[i];
			maxx= max(maxx, max(x[i],y[i]));
		}
		if(!maxx)continue;
		maxx++;
		ll adj [maxx][maxx];
		forr(i,maxx) forr(j,maxx) adj[i][j]= (0);
		forr(i,n)
			adj[x[i]][y[i]]=1;
		forr(k,maxx)forr(i,maxx)forr(j,maxx) adj[i][j]+=adj[i][k]*adj[k][j];
		forr(k,maxx)if(adj[k][k])forr(i,maxx)forr(j,maxx) if(adj[i][k] && adj [k][j])adj[i][j]=-1LL;
		forr(i,maxx)forr(j,maxx) cout<<adj[i][j]<<((j<maxx-1)?" ":"\n");

	}
	return 0;
}