#include <iostream>
using namespace std;
int arr[65][65];

bool allSame(int row, int col, int size)
{
	int flag = arr[row][col];
	for ( int i = row; i < row + size; i++ )
	{
		for ( int j = col; j < col + size; j++ )
		{
			if ( flag != arr[i][j] )
				return false;
		}
	}
	return true;
}

void solve(int row,int col, int size)
{
	int flag = arr[row][col];
	if ( allSame(row, col, size) == true)
	{
		printf("%d", flag);
	}
	else
	{
		printf("(");
		solve(row, col, size / 2);
		solve(row, col + ( size / 2 ), size / 2);
		solve(row + ( size / 2 ), col, size / 2);
		solve(row + ( size / 2 ), col + ( size / 2 ), size / 2);
		printf(")");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	solve(1, 1, n);
	return 0;
}