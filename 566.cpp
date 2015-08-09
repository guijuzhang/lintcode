#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cmath>

using namespace std;

class PenguinSledding {
public:
	long long countDesigns(int, vector <int>, vector <int>);
};

long long PenguinSledding::countDesigns(int numCheckpoints, vector <int> checkpoint1, vector <int> checkpoint2) {
	long res=1;
    res = 1;
	int n=checkpoint1.size();
	res+=n;
	vector<int> points(numCheckpoints+1,0);
	vector<vector<bool>> nb(numCheckpoints+1,vector<bool>(numCheckpoints+1,false));
	for(int i=0;i<n;i++)
	{
		points[checkpoint1[i]]++;
		points[checkpoint2[i]]++;
		nb[checkpoint1[i]][checkpoint2[i]]=true;
		nb[checkpoint2[i]][checkpoint1[i]]=true;
	}
	for(int i=1;i<=numCheckpoints;i++)
	{
		int k=points[i];
		res+=pow(2.0,k*1.0)-1-k;
	}
	//triangle numbers
	for(int k=1;k<=numCheckpoints;k++)
	{
		for(int i=1;i<=numCheckpoints;i++ )
		{
			for(int j=i+1;j<=numCheckpoints;j++)
			{
				if(nb[i][j]&&nb[k][i]&&nb[k][j])res++;
			}
		}
	}
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
