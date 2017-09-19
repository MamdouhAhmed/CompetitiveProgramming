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


class PikachuEasy {
public:
	string check(string word) {
		int i = 0; 
		for(;i<word.length();)
		{
			if(word.substr(i,3) == "chu")
			{
				i+=3;
			}
			else if(word.substr(i,2) == "pi")
			{
				i+=2;
			}
			else if(word.substr(i,2) == "ka")
			{
				i+=2;
			}
			else
			{
			return "NO";
			}
			
		}
		return "YES";
	}
};