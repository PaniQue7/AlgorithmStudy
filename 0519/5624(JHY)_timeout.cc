#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> v;
set<int> s;
int n;
int max;
int c=0;

int func(int k)
{
	for(int y=k-1; y>=0; y--)
	{
		int tmp = v[k]-v[y];
		if(s.find(tmp)!=s.end())
			return 1;
	}
	return 0;
}

int main(void)
{
	cin >> n;

	for(int i=0; i<n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		for(int j=i; j>=0; j--)
		{
			s.insert(v[i]+v[j]);
			s.insert(v[j]+v[j]);
		}
		if(i>1)
		{
			c += func(i);
		}
	}

	if(v[1]==v[0]*3)
		c += 1;

	cout << c ;
	return 0;
}
