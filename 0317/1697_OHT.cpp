#include <iostream>
#include <queue>
using namespace std;
int N, K;
int visited[100001];
queue<int> q;


int main()
{
	scanf("%d %d", &N, &K);
	visited[N] = 1;
	q.push(N);
	while ( !q.empty() )
	{
		int here = q.front();
		if ( here == K )
		{
			printf("%d\n", visited[here]-1);
			return 0;
		}
		q.pop();

		if ( 2 * here <= 100000 && !visited[2 * here] )
		{
			visited[2 * here] = visited[here] + 1;
			q.push(2 * here);
		}
		if ( here - 1 >= 0 && !visited[here - 1] )
		{
			visited[here - 1] = visited[here] + 1;
			q.push(here - 1);
		}
		if ( here + 1 <= 100000 && !visited[here + 1] )
		{
			visited[here + 1] = visited[here] + 1;
			q.push(here + 1);
		}
	}
	
}