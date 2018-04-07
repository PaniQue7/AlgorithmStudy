#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<pair<int,int>> st;
int M, N, input;
int arr[501][501];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int result;

int main()
{
	scanf("%d %d", &M, &N);
	for ( int i = 1; i <= M; i++ )
	{
		for ( int j = 1; j <= N; j++ )
		{
			scanf("%d", &arr[i][j]);
		}
	}
	st.push({ 1,1 });
	while ( !st.empty() )
	{
		int sero = st.top().first;
		int garo = st.top().second;
		if ( sero == M && garo == N ) result++;
		st.pop();
		for ( int i = 0; i < 4; i++ )
		{
			int m_sero = sero + dy[i];
			int m_garo = garo + dx[i];
			if ( ( arr[m_sero][m_garo] < arr[sero][garo] ) && 
				( 1 <= m_sero && m_sero <= M ) && ( 1 <= m_garo && m_garo <= N ) )
			{
				st.push({ m_sero,m_garo });
			}
		}
	}
	printf("%d", result);
	return 0;
}