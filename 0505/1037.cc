#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	set<long long> s;
	set<long long>::iterator it1;
	set<long long>::iterator it2;
	
	for(int i=0; i<n; i++)
	{
		long long num;
		cin >> num;
		s.insert(num);
	}
	
	it1 = s.begin();
	it2 = s.end();
	it2--;

	long long result;
	result = (*it1)*(*it2);
	
	cout << result;
}
