#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <stdio.h>
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
string srr[100];
bool brr[100][100];
int p,si,sj;
void color(int i, int j)
{
	if(i<0||i>=90||j<0||j>=90||brr[i][j]) return;
	brr[i][j]=1;
	color(i+1, j);
	color(i-1, j);
	color(i, j+1);
	color(i, j-1);
	return;
}
void print(string s)
{
	bool pr=0;
	for(int i=s.length()-1;i>=0;i--)
	{
		if(s[i]!=' ')
		{
			for(int j=0;j<=i;j++)
				cout<<s[j];
			break;
		}
	}
	cout<<"\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("coaches.in","r",stdin);
	#ifndef ONLINE_JUDGE
	#ifdef _WIN64
	freopen("C:\\Users\\mamdouh\\Desktop\\a1.in","r",stdin);
	freopen("C:\\Users\\mamdouh\\Desktop\\A2.out","w",stdout);
	#elif __linux__
	freopen("/media/mamdouh/System/Users/Mamdouh/Desktop/a1.in","r",stdin);
	freopen("/media/mamdouh/System/Users/Mamdouh/Desktop/A2.out","w",stdout);
	#endif
	#endif
	int n;
	cin>>n;
	cin.ignore();
	while(n--)
	{
		p=0;
		memset(brr, 0, sizeof brr);
		while(getline(cin,srr[p]))
		{	
			srr[p]=srr[p]+(string(100-((int)srr[p].length()),' '));
			if(srr[p][0]=='_')
			{
				p++;
				break;
			}
			for(int i=0;i<srr[p].length();i++)
			{
				if(srr[p][i]=='X')
				{
					brr[p][i]=1;
				}
				if(srr[p][i]=='*')
				{
					si=p;
					sj=i;
					srr[p][i]=' ';
				}
			}
			p++;
		}
		int k = p;
		color(si,sj);
		for(int i=0;i<k-1;i++)
		{
			for(int j=0;j<90;j++)
			{
				if(brr[i][j] && srr[i][j]!='X')
				{
					if(i && (srr[i-1][j]=='X')) srr[i][j]='#';
					else if(j && (srr[i][j-1]=='X')) srr[i][j]='#';
					else if(srr[i+1][j]=='X') {srr[i][j]='#';}
					else if(srr[i][j+1]=='X') srr[i][j]='#';
				}
			}
			print(srr[i]);
		}
		print(srr[k-1]);
	}

	return 0;
}