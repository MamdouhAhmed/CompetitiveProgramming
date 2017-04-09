#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define oo (int)1e9
#define OO (ll)1e18
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define dist(x,y,xx,yy) sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))
///////////////////// Solution Code
struct UnionFind{
	unordered_map<int,int> rank, parent;
	int forests;
	UnionFind()
	{
	}
	int find_set(int x)
	{
		if(parent[x] == 0)
		{
			parent[x]=x;rank[x]=1;forests++;
			return x;
		}
		if(parent[x]==x)return x;
		return parent[x]= find_set(parent[x]);
	}
	void link(int x, int y)
	{
		if(rank[x]>rank[y]) swap(x,y);
		parent[x] = y;
		rank[y]+=rank[x];
	}
	void union_sets(int x, int y)
	{
		x = find_set(x), y = find_set(y);
		if(x != y)
		{
			link(x,y);
			forests -- ;
		}
	}
};
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
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		string s,ss;
		int k=1,x,y;
		unordered_map<string , int > ma;
		UnionFind u;
		forr(i, n){
			cin>>s>>ss;
			if(!ma[s])
				ma[s]=k++;
			if(!ma[ss])
				ma[ss]=k++;
			x=ma[s],y=ma[ss];
			if(u.find_set(x) != u.find_set(y))
					u.union_sets(x,y);
			cout<<max(u.rank[u.find_set(x)],u.rank[u.find_set(y)])<<"\n";
		}
	}
	return 0;
}