//BOJ 1197 Minimum Spanning Tree - Prim Algorithm
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

typedef pair<int, int> pint;
bool visited[10001];
set<pint> MinHeapSet;
int vertex_cnt;

int main()
{
	int result = 0;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int V, E;
	cin >> V >> E;

	vector<vector<pint>> vec(V+1); // pint = pair{cost,destination}
	int a, b, c;
	for ( int i = 0; i < E; i++ )
	{
		cin >> a >> b >> c;
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	
	int here = 1;
	while (1)
	{
		visited[here] = true;
		vertex_cnt++;
		if ( vertex_cnt == V )
			break;
		for ( int i = 0; i < vec[here].size(); i++ )
		{
			MinHeapSet.insert(vec[here][i]);
		}
		auto itr = MinHeapSet.begin();
		// if itr->second(=there) is visited, continue;
		while ( visited[itr->second] == true )
		{
			itr = MinHeapSet.erase(itr);
		}
		result += itr->first;
		here = itr->second;
		MinHeapSet.erase(itr);
	}

	cout << result << '\n';
}
