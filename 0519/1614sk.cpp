#include <iostream>

using namespace std;

int main(void)
{
	int finger;
	long long max;
	unsigned long long num;


		cin >> finger >> max;

		if (max >= 1)
		{
			max = max - 1;
			num = 5;
		}


		else
		{
			switch (finger)
			{
			case 1: num = 0;
				break;
			case 2: num = 1;
				break;
			case 3: num = 2;
				break;
			case 4: num = 3;
				break;
			case 5: num = 4;
				break;
			}

			printf("%lld", num);

			return 0;
		}

		if (finger != 1 && finger != 5)
		{
			num = num + max * 4;

			if (max % 2 == 1)
				switch (finger)
				{
				case 4: num = num + 2;
					break;

				case 3: num = num + 1;
					break;
				case 2: break;
				}

			else
				switch (finger)
				{
				case 4: break;

				case 3: num = num + 1;
					break;
				case 2: num = num + 2;
					break;
				}
		}
		else if (finger == 1)
			num = num + max * 8 + 3;

		else
		{
			if (max == 0)
				num = num + 7;
			else
				num = num + 7 + max * 8;
		}			

		printf("%lld", num);

	return 0;
}