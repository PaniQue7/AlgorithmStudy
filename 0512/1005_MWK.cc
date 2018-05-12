#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> times;
vector<vector<int> > depend;
vector<int> dp;

void dfs(int node)
{
    if(depend[node].empty())
    {
        dp[node] = times[node];
    }
    else
    {
        for(int i = 0; i < depend[node].size(); i++)
        {
            if(dp[depend[node][i]] == -1)
            {
                dfs(depend[node][i]);
            }

            int m = times[node] + dp[depend[node][i]];
            if(dp[node] < m)
                dp[node] = m;
        }
    }
}

int main(void)
{
    int games;
    cin >> games;
    while(games--)
    {
        int n, k;
        cin >> n >> k;

        times.clear();
        depend.clear();
        dp.clear();

        times.resize(n + 1);
        depend.resize(n + 1);
        dp.resize(n + 1, -1);

        for(int i = 1; i <= n; i++)
        {
            cin >> times[i];
        }

        for(int i = 1; i <= k; i++)
        {
            int from, to;
            cin >> from >> to;
            depend[to].push_back(from);
        }

        int target;
        cin >> target;

        dfs(target);

        cout << dp[target] << "\n";
    }
}
