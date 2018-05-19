#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int arr[1000][3] = {0};

	int r,g,b;
	cin >> r >> g >> b;

	arr[0][0] = r;
	arr[0][1] = g;
	arr[0][2] = b;

	for(int i=1; i<n; i++)
	{
		int r,g,b;
		cin >> r;
		if(arr[i-1][1]>arr[i-1][2])
			arr[i][0] = r + arr[i-1][2];
		else
			arr[i][0] = r + arr[i-1][1];
			

		cin >> g;
		if(arr[i-1][0]>arr[i-1][2])
			arr[i][1] = g + arr[i-1][2];
		else
			arr[i][1] = g + arr[i-1][0];

		cin >> b;
		if(arr[i-1][0]>arr[i-1][1])
			arr[i][2] = b + arr[i-1][1];
		else
			arr[i][2] = b + arr[i-1][0];
	}

	int min = arr[n-1][0];

	if(min > arr[n-1][1])
		min = arr[n-1][1];

	if(min > arr[n-1][2])
		min = arr[n-1][2];

	cout << min;

	return 0;
}
