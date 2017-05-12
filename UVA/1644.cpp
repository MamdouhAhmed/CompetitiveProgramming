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
int arr[100100],p=0;
bool np[1299800];
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
	
	memset(np,1,sizeof np);
	np[0]=np[1]=0;
	forr(i,1299800)
	{
		if(np[i])
		{
			arr[p++]=i;
			for(int j=i*2;j<1299800;np[j]=0,j+=i);
		}
	}
	int t,kk;
	while(cin>>t && t)
	{
		kk = distance(arr, lower_bound(arr, arr+p, t));
		if(arr[kk]==t)
			cout<<"0\n";
		else 
		{
			cout<<arr[kk]-arr[kk-1]<<"\n";
		}
	}
	return 0;
}