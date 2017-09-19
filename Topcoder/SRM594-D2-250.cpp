#include <bits/stdc++.h>
using namespace std;


class FoxAndClassroom {
public:
	string ableTo(int n, int m) {
		if(__gcd(n,m) == 1)
		{
			return "Possible";
		}
		return "Impossible";
	}
};