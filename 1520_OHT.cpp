#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, pair<int, int>>> vec; // vector<{value,{ypos,xpos}}>
int dp[501][501];
int arr[501][501];
int M, N, input;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int num = 1;


int main()
{
	dp[1][1] = 1;
	scanf("%d %d", &M, &N);
	vec.resize(M*N + 1);
	for ( int i = 1; i <= M; i++ )
	{
		for ( int j = 1; j <= N; j++ )
		{
			scanf("%d", &input);
			arr[i][j] = input;
			vec[num].first = input;
			vec[num].second.first = i;
			vec[num].second.second = j;
			num++;
		}
	}
	sort(vec.begin() + 1, vec.end());
	for ( int i = M*N; i >= 1; i-- ) // 높이가 높은숫자부터
	{
		for ( int j = 0; j < 4; j++ )
		{
			int _y = vec[i].second.first;
			int _x = vec[i].second.second;
			int move_y = _y + dy[j];
			int move_x = _x + dx[j];
			if ( move_y <= 0 || move_y > M || move_x <= 0 || move_x > N ) continue;
			if ( dp[_y][_x] && arr[move_y][move_x] < arr[_y][_x] ) dp[move_y][move_x] += dp[_y][_x];
		}
	}
	printf("%d\n", dp[M][N]);
	
}