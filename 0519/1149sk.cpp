int a[1001][3];
int d[1001][3];


int mina(int a, int b, int c)
{
	return a > b ? (c > b ? b : c) : (a > c ? c : a);
}

int min(int a, int b)
{
	return a > b ? b : a;
}


int main(void)
{
	int num;

	d[0][0] = d[0][1] = d[0][2] = 0;

	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);


	for (int i = 1; i <= num; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
	}


	

	printf("%d", mina(d[num][0],d[num][1],d[num][2]));
}
