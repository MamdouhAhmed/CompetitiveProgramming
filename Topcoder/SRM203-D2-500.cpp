#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define all(v) v.begin(), v.end()
#define OO (ll)1e18
#define PI 3.14159265358979323846264
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define EPS 1e-9
#define dist(x,y,xx,yy) sqrt(((x-xx)*(x-xx))+((y-yy)*(y-yy)))
ull gcd (ull a,ull b){ull c;while(a!=0){c=a;a=b%a;b=c;}return b;}

class MatchMaking {
public:
	int getAgrement(string a, string b)
	{
		int ag = 0 ;
		for(int i=0;i<a.size();i++)
		{
			ag+=(a[i] == b[i]);
		}
		return ag;
	}
	string makeMatch(vector <string> namesWomen, vector <string> answersWomen, vector <string> namesMen, 
																vector <string> answersMen, string queryWoman) {
		vector<pair<string, string> > womenPairs(namesWomen.size()), menPairs(namesWomen.size());
		for(int i=0;i<namesWomen.size();i++)
		{
			womenPairs[i]= {namesWomen[i], answersWomen[i]};
			menPairs [i] = {namesMen[i], answersMen[i]};
		}
		map<string, string> sols;
		sort(all(menPairs));
		sort(all(womenPairs));
		for( int tt = 0, kkll = namesWomen.size();tt<kkll;tt++)
		{
			int maxx = 0, maxi,ag; 
			for(int i = 0;i<menPairs.size();i++)
			{
				ag = getAgrement(womenPairs[tt].se, menPairs[i].se);
				if(ag > maxx)
				{
					maxx= ag;
					maxi = i;
				}
			}
			sols[womenPairs[tt].fr] = menPairs[maxi].fr;
			menPairs.erase(menPairs.begin()+maxi);
		}
		return sols[queryWoman];
	}
};