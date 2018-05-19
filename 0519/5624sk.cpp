
#include <iostream>

using namespace std;



int main(void)
{
	int n;
	int cnt = 0;
	int arr[5000];
	int num[400000] = { 0 };	//// 0~199999 는 음수범위, 200000~399999는 양수범위

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// X+Y+Z = W   ->  X+Y = W-Z
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (num[arr[i] - arr[j] + 200000])	// W-Z
			{
				cnt++;
				break;
			}
		}

		for (int j = 0; j <= i; j++)	// 중복이 가능하니까 등호 포함
			num[arr[i] + arr[j] + 200000]++;	// X+Y
	}


	printf("%d", cnt);

	return 0;
}

/* solution
#include <cstdio>

using namespace std;

const int MAXN = 5001;
const int M    = 200000;

int n, a[MAXN], e[2*M+1];

inline int q(int b) { return e[b+M]; } // query
inline void u(int b) { e[b+M] = 1; } // update

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	int sol = 0;
	for (int i = 0, ok = 0; i < n; ++i, ok = 0)
	{
		for (int j = 0; j <  i && !ok; ++j)
			ok = q(a[i]-a[j]);
		for (int j = 0; j <= i; ++j)
			u(a[i]+a[j]);
		sol += ok;
	}

	printf("%d\n", sol);
	return 0;
}
*/