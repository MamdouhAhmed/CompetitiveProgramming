#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define OO (ll)1e18
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define dist(x,y,xx,yy) sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))
ull gcd (ull a,ull b){ull c;while(a!=0){c=a;a=b%a;b=c;}return b;}
ll sum(ll x){return (x*(x+1))/2;}
///////////////////// Solution Code

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
		int x;
		cin>>x;
		string res(300,'9');
		queue<pair <string , int> > q;
		q.push({"6", 6%x});
		q.push({"8", 8%x});
		while(!q.empty())
		{
			pair<string, int > p = q.front();
			//cout<<p.se<<"\n";
			q.pop();
			if(p.se == 0) {
				res = p.fr;
				break;
			}
			if(p.fr[p.fr.size() - 1] == '6')
			{
				auto pp = p ;
				pp.fr += '6';
				if(pp.fr.size() > 200) continue;
				pp.se = ((pp.se*10) + 6)%x;
				q.push(pp);
			}
			else 
			{
				auto pp = p ;
				pp.fr += '6';
				if(pp.fr.size() > 200) continue;
				pp.se = ((pp.se*10) + 6)%x;
				q.push(pp);
				pp = p ;
				pp.fr += '8';
				if(pp.fr.size() > 200) continue;
				pp.se = ((pp.se*10) + 8)%x;
				q.push(pp);
			}
 
 
		}
		if(res == (string(300,'9')))
			cout<<"-1"<<"\n";
		else cout<<res<<"\n";
 
	}
	return 0;
}