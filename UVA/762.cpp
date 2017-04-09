#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define OO (int)1e9
#define oo (ll)1e18
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define dist(x,y,xx,yy) sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))
///////////////////// Solution Code
struct edge{
	int from,to;
	ll cost;
	edge(int from=0, int to=0, ll cost=0):from(from),to(to),cost(cost){}
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
	int n,rio=0;
	while(cin>>n)
	{
		if(rio++)cout<<"\n";
		map<string, int> m;
		map<int, string> ms;
		string s,ss;
		int k=0;
		unordered_map<int, vector<edge> > adj;
		forr(i, n)
		{
			cin>>s>>ss;
			if(m.find(s)== m.end())
			{
				m[s]=k;
				ms[k]=s;
				k++;
			}
		if(m.find(ss)== m.end())
			{
				m[ss]=k;
				ms[k]=ss;
				k++;
			}
			adj[m[s]].push_back(edge(m[s],m[ss],1));
			adj[m[ss]].push_back(edge(m[ss],m[s],1));
		}
		
		cin>>s>>ss;
		if(m.find(s)== m.end())
		{
			m[s]=k;
			ms[k]=s;
			k++;
		}
		if(m.find(ss)== m.end())
		{
			m[ss]=k;
			ms[k]=ss;
			k++;
		}
		vector<ll> cost(k,OO),prev(k,-1LL), nxt(k,-1LL);
		queue<edge> q;
		cost[m[s]]=0;
		q.push(edge(0,m[s],0));
		edge e;
		while(!q.empty())
		{
			
			e= q.front();q.pop();
			if(e.cost > cost[e.to]) continue;
			forr(i,(int)adj[e.to].size())
			{
				edge r = adj[e.to][i];
				if(cost[r.to]>=cost[r.from]+r.cost)
				{
					r.cost= cost[r.to] = cost[r.from]+r.cost;
					prev[r.to]=r.from;
					nxt[r.from]=r.to;
					q.push(r);
				}

			}
		}
		if(cost[m[ss]]==OO)
		{
			cout<<"No route\n";
			continue;
		}
		int f=m[ss],t;
		stack<edge> ee;
		forr(i,cost[m[ss]])
		{
			ee.push(edge(prev[f],f,0));
			f=prev[f];
		}
		while(!ee.empty())
		{
			e= ee.top();
			ee.pop();
			cout<<ms[e.from]<<" "<<ms[e.to]<<endl;
		}
	}
	return 0;
}