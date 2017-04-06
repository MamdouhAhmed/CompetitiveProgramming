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
struct UnionFind{
	vector<int> rank, parent;
	int forests;
	UnionFind(int n)
	{
		rank = vector<int>(n);
		parent = vector<int> (n);
		forests = n;
		forr(i,n) parent[i]=i,rank[i]=1;
	}
	int find_set(int x)
	{
		if(parent[x] == x)
			return x;
		return parent[x]= find_set(parent[x]);
	}
	void link(int x, int y)
	{
		if(rank[x]>rank[y]) swap(x,y);
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
	bool union_sets(int x, int y)
	{
		x = find_set(x), y = find_set(y);
		if(x != y)
		{
			link(x,y);
			forests -- ;
		}
		return x!=y;
	}
};
struct  edge
{
	int from,to;ll cost;
	edge(int from=0, int to=0, ll cost=0): from(from), to(to), cost(cost){}
	bool operator < (const edge & e)const {return cost>e.cost;}
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
	int n,m;
	while(cin>>n>>m)
	{
		UnionFind u(n);
		char x,y;
		int ans=1;
		map<char, int> fih;
		int curr=0;
		queue<edge> es;
		forr(i,m)
		{
			cin>>x>>y;
			if(fih.find(x)== fih.end())
				fih[x]=curr++;
			if(fih.find(y)== fih.end())
				fih[y]=curr++;
			es.push(edge(fih[x],fih[y],1));
		}
		queue<edge> neww;
		while(!es.empty())
		{
			edge e= es.front(); es.pop();
			if(u.find_set(e.from)!= u.find_set(e.to))
				u.union_sets(e.from,e.to);
			else
				ans++;
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}