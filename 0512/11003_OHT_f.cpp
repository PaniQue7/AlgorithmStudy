#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N, L;
vector<int> arr;

void Max_arr(vector<int> vec)
{
	int ret;
	for ( int i = 1; i < L; i++ )
	{
		ret = pow(10, 9);
		for ( int j = i - L + 1; j <= i; j++ )
		{
			if ( j <= 0 )
				continue;
			ret = min(ret, arr[j]);
		}
		printf("%d ", ret);
	}
}

int main()
{
	scanf("%d %d", &N, &L);
	arr.resize(N+1);
	for ( int i = 1; i <= N; i++ )
	{
		scanf("%d", &arr[i]);
	}
	
	Max_arr(arr);
	
	return 0;
}