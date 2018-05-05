#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	arr.resize(n);
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];
	
	int i = n - 1;
	while ( i > 0 && arr[i - 1] >= arr[i] ) i--;
	if ( i <= 0 )
	{
		cout << "-1" << '\n';
		return 0;
	}
	int j = n - 1;
	while ( arr[j] <= arr[i - 1] ) j--;
	int temp = arr[j];
	arr[j] = arr[i - 1];
	arr[i - 1] = temp;	
	sort(arr.begin() + i, arr.end());
	for ( auto i = arr.begin(); i != arr.end(); i++ )
	{
		cout << *i << " ";
	}

}
