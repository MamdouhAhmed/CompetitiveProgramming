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
	int from,to;double cost;
	edge(int from=0, int to=0, double cost=0): from(from), to(to), cost(cost){}
	bool operator < (const edge & e)const {return cost>e.cost;}
};
double adj[750][750];
II arr[750];
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
		int n, m, x, y;
		cin>>n;
		UnionFind u_f(n);
		
		forr(i,n)
			cin>>arr[i].fr>>arr[i].se;
		
		forr(i,n)
			forr(j,n)
				adj[i][j]= dist(arr[i].fr,arr[i].se,arr[j].fr,arr[j].se);
		double cost = 0.0;
		cin>>m;
		bool good_so_far=1;
		forr(i,m)
		{
			cin>>x>>y;
			x--,y--;
			cost += adj[x][y];
			good_so_far &= u_f.union_sets(x,y);

		}
		/*if (!good_so_far)
			cout<<"!good_so_far";
		else cout<<"YES!";*/
		priority_queue<edge> q;
		edge e(0,0,0);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				e.from = i, e.to = j, e.cost= adj[i][j];
				cost += e.cost; 
				q.push(e);
			}
		//cout<<"got all input\n"<<endl;
		int added = 0;
		queue<II> add;
		edge now;
		while(!q.empty())
		{
			now = q.top(); q.pop();
			if(u_f.find_set(now.from) != u_f.find_set(now.to))
			{
				//cout<<now.from<<" "<<now.to<<"<\n";
				added++;
				add.push({now.from,now.to});
				cost+=now.cost;
				good_so_far &= u_f.union_sets(now.from,now.to);
			}
		}
		//cout<<cost<<"\n";
		if(added == 0)
		{
			cout<<"No new highways need\n";
		}
		else 
		{
			while(!add.empty())
			{
					cout<<add.front().fr +1<<" "<<add.front().se +1<<"\n";
					add.pop();
			}
		}
		if(N)
			cout<<"\n";
	}
	return 0;
}