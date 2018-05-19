#include<iostream>

#define MIN(a, b) (a > b ? b : a)
using namespace std;

int rgb[1000][3];
int dp[1000][3];

int main(void)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> rgb[i][j];
        }
    }

    dp[0][0] = rgb[0][0];
    dp[0][1] = rgb[0][1];
    dp[0][2] = rgb[0][2];

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = MIN(dp[i-1][1] + rgb[i][0], dp[i-1][2] + rgb[i][0]);
        dp[i][1] = MIN(dp[i-1][0] + rgb[i][1], dp[i-1][2] + rgb[i][1]);
        dp[i][2] = MIN(dp[i-1][0] + rgb[i][2], dp[i-1][1] + rgb[i][2]);
    }

    int res = dp[n-1][0];
    if(res > dp[n-1][1])
        res = dp[n-1][1];
    if(res > dp[n-1][2])
        res = dp[n-1][2];

    cout << res << "\n";
}
