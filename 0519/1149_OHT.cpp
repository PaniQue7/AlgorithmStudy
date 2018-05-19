// BOJ_1149 RGB거리
#include <iostream>
#include <algorithm>
using namespace std;
int Arr[1000][3];
int D[1000][3]; // D[n][0]은 n개의 집을 칠하고 마지막 집을 0으로 칠했을때의 최소 비용

int main()
{
	int N;
	scanf("%d", &N);
	for ( int i = 0; i < N; i++ )
	{
		cin >> Arr[i][0] >> Arr[i][1] >> Arr[i][2];
	}
	for ( int i = 0; i < 3; i++ )
	{
		D[0][i] = Arr[0][i];
	}
	for ( int i = 1; i < N; i++ )
	{
		D[i][0] = min(D[i - 1][1] + Arr[i][0], D[i - 1][2] + Arr[i][0]);
		D[i][1] = min(D[i - 1][0] + Arr[i][1], D[i - 1][2] + Arr[i][1]);
		D[i][2] = min(D[i - 1][0] + Arr[i][2], D[i - 1][1] + Arr[i][2]);
	}
	int result = min(min(D[N - 1][0], D[N - 1][1]),D[N-1][2]);
	printf("%d", result);
}