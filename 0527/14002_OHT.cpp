// BOJ 14002 가장 긴 증가하는 부분수열4
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<int> arr(n + 1);
	vector<int> dp(n + 1, 1); // dp[n] = n번째까지 가장 긴 증가하는 수열의 개수
	
	for ( int i = 1; i <= n; ++i )
	{
		cin >> arr[i];
	}
	
	for ( int i = 1; i <= n; ++i )
	{
		for ( int j = 1; j < i; ++j )
		{
			if ( arr[i] > arr[j] && dp[i] < dp[j]+1)
				dp[i] = dp[j] + 1;
		}
	}
	
	int result = 0;
	int index = 0;

	for ( int i = 1; i <= n; ++i )
	{
		if ( result < dp[i] )
		{
			result = dp[i];
			index = i;
		}	
	}
	cout << result << '\n';

	string str = "";
	for ( int i = index; i >= 1; --i )
	{
		if ( dp[i] == result )
		{
			str = to_string(arr[i]) + " " + str;
			result--;
		}
	}
	cout << str;
}