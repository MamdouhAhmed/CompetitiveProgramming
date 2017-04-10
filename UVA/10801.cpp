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
struct edge{
	II from,to;
	ll cost;
	edge(II from={0,0}, II to={0,0}, ll cost=0):from(from),to(to),cost(cost){}
	bool operator < (const edge & e )const{return cost>e.cost;}
	friend ostream& operator<<(ostream& os, const edge& e)  
	{  
    	os <<"[{"<<e.from.first<<","<<e.from.second<<"},{"<<e.to.first<<","<<e.to.second<<"},"<<e.cost<<"]";  
    	return os;  
	}  
	
};
ostream& operator<<(ostream& os, const II & e)  
	{  
    	os <<"{"<<e.first<<","<<e.second<<"}";  
    	return os;  
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
	int n,K;
	while(cin>>n>>K)
	{
		int arrt[n],v;
		forr(i,n) cin>>arrt[i];
		vector<int> arr[n],feg[100];
		map<II,vector<edge> > adj;
		string s;
		cin.ignore();
		forr(i,n)
		{
			getline(cin,s);
			stringstream ss(s);
			while(ss>>v)
			{
				arr[i].pb(v);
				feg[v].pb(i);
			}
		}
		forr(i,n)
		{
			forr(j,arr[i].size()-1)
			{
				adj[{i,arr[i][j]}].push_back(edge({i,arr[i][j]},{i,arr[i][j+1]},(arr[i][j+1]-arr[i][j])*arrt[i]));
				adj[{i,arr[i][j+1]}].push_back(edge({i,arr[i][j+1]},{i,arr[i][j]},(arr[i][j+1]-arr[i][j])*arrt[i]));

			}
		}
		forr(i,100)
		{
			forr(j,feg[i].size())
			forr(k,feg[i].size())
			{
				if(j!=k)
				{
					adj[{feg[i][j],i}].push_back(edge({feg[i][j],i},{feg[i][k],i},60));
				}
			}
		}
		queue<edge> q;
		int coss=OO;
		forr(i,n)
		{
			if(adj.find({i,0})!= adj.end())
			{
				q.push(edge({0,0},{i,0}, 0));
				vector<vector<int> > cost(5,vector<int>(100,OO));
				cost[i][0]=0;
				while(!q.empty())
				{
					edge e = q.front();
					q.pop();
					forr(j , adj[e.to].size())
					{
						edge temp = adj[e.to][j];
						if(cost[temp.to.fr][temp.to.se] > cost[temp.from.fr][temp.from.se]+temp.cost)
						{
							cost[temp.to.fr][temp.to.se] = temp.cost = cost[temp.from.fr][temp.from.se]+temp.cost;
							q.push(temp);
						}
					}
				}
				forr(k,n)
				{
					coss = min(coss, cost[k][K]);
				}
			}
		}
		if(coss != OO)cout<<coss<<"\n";
		else cout<<"IMPOSSIBLE\n";

	}
	return 0;
}