#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int n;
char m[65][65];
char num;

void quad(int i, int j, int size);
bool isSame(int i, int j, int size);

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		scanf("%s", m[i]);

	quad(0, 0, n);

	return 0;
}


void quad(int i, int j,int size)
{
	if (isSame(i, j, size))
	{
		printf("%c", num);
		return;
	}

	else
	{
		printf("(");
		quad(i, j, size / 2);
		quad(i, j + size / 2, size / 2);
		quad(i + size / 2, j, size / 2);
		quad(i + size / 2, j + size / 2, size / 2);
		printf(")");
	}
}

bool isSame(int i, int j, int size)
{
	char before = m[i][j];
	num = before;
	for (int a = i; a < i + size; a++)
		for (int b = j; b < j + size; b++)
			if (m[a][b] != before)
				return false;

	return true;
}
