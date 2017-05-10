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
struct point
{
	int x,y;
};
struct line{
	point start, end;
};
bool pons(point p, point q, point r)
{
	return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}
int ori(point p, point q, point r)
{
	int val = (q.y-p.y)*(r.x-q.x) - (q.x - p.x) * (r.y - q.y);
	if(!val) return 0;
	return (val > 0)? 1: 2;
}
bool intersect(point p1, point q1, point p2, point q2)
{
	int o1 = ori(p1, q1, p2);
    int o2 = ori(p1, q1, q2);
    int o3 = ori(p2, q2, p1);
    int o4 = ori(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && pons(p1, p2, q1)) return true;
    if (o2 == 0 && pons(p1, q2, q1)) return true;
    if (o3 == 0 && pons(p2, p1, q2)) return true;
    if (o4 == 0 && pons(p2, q1, q2)) return true;
 
    return false;
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
	while(T--)
	{
		point one,three,ls,le;
		cin>>ls.x>>ls.y>>le.x>>le.y>>one.x>>one.y>>three.x>>three.y;
		point two, four;
		two.x = three.x;
		two.y = one.y;
		four.x = one.x;
		four.y = three.y;
		if(intersect(one , two, ls,le) || intersect(two , three, ls,le) ||intersect(three , four, ls,le) ||intersect(four , one, ls,le)
			|| pons(one,ls ,three))

			cout<<"T\n";
		else 
			cout<<"F\n";
	}
	return 0;
}