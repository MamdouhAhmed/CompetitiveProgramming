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
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define dist(x,y,xx,yy) sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))
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
	string s;
	int k = 0;
	while(cin>>s)
	{
		if(k++)
			cout<<"\n";
		int n= s.size();
		int b4=0,b100=0,b400=0,b15=0,b55=0;
		for(int i=0;i<n;i++)
		{
			b4 = (b4*10 + (s[i]-'0'))%4;
			b100 = (b100*10 + (s[i]-'0'))%100;
			b400 = (b400*10 + (s[i]-'0'))%400;
			b15 = (b15*10 + (s[i]-'0'))%15;
			b55 = (b55*10 + (s[i]-'0'))%55;
		}
		bool fl = 0, leap = 0;
		if(!b4)
		{
			if(b100 || (!b100&&!b400))
			{
				cout<<"This is leap year.\n";
				fl = leap = 1;
			}
		}
		if(!b15)
		{
			cout<<"This is huluculu festival year.\n";
			fl =1;
		}
		if(leap && !b55)
		{
			cout<<"This is bulukulu festival year.\n";
			fl =1;
		}
		if(!fl)
			cout<<"This is an ordinary year.\n";
	}
	return 0;
}