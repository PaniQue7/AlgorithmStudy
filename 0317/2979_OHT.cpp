#include <iostream>
using namespace std;
int A, B, C;
int startTime, endTime;
int time[101];
int result;

int main()
{
	scanf("%d %d %d", &A, &B, &C);
	for ( int i = 1; i <= 3; i++ )
	{
		scanf("%d %d", &startTime, &endTime);
		for ( int j = startTime; j < endTime; j++ )
		{
			time[j] += 1;
		}
	}

	for ( int i = 1; i <= 100; i++ )
	{
		if ( time[i] == 0 ) continue;
		else if ( time[i] == 1 ) result += time[i] * A;
		else if ( time[i] == 2 ) result += time[i] * B;
		else if ( time[i] == 3 ) result += time[i] * C;
	}
	printf("%d\n", result);
}