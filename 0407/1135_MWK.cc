#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int N;
vector<int> adj[51];
priority_queue<pair<int, int> > pq[51];

int dfs(int here) {
    int ret = 0;
    int plus = 0;

    for (int i = 0; i < adj[here].size(); i++) {
        pq[here].push(make_pair(1 + dfs(adj[here][i]), adj[here][i] ));
    }

    while (!pq[here].empty()) {
        // Get the child which takes the longest and call them first
        int cost = pq[here].top().first;
        pq[here].pop();
        ret = max(ret, cost + plus);
        plus ++;
    }

    return ret;
}

int main() {
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        int u;
        scanf("%d", &u);
        if (u == -1) 
			continue;
		adj[u].push_back(n);
    }

    printf("%d\n", dfs(0));
    return 0;
}

