#include <iostream>
using namespace std;
int num_tester[1000001];
int n;
int b, c;
long long result;

int main()
{
	scanf("%d", &n);

	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d", &num_tester[i]);
	}
	scanf("%d %d", &b, &c);
	for ( int i = 1; i <= n; i++ )
	{
		num_tester[i] -= b;
		result++;
		if ( num_tester[i] <= 0 ) continue;

		if ( num_tester[i] % c == 0 )
			result += (num_tester[i] / c);
		else
			result += (num_tester[i] / c) + 1;
	}
	printf("%lld\n", result);
	return 0;
}