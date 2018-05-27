#include <cstdio>

bool dp[2001][2001]; // dp[i][j] -> is it pendulum from index i to j
int arr[2001];

using namespace std;

int main(void)
{
    int n, c;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Set 1,2 length pendulum
    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = true;
        if(arr[i-1] == arr[i])
            dp[i-1][i] = true;
    }

    // 1 2 2 1 
    // if arr[1] == arr[4]
    // and dp[2][3] is true since 2,2 is same
    // then it is a pendulum
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n-i; j++)
        {
            if(arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
                dp[j][j + i] = true;
        }
    }

    scanf("%d", &c);
    for(int i = 0; i < c; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a][b]);
    }
}
