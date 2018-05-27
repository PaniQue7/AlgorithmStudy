#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pint;
priority_queue<pint, vector<pint>, greater<pint>> pq;
int visited[100001];

struct Point
{
	int x;
	int y;
	int z;
};

int getDistance(Point& p1, Point& p2)
{
	int ret = 0;
	int diff_x = abs(p1.x - p2.x);
	int diff_y = abs(p1.y - p2.y);
	int diff_z = abs(p1.z - p2.z);
	ret = min(diff_x, diff_y);
	ret = min(ret, diff_z);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<Point> arr(n + 1);
	for ( int i = 1; i <= n; i++ )
	{
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
	}

	int result = 0;
	pq.push({ 0,1 }); // {cost,destination}
	while ( !pq.empty() )
	{
		int here = pq.top().second;
		if ( visited[here] )
		{
			pq.pop();
			continue;
		}
		visited[here] = 1;
		result += pq.top().first;
		pq.pop();
		for ( int i = 1; i <= n; i++ )
		{
			if ( here == i )
				continue;
			pq.push({ getDistance(arr[here],arr[i]),i });
		}
	}
	cout << result << '\n';
	return 0;
}