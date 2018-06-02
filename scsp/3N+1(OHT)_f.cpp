#include <iostream>
#include <set>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
set<ull> numset;

void dfs(int depth, ull num)
{
	if ( depth == 0 )
	{
		if ( num == 1 )
			return;
		numset.insert(num);
		return;
	}

	if ( num % 3 == 1 && num % 2 == 1 )
	{
		dfs(depth - 1, num * 2);
	}
	else if ( num != 4 && num % 3 == 1 && num % 2 == 0 )
	{
		dfs(depth - 1, num / 3);
		dfs(depth - 1, num * 2);
	}
	else
	{
		dfs(depth - 1, num * 2);
	}
}

void _main(int T)
{
	cout << "Case #" << T << '\n';
	int depth;
	cin >> depth; // 1로 만드는 데 depth번의 기회가 있음.
	if ( depth == 0 )
	{
		cout << 1 << '\n';
		return;
	}
	dfs(depth, 1);
	auto itrbegin = numset.begin();
	ull maxi = (ull)1 << depth;
	cout << *itrbegin << ' ' << maxi << '\n';
	numset.clear();
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for ( int i = 1; i <= T; i++ )
	{
		_main(i);
	}
	return 0;
}