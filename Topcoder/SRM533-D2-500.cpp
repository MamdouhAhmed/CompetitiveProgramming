#include <bits/stdc++.h>

using namespace std;


class CasketOfStarEasy {
public:
	map<vector<int>, int> mmp;
	int solve(vector<int> weight)
	{
		if (weight.size() <= 2)
			return 0;
		if(mmp.find(weight)!= mmp.end())
			return mmp[weight];
		int maxx = 0, temp;
		for(int i=1;i<weight.size()-1;i++)
		{
			vector<int> neww = weight;
			temp = weight[i-1]*weight[i+1];
			neww.erase(neww.begin()+i);
			maxx = max(maxx, temp+solve(neww));
		}
		return maxx;
	}
	int maxEnergy(vector <int> weight) {
		return solve(weight);
	}
};