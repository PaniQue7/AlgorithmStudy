#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

#define ABS(a) a < 0? -a : a
priority_queue<pair<int, int>, vector<pair<int, int> >, \
        greater<pair<int, int> > > pq;
vector<vector<int> > points;
vector<int> visited(count);


int getMin(vector<int>& p1, vector<int>& p2)
{
    int x, y, z;
    x = p1[0] - p2[0];
    y = p1[1] - p2[1];
    z = p1[2] - p2[2];

    x = ABS(x);
    y = ABS(y);
    z = ABS(z);

    if(x < y)
    {
        if(x < z)
            return x;
        else
            return z;
    }
    else if(y < z)
    {
        return y;
    }
    else
        return z;
}

int main(void)
{
    int count;
    scanf("%d", &count);
    points.resize(count);
    for(int i = 0; i < count; i++)
    {
        points[i].resize(3);
        scanf("%d %d %d", &points[i][0], &points[i][1], &points[i][2]);
    }

    pq.push(make_pair(0, 0));
    int minCost = 0;

    while(!pq.empty())
    {
        int point = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(visited[point])
            continue;

        visited[point] = true;
        minCost += cost;
        for(int i = 0; i < count; i++)
        {
            if(i != point && !visited[i])
            {
                pq.push(make_pair(getMin(points[point], points[i]), i));
            }
        }
    }

    printf("%d\n", minCost);
}

