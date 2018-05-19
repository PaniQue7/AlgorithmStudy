#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <utility>

using namespace std;
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, \
    greater<pair<int, pair<int, int> > > > q;
vector<int> visited;
int v, e;

void changeGroup(int to, int from)
{
    for(int i = 1; i <= v; i++)
    {
        if(visited[i] == from)
            visited[i] = to;
    }
}

int main(void)
{
    cin >> v >> e;
    for(int i = 0; i < e; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        q.push(make_pair(weight, make_pair(from, to)));
    }

    visited.resize(v + 1);
    for(int i = 1; i <= v; i++)
    {
        visited[i] = i;
    }

    int res = 0;
    while(!q.empty())
    {
        int w = q.top().first;
        pair<int, int> p = q.top().second;
        q.pop();

        if(visited[p.first] == visited[p.second])
            continue;
        else
        {
            changeGroup(visited[p.first], visited[p.second]);
        }

        res += w;
    }

    cout << res << "\n";
}

