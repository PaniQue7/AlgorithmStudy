// BOJ 1193 분수찾기
#include <iostream>
using namespace std;

int TotalSum(int num)
{
	int ret = 0;
	for ( int i = 0; i <= num; i++ )
	{
		ret += i;
	}
	return ret;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if ( n == 1 )
	{
		cout << "1/1" << '\n';
		return 0;
	}
	int pos = 0;
	for ( int i = 1; i <= n; i++ )
	{
		if ( n <= TotalSum(i) )
		{
			pos = i;
			break;
		}
	}
	// pos = 5; n = 14, TotalSum(5) = 15
	int bunja, bunmo;
	//pos가 짝수면 내려가는방향 홀수면 올라가는방향
	if ( pos % 2 == 0 )
	{
		bunja = pos;
		bunmo = 1;
		int temp = TotalSum(pos) - n;
		bunja -= temp;
		bunmo += temp;
	}
	else
	{
		bunja = 1;
		bunmo = pos;
		int temp = TotalSum(pos) - n;
		bunja += temp;
		bunmo -= temp;
	}
	cout << bunja << "/" << bunmo << '\n';


}