#include <iostream>
using namespace std;
int BinoArr[30][30];

int Binomial(int n,int r) // = nCr
{
	if ( r == 0 ) return 1;
	if ( n == r ) return 1;
	if ( BinoArr[n][r] > 0 ) return BinoArr[n][r];
	return BinoArr[n][r] = Binomial(n - 1, r - 1) + Binomial(n - 1, r);
}
int main()
{
	int TestCase;
	int n, m;
	scanf("%d", &TestCase);
	for ( int i = 0; i < TestCase; i++ )
	{
		scanf("%d %d", &n, &m);
		int result = Binomial(m, n);
		printf("%d\n", result);
	}
	return 0;
}