#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define OO (ll)1e18
#define PI 3.14159265358979323846264
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define dist(x,y,xx,yy) sqrt(((x-xx)*(x-xx))+((y-yy)*(y-yy)))
ull gcd (ull a,ull b){ull c;while(a!=0){c=a;a=b%a;b=c;}return b;}
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
	int ffp[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};//First Few Primes
	int ffm[]={2, 3, 5, 7, 13, 17, 19, 31};// First Few Merseen
	unordered_map<int, int> dat;
	forr(i, 11)
		dat [ffp[i]]++;
	forr(i, 8)
		dat [ffm[i]]++;
	int n;
	while(cin>>n && n)
	{
		if(dat[n]==2)
			cout<<"Perfect: "<<((1LL<<(n-1))*((1LL<<n)-1))<<"!\n";
		else if(dat[n]== 1)
			cout<<"Given number is prime. But, NO perfect number is available.\n";
		else 
			cout<<"Given number is NOT prime! NO perfect number is available.\n";
	}
	return 0;
}
/* IO
In:
2
3
6
31
0
Out:
Perfect: 6!
Perfect: 28!
Given number is NOT prime! NO perfect number is available.
Perfect: 2305843008139952128!
*/