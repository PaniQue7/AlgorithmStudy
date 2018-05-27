//BOJ 10942 ÆÓ¸°µå·Ò?
#include <iostream>
#include <vector>
using namespace std;
int dp[2001][2001]; // dp[start][end] = Check if arr[start]~arr[end] is palindrome, return 1 else 0

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for ( int i = 1; i <= n; i++ )
	{
		cin >> arr[i];
	}

	for ( int i = 1; i <= n; i++ ) // dp length = 1
	{
		dp[i][i] = 1;
	}

	for ( int i = 1; i <= n-1; i++ ) // dp length = 2
	{
		if ( arr[i] == arr[i + 1] )
			dp[i][i + 1] = 1;
	}

	for ( int len = 3; len <= n ; len++ )
	{
		for ( int i = 1; i <= n - len + 1; i++ )
		{
			if ( arr[i] == arr[i + len - 1] )
				dp[i][i + len - 1] = dp[i + 1][i + len - 2];
		}
	}

	int T;
	cin >> T;
	int a, b;
	for ( int i = 0; i < T; i++ )
	{
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}
}