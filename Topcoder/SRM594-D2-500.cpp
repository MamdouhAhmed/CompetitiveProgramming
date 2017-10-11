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




class AstronomicalRecordsEasy {
public:
	int getUnionSize(vector<int> a, vector<int> b)
	{
		std::vector<int> v(a.size()+b.size());
		auto it = set_union(all(a), all(b), v.begin());
		return it-v.begin();
	}
	int minimalPlanets(vector <int> A, vector <int> B) {
		int gcdd = A[0];
		for(int i = 1; i< A.size(); i++)
		{
			gcdd = __gcd(gcdd, A[i]);
		}
		for(int i = 0;i< A.size();i++)
		{
			A[i]= A[i]/gcdd;
		}
		gcdd = B[0];
		for(int i = 1; i< B.size(); i++)
		{
			gcdd = __gcd(gcdd,B[i]);
		}
		for(int i = 0;i< B.size();i++)
		{
			B[i]= B[i]/gcdd;
		}
		int sol = getUnionSize(A,B);
		vector<int> va[1010];
		for(int i = 1;i<= 1001;i++)
		{
			va[i-1] = A;
			for(int k = 0, o = va[i-1].size(); k<o ; k++)
			{
				va[i-1][k] = va[i-1][k] *i;
			}
		}

		vector<int> vb[1010];
		for(int i = 1;i<= 1001;i++)
		{
			vb[i-1] = B;
			for(int k = 0, o = vb[i-1].size(); k<o ; k++)
			{
				vb[i-1][k] = vb[i-1][k]*i;
			}
		}
		for(int i=0;i<1001;i++)
			for(int j=0;j<1001;j++)
			{
				sol = min(sol,getUnionSize(va[i],vb[j]));
			}
		return sol;
	}
};