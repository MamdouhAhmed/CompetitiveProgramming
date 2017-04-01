#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define oo (int)1e9
#define fr first
#define se second
///////////////////// Solution Code
struct edge{
	pair<int, int> from, to ;
	int cost;
	edge(pair<int, int> from, pair<int, int> to, int cost): from(from), to(to), cost(cost){}
	bool operator < (const edge & e) const{
		return cost > e.cost;
	}
	friend ostream& operator<<(ostream& os, const edge& e)  
	{  
    	os <<"[{"<<e.from.first<<","<<e.from.second<<"},{"<<e.to.first<<","<<e.to.second<<"},"<<e.cost<<"]";  
    	return os;  
	}  
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
	int h,w;
	while(cin>>w>>h&&h&&w)
	{
		vector<string> vs(h);
		vector<edge> adjlist[h][w];
		forr(i,h)
			cin>>vs[i];

		int si,sj,di,dj;
		forr(i,h)
		{
			forr(j,w)
			{
				if(vs[i][j]=='S')
					si=i,sj=j;
				if(vs[i][j]=='D')
					di=i,dj=j;
				if(i<h-1)
				{
					if(vs[i][j]!= 'X'&& vs[i+1][j]!= 'X')
					{
						adjlist[i][j].push_back(edge({i,j},{i+1,j}, ((isdigit(vs[i+1][j]))?vs[i+1][j]-'0':0)));
						//adjlist[i+1][j].push_back(edge({i+1,j},{i,j}, ((isdigit(vs[i][j]))?vs[i][j]-'0':0)));
					}
				}
				if(i)
				{
					if(vs[i][j]!= 'X'&& vs[i-1][j]!= 'X')
					{
						adjlist[i][j].push_back(edge({i,j},{i-1,j}, ((isdigit(vs[i-1][j]))?vs[i-1][j]-'0':0)));
						//adjlist[i-1][j].push_back(edge({i-1,j},{i,j}, ((isdigit(vs[i][j]))?vs[i][j]-'0':0)));
					}
				}
				if(j<w-1)
				{
					if(vs[i][j]!= 'X'&& vs[i][j+1]!= 'X')
					{
						adjlist[i][j].push_back(edge({i,j},{i,j+1}, ((isdigit(vs[i][j+1]))?vs[i][j+1]-'0':0)));
						//adjlist[i][j+1].push_back(edge({i,j+1},{i,j}, ((isdigit(vs[i][j]))?vs[i][j]-'0':0)));
					}
				}
				if(j)
				{
					if(vs[i][j]!= 'X'&& vs[i][j-1]!= 'X')
					{
						adjlist[i][j].push_back(edge({i,j},{i,j-1}, ((isdigit(vs[i][j-1]))?vs[i][j-1]-'0':0)));
						//adjlist[i][j-1].push_back(edge({i,j-1},{i,j}, ((isdigit(vs[i][j]))?vs[i][j]-'0':0)));
					}
				}
			}
		}
		vector<vector<int> > dist(h, vector<int> (w,oo));
		vector<vector<pair<int,int> > > prev(h, vector<pair<int,int> > (w,make_pair(-1,-1)));
		dist[si][sj]=0;
		priority_queue<edge> qq;
		pair<int,int> srcp={si,sj},dstp={di,dj};
		qq.push(edge({-1,-1},srcp,0));
		while(!qq.empty())
		{
			edge now = qq.top(); qq.pop();
			if(now.cost > dist[now.to.first][now.to.second]) continue;
			prev[now.to.first][now.to.second] = now.from;
			forv(i,adjlist[now.to.first][now.to.second])
			{
				edge hard = adjlist[now.to.first][now.to.second][i];
				if(dist[hard.to.first][hard.to.second]>dist[hard.from.fr][hard.from.se]+hard.cost)
				{
					hard.cost = dist[hard.to.fr][hard.to.se] = dist[hard.from.fr][hard.from.se]+hard.cost;
					qq.push(hard);
				}
			}
		}
		cout<<dist[di][dj]<<"\n";

	}
	return 0;
}