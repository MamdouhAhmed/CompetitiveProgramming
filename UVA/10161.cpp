#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
///////////////////// Solution Code
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Mamdouh\\Desktop\\a1.in","r",stdin);
		freopen("C:\\Users\\Mamdouh\\Desktop\\A2.out","w",stdout);
	#endif
	long long n;
	while(cin>>n && n)
	{
		long long m = trunc(sqrt(n));
		long long delta = n-(m*m);
		if (delta == 0)
		{
			if((m&1)==0) cout<<m<<" "<<1<<"\n";
			else cout<<1<<" "<<m<<"\n";
			continue;
		}
		if(delta == m+1)
		{
			cout<<m+1<<" "<<m+1<<"\n";
			continue;
		}
		int x= 0,y=0;
		if(delta>m+1)
		{
			x = m+1;
			y = (m+1)*(m+1)- n+1;
			
		}
		else
		{
			y = m+1;
			x = delta;
		}
		if(!(m&1))
			swap(x,y);
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}