#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int w,h;
	cin >> w >> h;
	vector<vector<int>> vec;
	for(int i=0; i<h; i++)
	{
		vector<int> v;
		v.push_back(0);
		for(int j=0; j<w; j++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		v.push_back(0);
		vec.push_back(v);
	}
	vector<int> v(w+2,0);
	vec.push_back(v);
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			if(vec[i][j]==1)
			{
				if(vec[i+1][j]==1 || vec[i][j+1]==1 || vec[i+1][j+1]==1 || vec[i-1][j-1]==1)
					vec[i][j]=0;
			}
		}
	}
	int count=0;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			if(vec[i][j]==1)
			{
				count++;
			}
		}
	}
	cout << count << endl;

	return 0;
}
