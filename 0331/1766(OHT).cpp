#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int n, m;
int pre, post;
vector<int> vec[32001];
priority_queue <int, vector<int>, greater<int>> q;
int indegree[32001];
int main()
{
	scanf("%d %d", &n, &m);
	for ( int i = 0; i < m; i++ )
	{
		scanf("%d %d", &pre, &post);
		vec[pre].push_back(post);
		indegree[post]++;
	}
	for ( int i = 1; i <= n; i++ )
	{
		if ( indegree[i] == 0 )	q.push(i);
	}
	while ( !q.empty() )
	{
		int here = q.top();
		q.pop();
		printf("%d ", here);
		for ( int j = 0; j < vec[here].size(); j++ )
		{
			int there = vec[here][j];
			indegree[there]--;
			if(indegree[there] == 0) q.push(there);
		}
	}
	printf("\n");
	return 0;
}