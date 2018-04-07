#include <iostream>
using namespace std;
int map[51][51];
int row, col;
int dx[] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };


void dfs(int row, int col)
{
	map[row][col] = 0;
	for ( int i = 0; i < 9; i++ )
	{
		int my = row + dy[i];
		int mx = col + dx[i];
		if ( map[my][mx] == 1 )
			dfs(my, mx);
	}
}

int main()
{
	while ( 1 )
	{
		int cnt = 0;
		scanf("%d %d", &col, &row);
		if ( col == 0 && row == 0 )
			break;
		for ( int i = 1; i <= row; i++ )
		{
			for ( int j = 1; j <= col; j++ )
			{
				scanf("%d", &map[i][j]);
			}
		}
		for ( int i = 1; i <= row; i++ )
		{
			for ( int j = 1; j <= col; j++ )
			{
				if ( map[i][j] == 1 )
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);		
	}
	return 0;
}