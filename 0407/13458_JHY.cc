#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int tr;
	vector<long long> tm;
	long long m[1000001] = {0};
	int b,c;
	cin >> tr;
	for(int i=0; i<tr; i++)
	{
		long long num;
		cin >> num ;
		tm.push_back(num);
	}
	cin >> b >> c;
	for(int i=0; i<tr; i++)
	{
		tm[i] -= b;
		if(tm[i]<0)
			tm[i]=0;
	}
	
	long long sum=0;
	for(int i=0; i<tr; i++)
	{
		if(tm[i]%c!=0)
			sum += (tm[i]/c+1);
		else
			sum += (tm[i]/c);
	}

	cout << sum+tr << endl;
	return 0;
}

