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
///////////////////// Solution Code /* 10462 - Is There A Second Way Left? */
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
	int ind,from,to;
	int cost;
	edge(int ind=0 ,int from=0, int to=0, int cost=0):ind(ind),from(from),to(to),cost(cost){}
	bool operator < (const edge & e )const{return cost>e.cost;}
};
int n;
edge e,me;
set<edge> orMST;
bool arr[220];
int cnt;
int get(queue<edge> qe,bool ori=0)
{
	UnionFind u(n);
	int cost=0;
	priority_queue<edge> q;
	while(!qe.empty())
	{
		q.push(qe.front());
		qe.pop();
	}
	while(!q.empty())
	{
		e = q.top(); q.pop();
		if(u.find_set(e.from) != u.find_set(e.to))
		{
			cost += e.cost;
			u.union_sets(e.from, e.to);
			if(ori)
			{
				arr[e.ind]=1;
				cnt++;
			}
		}
	}
	if(u.forests == 1)
		return cost;
	return -1;
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
	int t,tt=0;
	cin>>t;
	while(tt++<t)
	{
		memset(arr,0,sizeof arr);
		cnt=0;
		cout<<"Case #"<<tt<<" : ";
		int m;
		cin>>n>>m;
		int x,y,c;
		queue<edge> all;
		forr(i,m)
		{
			cin>>x>>y>>c;
			x--,y--;
			all.push(edge(i,x,y,c));
		}
		vector<int> sols(0);
		sols.push_back(get(all,1));
		if(sols[0]==-1)
		{
			cout<<"No way\n";
			continue;
		}
		forr(i,m)
		{
			me=all.front();
			all.pop();
			if(arr[me.ind])
			{
				c = get(all);
				if(c!=-1)
					sols.push_back(c);
				
			}
			all.push(me);

		}
		sort(sols.begin(),sols.end());
		if(sols.size()<=1)
		{
			cout<<"No second way\n";
		}
		else 
		{
			cout<<sols[1]<<"\n";
		}

	}
	return 0;
}