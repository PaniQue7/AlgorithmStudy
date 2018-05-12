#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int indegree[1001];

bool isTarget(vector<vector<int>> &vec, int start, int goal)
{
	if ( vec[start].size() == 0 )
		return false;

	bool ret = false;
	for ( int i = 0; i < vec[start].size(); i++ )
	{
		int there = vec[start][i];
		if ( there == goal )
			return true;
		ret = ret || isTarget(vec, there, goal);
	}
	return ret;
}

void _main(int TestCase)
{
	int result = 0;
	int goal_tower;
	int N, K;
	scanf("%d %d", &N, &K);
	vector<int> arr(N + 1); // building cost
	vector<vector<int>> vec(N+1); // graph
	queue<int> q;

	for ( int i = 1; i <= N; i++ )
	{
		scanf("%d", &arr[i]);
	}

	for ( int i = 1; i <= K; i++ )
	{
		int g_start, g_end;
		scanf("%d %d", &g_start, &g_end);
		vec[g_start].push_back(g_end);
		indegree[g_end]++;
	}
	scanf("%d", &goal_tower);

	// 위에부분 input쪽


	while ( 1 )
	{
		int max_value = 0;
		for ( int i = 1; i <= N; i++ )
		{
			if ( indegree[i] == 0 && isTarget(vec, i, goal_tower) )
			{
				if ( max_value < arr[i] )
					max_value = arr[i];
				q.push(i);
				indegree[i]--;
			}
		}
		while ( !q.empty() ) // indegree-- 과정
		{
			int here = q.front();
			q.pop();
			for ( int i = 0; i < vec[here].size(); i++ )
			{
				int there = vec[here][i];
				indegree[there]--;
				//cout << "indegree[there]--" << there << "\n";
			}
		}

		result += max_value;

		if ( indegree[goal_tower] == 0 )
		{
			result += arr[goal_tower];
			break;
		}
	}
	printf("%d\n", result);
	memset(indegree, 0, sizeof(indegree));
};

int main()
{
	int T;
	scanf("%d", &T);
	for ( int i = 1; i <= T; i++ )
	{
		_main(i);
	}
	return 0;
}