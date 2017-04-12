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
int n;
ll adj[110][110];
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
	
	while(cin>>n&&n)
	{
		
		forr(i,n)forr(j,n) adj[i][j]=((i==j)?0:OO);
		ll vv,x,c;
		forr(i,n)
		{
			cin>>vv;
			forr(j,vv)
			{
				cin>>x>>c;
				x--;
				adj[i][x]=c;
			}
		}
		//forr(i,n){forr(j,n)cout<<adj[i][j]<<" ";cout<<"\n";}
		forr(k,n) forr(i,n) forr(j,n)
		if(adj[i][k]<OO && adj[k][j]<OO)
			adj[i][j]= min(adj[i][j],adj[i][k]+adj[k][j]);
		II minn= {OO,OO};
		forr(i,n)
		{
			sort(adj[i],adj[i]+n);
			if(adj[i][n-1]<OO)
			{
				minn = min(minn, {adj[i][n-1],i+1});
			}
		}
		//forr(i,n){forr(j,n)cout<<adj[i][j]<<" ";cout<<"\n";}
		if(minn!=make_pair(OO,OO)) cout<<minn.se<<" "<<minn.fr<<"\n";
		else cout<<"disjoint\n";
	}
	return 0;
}