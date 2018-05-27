#include <cstdio>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int arr[10001];
vector<pair<int, string> > dp(10001);

int main(void)
{
    int c;
    scanf("%d", &c);

    for(int i = 1; i <= c; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= c; i++)
    {
        int maxDp = 0;
        string list;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && maxDp < dp[j].first)
            {
                maxDp = dp[j].first;
                list = dp[j].second;
            }
        }
        dp[i].first = maxDp + 1;
        if(list != "")
            dp[i].second = list + " " + to_string(arr[i]);
        else
            dp[i].second = to_string(arr[i]);
    }

    int max = 0;
    int index = 1;
    for(int i = 1; i <= c; i++)
    {
        if(dp[i].first > max)
        {
            max = dp[i].first;
            index = i;
        }
    }

    printf("%d\n%s\n", dp[index].first, dp[index].second.c_str());
}
