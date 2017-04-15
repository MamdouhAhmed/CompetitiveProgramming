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
	int n,m;
	while((cin>>n>>m)&&(n||m))
	{
		int x[n],y[n];
		forr(i,n)
			cin>>x[i]>>y[i];
		int u,v;
		double adj[n][n];
		forr(i,n)forr(j,n) adj[i][j]=(OO*(i!=j));
		forr(i,m)
		{
			cin>>u>>v;
			u--,v--;
			adj[u][v]=adj[v][u]=dist(x[u],y[u],x[v],y[v]);
		}
		double newadj[n][n];
		double lel[n][n];
		forr(i,n)forr(j,n) newadj[i][j]=adj[i][j];
		forr(k,n)forr(i,n)forr(j,n) if(adj[i][k]<OO && adj[k][j]<OO) adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
		int maxi,maxj;
		double maxc=0;
		double c=0;
		forr(i,n)forr(j,n)
		{
			if(newadj[i][j]==OO)
			{
				lel[i][j]=lel[j][i]=dist(x[i],y[i],x[j],y[j]);
				c=0;
				forr(k,n)forr(l,n) c+= adj[k][l]-min(adj[k][l], min(adj[k][i]+lel[i][j]+adj[j][l],adj[k][j]+lel[j][i]+adj[i][l]));
				if((c-maxc)>1e-9)
				{
					maxi=i;
					maxj=j;
					maxc=c;
				}
			}
		}
		if(maxc<=1.0) cout<<"No road required\n";
		else cout<<maxi+1<<" "<<maxj+1<<"\n";
	}
	return 0;
}