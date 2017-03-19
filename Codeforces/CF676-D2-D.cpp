#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
///////////////////// Solution Code, Ignore all of the above
char rotate(char in)
{
	if(in == '*' || in == '+')
		return in;
	int pl;
	if((pl = string("|-").find(in))!= -1)
		return string("|-")[!((bool)pl)];
	if((pl = string("^>v<").find(in))!= -1)
		return string("^>v<")[(++pl)%4];
	if((pl = string("RDLU").find(in))!= -1)
		return string("RDLU")[(++pl)%4];
}
bool horcon(char a, char b)
{
	if(a == '*' || b == '*') 
		return 0;
	if((a == '+' || a =='>'|| a == '-' || (string("RDLU").find(a) != -1 && a != 'R'))
		&&
		(b == '+' || b =='<'|| b == '-'|| (string("RDLU").find(b) != -1 && b != 'L'))
		)
		return 1;
	return 0;
}
bool vertcon(char a, char b)
{
	if(a == '*' || b == '*') 
		return 0;
	if((a== '+' || a=='v'|| a=='|' || (string("RDLU").find(a)!=-1 && a!='D'))
		&&
		(b== '+' || b=='^'|| b=='|'|| (string("RDLU").find(b)!=-1 && b!='U'))
		)
		return 1;
	return 0;
}
int n,m,i,j,ii,jj;
string arr[4][1000];
bool vis[4][1010][1010];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Mamdouh\\Desktop\\a1.in","r",stdin);
		freopen("C:\\Users\\mamdouh\\Desktop\\A2.out","w",stdout);
	#endif
	while(cin>>n>>m)
	{
		memset(vis,0,sizeof vis);

		for(int i=0;i<n;i++)
		{
			cin>>arr[0][i];
			arr[3][i]=arr[2][i]=arr[1][i]=string(m,'0');
			for(int j=0;j<m;j++)
			{
				arr[1][i][j]= rotate(arr[0][i][j]);
				arr[2][i][j]= rotate(arr[1][i][j]);
				arr[3][i][j]= rotate(arr[2][i][j]);
			}

		}
		int cnt=0;
		bool fl = 0;
		pair<int,pair<int, int> > bloc={1000000,{1000000,1000000}}, cur ,q;
		cin>>i>>j>>ii>>jj;
		i--;j--;ii--;jj--;
		queue<pair<int,pair<int, int> > > bfs;
		bfs.push({0,{i,j}});
		bfs.push(bloc);
		while(!bfs.empty())
		{
			cur = bfs.front();
			bfs.pop();
			if(cur == bloc)
			{
				if (bfs.empty())
					break;
				cnt++;
				bfs.push(bloc);
			}
			else
			{
				if(cur.second == make_pair(ii,jj))
				{
					fl=1;
					break;
				}
				vis[cur.first][cur.second.first][cur.second.second]=1;
				int i=cur.first,j=cur.second.first,k=cur.second.second;
				if(k<m-1 &&horcon(arr[i][j][k],arr[i][j][k+1])&& !vis[i][j][k+1]++)
				{
					bfs.push({i,{j,k+1}});
				}
				if(k &&horcon(arr[i][j][k-1],arr[i][j][k])&& !vis[i][j][k-1]++)
				{
					bfs.push({i,{j,k-1}});
				}
				if(j<n-1 && vertcon(arr[i][j][k],arr[i][j+1][k]) && !vis[i][j+1][k]++)
				{
					bfs.push({i,{j+1,k}});
				}
				if(j && vertcon(arr[i][j-1][k],arr[i][j][k]) && !vis[i][j-1][k]++)
				{
					bfs.push({i,{j-1,k}});
				}
				if(i<3&& !vis[i+1][j][k]++ )
				{
					bfs.push({i+1,{j,k}});
				}
				if(i==3 && !vis[0][j][k]++)
				{
					bfs.push({0,{j,k}});
				}
			}

		}
		if(!fl)
			cout<<"-1\n";
		else cout<<cnt<<"\n";


	}
	return 0;
}