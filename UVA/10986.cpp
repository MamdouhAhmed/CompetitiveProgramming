#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define oo 1e18
#define fr first
#define se second
#define pb push_back
///////////////////// Solution Code
struct edge {
	int from, to ;
	ll c;
	edge(int from=-1, int to=-1, ll c=-1):from(from),to(to),c(c){}
	bool operator < (const edge & e) const {return c>e.c;}
};
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
	int N,n,m,s,t;
	while(cin>>N)
	{
		int k=0;
		while(k++<N)
		{
			cout<<"Case #"<<k<<": ";
			cin>>n>>m>>s>>t;
			vector<edge> arr[n];
			edge mye(0,0,0);
			forr(i,m)
			{
				cin>>mye.from>>mye.to>>mye.c;
				arr[mye.from].push_back(mye);
				swap(mye.from,mye.to);
				arr[mye.from].push_back(mye);
			}
			vector<ll> dist(n,oo), prev(n,-1);
			dist[s]=0;
			priority_queue<edge> q;
			q.push(edge(-1,s,0));
			while(!q.empty())
			{
				edge here = q.top(); q.pop();
				if(dist[here.to] < here.c) continue;
				forv(i,arr[here.to])
				{
					edge now=arr[here.to][i];
					if(dist[now.to]>dist[now.from]+now.c)
					{
						dist[now.to]= now.c= dist[now.from]+now.c;
						q.push(now);
					}
				}
			}
			if(dist[t]!= oo)
			{
				cout<<dist[t]<<"\n";
			}
			else 
			{
				cout<<"unreachable\n";
			}
		}
	}


	return 0;
}