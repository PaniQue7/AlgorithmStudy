// BOJ 12015 Longest Increasing Sequence 2 O(NlogN) solution
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> arr;
vector<int> lis;

int lower_bound(int s, int e, int target) // start, end, target
{
	int m;
	while ( e - s > 0 )
	{
		m = ( s + e ) / 2;
		if ( lis[m] < target )
			s = m + 1;
		else
			e = m;
	}
	return e + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	arr.resize(n);
	for ( int i = 0; i < n; ++i )
	{
		cin >> arr[i];
	}

	
	lis.push_back(arr[0]);

	int i = 1; // used for arr[]
	int j = 0; // used for lis[]
	
	while ( i < n )
	{
		if ( lis[j] < arr[i] ) // if input arr[i] is the largest, append
		{
			lis.push_back(arr[i]);
			j++;
		}
		else // replace
		{
			// #include <algorithm>
			// auto itr = lower_bound(lis.begin(),lis.end(),arr[i]);
			int itr = lower_bound(0, j, arr[i]);
			lis[itr-1] = arr[i];
		}
		i++;
	}
	
	cout << j+1 << '\n';
}