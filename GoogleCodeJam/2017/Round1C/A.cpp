/******************************************************************
* Oh, Lord.                                                       *
* Oooh, You are so big... So absolutely huge.                     *
* Gosh, We're all really impressed down here, I can tell you.     *
* Forgive us, Oh Lord, for this our dreadful toadying... and bare-*
* faced flattery.                                                 *
* But you're so strong and, well just so... super.                *
* Fantastic.                                                      *
******************************************************************/
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
#define dist(x,y,xx,yy) sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))
ull gcd (ull a,ull b){ull c;while(a!=0){c=a;a=b%a;b=c;}return b;}
///////////////////// Solution Code
double dp [1010][1010];
pair<ll,ll > area[1010];
int n,k;
double get(int ind, int kk)
{
	if(dp [ind][kk]==dp [ind][kk])
		return dp[ind][kk];
	if(ind ==n )
	{
		if(kk)
			return -1;
		else return 0;
	}
	if(!kk)return 0;
	double maxx=0;
	if(kk == k)
		maxx= (area[ind].fr * area[ind].fr * PI ) + (2* PI * area[ind].fr * area[ind].se)+ get(ind+1, kk-1);
 	else 
 		maxx= max(maxx,  (2 * area[ind].fr * area[ind].se * PI)+ get(ind+1, kk-1));
 	maxx= max(maxx, get(ind+1,kk));
 	return dp[ind][kk]= maxx;
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
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(dp,-1, sizeof dp);
		cout<<"Case #"<<t<<": ";
		cin>>n>>k;
		int x,xx,maxx= 0, minn=1e9;
		forr(i,n)
			cin>>area[i].fr>>area[i].se;
		sort(area, area + n, greater<pair<int, int >> ());
		double sol =get(0,k);
		cout<<fixed<<setprecision(10)<<sol<<"\n";
	}
	return 0;
}