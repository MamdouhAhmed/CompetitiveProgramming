#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define oo (int)1e18
#define fr first
#define se second
#define pb push_back
///////////////////// Solution Code
struct edge{
	int from,to;
	ll cost;
	edge(int from, int to, ll cost):from(from),to(to),cost(cost){}
	bool operator < (const edge & e )const{return cost>e.cost;}
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
	int N;
	cin>>N;
	while(N--)
	{
		int n,m,s,d;
		cin>>n>>m>>s>>d;
		s--;
		d--;
		vector<ll> dist(n,oo);
		vector<int>  prev(n,-1);
		edge e(0,0,0);
		vector<edge> adj[n];
		forr(i,m)
		{
			cin>>e.from>>e.to>>e.cost;
			e.from--;
			e.to--;
			adj[e.from].pb(e);
			swap(e.from,e.to);
			adj[e.from].pb(e);
		}
		dist[s]= 0;
		priority_queue<edge> q;
		q.push(edge(0,s,0));
		while(!q.empty())
		{
			edge he = q.top(); q.pop();
			if(dist[he.to] < he.cost) continue;
			forv(i,adj[he.to])
			{
				edge me = adj[he.to][i];
				if(dist[me.to]> dist[me.from]+me.cost)
				{
					me.cost = dist[me.to] = dist[me.from]+me.cost;
					q.push(me);
				}
			}	
		}
		if(dist[d]==oo)
		{
			cout<<"NONE\n";
		}
		else 
		{
			cout<<dist[d]<<"\n";
		}
		
	}
	return 0;
}