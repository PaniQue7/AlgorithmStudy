//BOJ 1037 ¾à¼ö
#include <iostream>
using namespace std;
int arr[51];

int main()
{
	int n;
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d", &arr[i]);
	}

	int min, max;
	min = max = arr[1];
	for ( int i = 1; i <= n; i++ )
	{
		if ( min > arr[i] )
			min = arr[i];
		if ( max < arr[i] )
			max = arr[i];
	}
	printf("%d\n", min*max);
	
	return 0;
}