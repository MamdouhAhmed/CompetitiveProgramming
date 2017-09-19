#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define OO (int)1e9
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define dist(x,y,xx,yy) sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))
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
	int N;
	cin>>N;
	while(N--)
	{
		int n;
		cin>>n;
		int x[n],y[n];
		double adj[100][100];
		forr(i,n)
			cin>>x[i]>>y[i];
		forr(i,n)forr(j,n) adj[i][j]= dist(x[i],y[i],x[j],y[j]);
		forr(k,n)forr(i,n)forr(j,n) adj[i][j]= min(adj[i][j], adj[i][k]+adj[k][j]);
		int maxx=0;
		forr(i,n)
		{
			int m=0;
			forr(j,n)
			{
				m+=adj[i][j];
				cout<<adj[i][j]<<" ";
			}
			cout<<"\n";
			maxx = max(m,maxx);
		}
		cout<<maxx<<"\n";
	}
	return 0;
}

http://hicit.sha.edu.eg/index.php?code=314140126&action=stu&view=1&1=&2=&3=&4=&5=&6=&7=&8=&9=&10=&11=&12=&13=&14=&15=&16=&17=&18=&19=&20=&21=&22=&23=&24=&25=&26=&27=&28=&29=&30=&31=&32=&33=&34=&35=&36=&37=&38=&39=&40=&41=&42=&43=&44=&45=&46=&47=&48=&49=&50=&51=&52=&53=&54=&55=&56=&57=&58=&59=&60=&61=&62=&63=&64=&65=&66=&67=&68=&69=&70=&71=&72=&73=&74=&75=&76=&77=&78=&79=&80=&81=&82=&83=&84=&85=&86=&87=&88=&89=&90=&91=&92=&93=&94=&95=&96=&97=&98=&99=&100=&101=&102=&103=&104=&105=&106=&107=&108=&109=&110=&111=&112=&113=&114=&115=&Submit=