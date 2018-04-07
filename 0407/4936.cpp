#include <iostream>

using namespace std;

int map[50][50];
int w, h, cnt;


bool InMap(int i, int j)
{
	if (i >= 0 && i < h)
		if (j >= 0 && j < w)
			return true;

	return false;
}

void dfs(int i, int j)
{

	map[i][j] = 0;


	if (InMap(i - 1, j) && map[i - 1][j] == 1)
		dfs(i-1, j);

	if (InMap(i + 1, j) && map[i + 1][j] == 1)
		dfs(i+1, j);

	if (InMap(i, j - 1) && map[i][j - 1] == 1)
		dfs(i, j-1);

	if (InMap(i, j + 1) && map[i][j + 1] == 1)
		dfs(i, j+1);

	if (InMap(i + 1, j + 1) && map[i + 1][j + 1] == 1)
		dfs(i+1, j+1);

	if (InMap(i + 1, j - 1) && map[i + 1][j - 1] == 1)
		dfs(i+1, j-1);

	if (InMap(i - 1, j + 1) && map[i - 1][j + 1] == 1)
		dfs(i-1, j+1);

	if (InMap(i - 1, j - 1) && map[i - 1][j - 1] == 1)
		dfs(i-1, j-1);

}


void Search()
{
	cnt = 0;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (map[i][j] == 1) 
			{
				dfs(i, j);
				cnt++;
			}
}

int main(void)
{
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];


		Search();

		printf("%d\n", cnt);
	}
	return 0;
}