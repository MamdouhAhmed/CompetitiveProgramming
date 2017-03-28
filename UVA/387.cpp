#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
///////////////////// Solution Code
int n,totsz;
vector<string> pieces[10];
int x[10],y[10],sz[10];
vector<string> sol;
bool solved;
void get(vector<string> & here, int ind, int need)
{
	if(solved) return;
	if(!need && ind == n){
		sol = here;
		solved=1;
	}
	if (ind == n) return;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			bool kay=1;
			vector<string> now(here);

			for(int k=0;k<x[ind]&&kay;k++)
			{
				for(int l=0;l<y[ind]&&kay;l++)
				{
					if(pieces[ind][k][l]=='0') continue;
					if(j+l>=4 || i+k >= 4){
						kay=0;
						break;
					}
					kay &= (now[i+k][j+l]=='0');
					now[i+k][j+l] = '1'+ind;
				}
			}
			if(kay)
				get(now,ind+1,need-sz[ind]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	/*#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\mamdouh\\Desktop\\a1.in","r",stdin);
		freopen("C:\\Users\\mamdouh\\Desktop\\A2.out","w",stdout);
	#endif*/
	#ifndef ONLINE_JUDGE
		freopen("/media/mamdouh/System/Users/Mamdouh/Desktop/a1.in","r",stdin);
		freopen("/media/mamdouh/System/Users/Mamdouh/Desktop/A2.out","w",stdout);
	#endif
	int kko=0;
	while(cin>>n&&n)
	{
		if(kko++) cout<<"\n";
		solved=0;
		totsz=0;
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
			pieces[i].resize(x[i]);
			sz[i]=0;

			for(int j=0;j<x[i];j++)
			{
				cin>>pieces[i][j];
				for(int k=0;k<y[i];k++)
				{
					sz[i]+=(pieces[i][j][k]!='0');
				}
			}
			totsz += sz[i];
		}
		if(totsz != 16)
		{
			cout<<"No solution possible\n";
			continue;
		}
		vector<string> ss(4,"0000");
		get(ss,0,16);
		if(solved)
		{
			for(int i=0;i<4;i++)
				cout<<sol[i]<<"\n";
		}
		else 
			cout<<"No solution possible\n";
	}
	return 0;
}