#include <iostream>

using namespace std;

int n;

//col[i]의 값은 i번째 열의 몇번째 행인지를 나타냄
int col[16] = { 0 };
int cnt = 0;


bool satisfy(int index)
{
	bool check = true;

	if (index == 1)
		return true;

	//index의 왼쪽 모든 말들과(index = 1부터 index = index-1 까지) 같은 행이 아님
	for (int i = 1; i <= index - 1; i++)
		if (col[i] == col[index] //index의 왼쪽 모든 말들과(index = 1부터 index = index-1 까지) 같은 행인가?
			|| col[index] == col[i] - (index - i) //왼쪽 말들과 같은 대각선에 위치한 말인가?
			|| col[index] == col[i] + (index - i)) //왼쪽 말들과 같은 대각선에 위치한 말인가?
		{
			check = false;
			break;
		}

	return check;
}



bool finished(int index)
{
	if (index == n && satisfy(index))
		return true;

	return false;
}



void nqueens(int index)
{
	col[index] = 0;

	for (int i = 0; i < n; i++)
	{
		//각 열의 행을 증가시킴
		col[index]++;

		if (finished(index))
			cnt++;
		
		else if (satisfy(index))
			nqueens(index + 1);
	}	
}

int main(void)
{
	scanf("%d", &n);
	nqueens(1);
	printf("%d", cnt);

	return 0;
}