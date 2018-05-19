#include <iostream>
using namespace std;
long long finger, chance;
long long result;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> finger;
	cin >> chance;
	
	if ( finger == 1 )
	{
		//chance = 1 -> result = 8
		//chance = 2 -> result = 16
		//chance = 3 -> result = 24
		result = 8 * chance;
	}
	else if ( finger == 2 )
	{
		//chance = 1 -> result = 7
		//chance = 2 -> result = 9
		//chance = 3 -> result = 15
		//chance = 4 -> result = 17
		if ( chance % 2 == 1 )
			result = 8 *((chance + 1) / 2) - 1;
		else
			result = 8 * (( chance + 1 ) / 2) + 1;
	}
	else if ( finger == 3 )
	{
		//chance = 1 -> result = 6
		//chance = 2 -> result = 10
		//chance = 3 -> result = 14
		//chance = 4 -> result = 18
		if ( chance % 2 == 1 )
			result = 8 * (( chance + 1 ) / 2) - 2;
		else
			result = 8 * (( chance + 1 ) / 2) + 2;
	}
	else if ( finger == 4 )
	{
		//chance = 1 -> result = 5
		//chance = 2 -> result = 11
		if ( chance % 2 == 1 )
			result = 8 * (( chance + 1 ) / 2) - 3;
		else
			result = 8 * (( chance + 1 ) / 2) + 3;
	}
	else
		//chance = 1 -> result = 12
		//chance = 2 -> result = 20
		result = 8 * chance + 4;

	cout << result;
}