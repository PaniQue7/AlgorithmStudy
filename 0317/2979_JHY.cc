#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v(100,0);
	int a,b,c,min=0,max=0;
	cin >> a >> b >> c;
	for(int i=0; i<3; i++)
	{
		int x, y;
		cin >> x >> y;
		if(min>x) min = x;
		if(max<y) max = y;
		for(int i=x; i<y; i++)
		{
			v[i]++;
		}
	}

	//result
	int result=0;
	for(int i=min; i<max; i++)
	{
		if(v[i]==1) result += a;
		else if(v[i]==2) result += b*2;
		else if(v[i]==3) result += c*3;
	}
	cout << result;
}

