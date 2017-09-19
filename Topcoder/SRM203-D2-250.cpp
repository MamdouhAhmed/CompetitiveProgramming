#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class UserName {
public:
	string newMember(vector <string> existingNames, string newName) {
		set<string> ss;
		for(string s: existingNames)
		{
			ss.insert(s);
		}
		string newnewname = newName;
		int n = 0;
		while(ss.find(newnewname)!= ss.end())
		{
			n++;
			newnewname= newName+to_string(n);
		}
		return newnewname;
	}
};