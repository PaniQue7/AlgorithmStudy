//BOJ 1197 Minimum Spanning Tree - Prim Algorithm(Priority Queue)
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> pint;
priority_queue<pint,vector<pint>,greater<pint>> pq; // min-heap
bool visited[10001];

int main()
{
	int result = 0;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int V, E;
	cin >> V >> E;

	vector<vector<pint>> vec(V + 1); // pint = pair{cost,destination}
	int a, b, c;
	for ( int i = 0; i < E; i++ )
	{
		cin >> a >> b >> c;
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}

	//start vertex = 1;
	pq.push({ 0,1 });
	while ( !pq.empty() )
	{
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if ( visited[here] )
			continue;
		result += cost;
		visited[here] = true;
		for ( int i = 0; i < vec[here].size(); i++ )
		{
			pq.push(vec[here][i]);
		}
	}
	cout << result;
}
