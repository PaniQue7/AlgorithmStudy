#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int num[1001];
	vector<int> sequence[1001];

	int cnt = 1;
	int temp;


	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> num[i];


	sequence[1].push_back(num[1]);

	for (int i = 2; i <= n; i++)
	{
		temp = cnt;
		while (temp != 0)
		{
			if (sequence[temp].back() < num[i])
				sequence[temp].push_back(num[i]);

			temp--;
		}

		temp = cnt;
		while (temp != 0)
		{
			if (sequence[temp].back() > num[i])
			{
				sequence[++cnt].push_back(num[i]);
				break;
			}
				
			temp--;
		}			
	}

	int maxIndex = 1;

	for (int i = 2; i <= cnt; i++)
	{
		if (sequence[i].size() > sequence[maxIndex].size())
			maxIndex = i;
	}

	cout << sequence[maxIndex].size() << endl;
	for (int i = 0; i < sequence[maxIndex].size(); i++)
	{
		if (i == sequence[maxIndex].size() - 1)
			cout << sequence[maxIndex].at(i);
		else
			cout << sequence[maxIndex].at(i) << " ";
	}
		


	return 0;
}
