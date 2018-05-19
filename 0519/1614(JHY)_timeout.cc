#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	long long n,c,f=0,max=0;
	cin >> n >> c;

	int arr[] ={1,2,3,4,5,4,3,2};

	for(int i=0; f<=c; i++)
	{
		if(i==8)
			i=0;

		if(arr[i] == n)
			f++;
		max++;
	}

	cout << max-1;

	return 0;
}
