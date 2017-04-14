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
int path[110][110];
string s;
vector<string> vec;
ll adj[110][110];
unordered_map<string, int> cities;
unordered_map<int, string> codes;
string routname[110][110];
int routlen[110][110];
int n=0;
void print_path(int i, int j)
{
	if(path[i][j]==-1)
	{
		cout<<left<<setw(21)<<codes[i]<<setw(21)<<codes[j]<<setw(11)<<routname[i][j]<<right<<setw(5)<<routlen[i][j];
		cout<<"\n";
		return ;
	}
	print_path(i,path[i][j]);
	print_path(path[i][j],j);

}
vector<string> split(string s)
{
	vector<string> ss;
	string t;
	forr(i,s.length())
	{
		if(s[i]==',')
		{
			ss.pb(t);
			t="";
		}
		else 
		{
			t+=s[i];
		}
	}
	ss.pb(t);
	return ss;
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
	
	getline(cin,s);
	
	forr(i,110)forr(j,110) adj[i][j]=(OO*(i!=j));
	
	while(s!="")
	{
		vec= split(s);
		if(cities.find(vec[0])==cities.end())
		{
			cities[vec[0]]=n;
			codes[n]=vec[0];
			n++;
		}
		if(cities.find(vec[1])==cities.end())
		{
			cities[vec[1]]=n;
			codes[n]=vec[1];
			n++;
		}
		if(adj[cities[vec[0]]][cities[vec[1]]]>stoi(vec[3]))
		{
			adj[cities[vec[0]]][cities[vec[1]]]= routlen[cities[vec[0]]][cities[vec[1]]] =stoi(vec[3]);
			routname[cities[vec[0]]][cities[vec[1]]] = vec[2];
		}
		if(adj[cities[vec[1]]][cities[vec[0]]]>stoi(vec[3]))
		{
			adj[cities[vec[1]]][cities[vec[0]]]= routlen[cities[vec[1]]][cities[vec[0]]] =stoi(vec[3]);
			routname[cities[vec[1]]][cities[vec[0]]] = vec[2];
		}
		getline(cin,s);
	}
	
	forr(i,n)forr(j,n)if(adj[i][j]<OO)path[i][j]=-1;else path[i][j]=n+1;
	forr(k,n)forr(i,n)forr(j,n)
	{
		if(adj[i][k]<OO&&adj[k][j])
		{
			if(adj[i][j]> adj[i][k]+adj[k][j])
			{
				adj[i][j]=adj[i][k]+adj[k][j];
				path[i][j]=k;
			}
		}
	}
	getline(cin,s);
	while(s!="")
	{
		vec= split(s);
		cout<<"\n\n";
		cout<<left<<setw(21)<<"From"<<setw(21)<<"To"<<setw(11)<<"Route"<<setw(5)<<"Miles";
		cout<<"\n-------------------- -------------------- ---------- -----\n";
		print_path(cities[vec[0]],cities[vec[1]]);
		cout<<(string(53,' '))<<"-----\n"<<(string(42,' '))<<left<<setw(11)<<"Total"<<right<<setw(5)<<adj[cities[vec[0]]][cities[vec[1]]]<<"\n";
		getline(cin,s);
	}
	return 0;
}