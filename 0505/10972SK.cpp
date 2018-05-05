#include <iostream>
#include <algorithm>

using namespace std;
int num;
int input[10000];
int index, result;
int arr[10000];

int isLast()
{
	for (int i = 0; i < num; i++)
		if ((i + 1 != num) && (input[i] < input[i + 1]))
			return 0;

	return -1;
}


void sssort(int start, int val, int least)
{
	//start인덱스부터 num-1인덱스까지... val+1값을 val로 바꾸고 소트 진행
	for (int i = start; i <= num - 1; i++)
	{
		if (input[i] == least)
			input[i] = val;

		
	}
	//sort
	sort(input + start, input + num);
}

bool isIn(int a, int index)
{
	for (int i = index; i < num; i++)
		if (input[i] == a)
			return true;

	return false;
}

int getLeast(int start, int a)
{
	int min = input[start];
	for (int i = start; i < num; i++)
	{
		if (input[i] < min && input[i] > a)
			min = input[i];
	}
	return min;
}

int main(void)
{
	while (1)
	{
		cin >> num;

		for (int i = 0; i < num; i++)
			cin >> input[i];

		if ((result = isLast()) == -1)
		{
			printf("%d", result);
			return 0;
		}

		else
		{
			for (int i = 0; i < num; i++) {
				if ((i + 1 != num) && (input[i] < input[i + 1]))
					index = i;
			}
		}


		if (index == num - 2)
		{
			int temp = input[index];
			input[index] = input[index + 1];
			input[index + 1] = temp;
		}
		else
		{
			//index + 1의 위치의 값에 그 나머지 중에 가장 작은 값으로 변경하고, 기존 index+1의 값과 그 뒤의 값들을 오름차순으로 정렬한다
			int temp = input[index];
			//
			if (!isIn(input[index]+1, index+1))
			{
				//input[index]보다 큰 값들 중에서의 min

				input[index] = getLeast(index + 1, input[index]);
				sssort(index + 1, temp, input[index]);
			}
			
			else
			{
				input[index]++;
				sssort(index + 1, temp, input[index]);
			}
		}


		for (int i = 0; i < num; i++)
		{
			printf("%d", input[i]);
			if (i != num - 1)
				printf(" ");
		}

	}
	return 0;
}


