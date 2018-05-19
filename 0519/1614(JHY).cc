#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	long long finger, count;
	cin >> finger >> count;

	//1,2,3,4,5,4,3,2 반복
	
	 long long result;

	if(finger==1)
		result = 8 * count;
    
	else if(finger==5)
		result = 8 * count + 4;

	else
	{
		long long tmp = (count+1)/2;
		
        if(count%2!=0)
			result =  8 * tmp - (finger-1);

		else if(count%2==0)
			result =  8 * tmp + (finger-1);
	}

	cout << result;
	return 0;
}
