#include<stdio.h>
#define N 100
int a[N + 1][N + 1] = {0};
int main()
{
	int ans = 0,la = 1,x = 0,k = 2;
	a[1][1] = 2;
	a[2][1] = 3;
	a[3][1] = 8;
	int i = 3;
	while (i < N)
	{
		++i;
		for (int j = 1;j <= la;++j)
		{
			a[i][j] = a[i - 1][j] + a[i - 2][j] + x;
			x = a[i][j] / 10;
			a[i][j] %= 10;
		}
		while (x > 0)
		{
			++la;
			a[i][la] = x % 10;
			x /= 10;
		}
		for (int j = la;j >= 1;--j)
			printf("%d",a[i][j]);
		printf("\n");
		if (i == N)
			break;

		++i;
		for (int j = 1;j <= la;++j)
		{
			a[i][j] = a[i - 1][j] + a[i - 2][j] + x;
			x = a[i][j] / 10;
			a[i][j] %= 10;
		}
		while (x > 0)
		{
			++la;
			a[i][la] = x % 10;
			x /= 10;
		}
		for (int j = la;j >= 1;--j)
			printf("%d",a[i][j]);
		printf("\n");
		if (i == N)
			break;

		++i;
		k += 2;
		for (int j = 1;j <= la;++j)
		{
			a[i][j] = a[i - 1][j] * k + x;
			x = a[i][j] / 10;
			a[i][j] %= 10;
		}
		while (x > 0)
		{
			++la;
			a[i][la] = x % 10;
			x /= 10;
		}
		for (int j = 1;j <= la;++j)
		{
			a[i][j] += a[i - 2][j] + x;
			x = a[i][j] / 10;
			a[i][j] %= 10;
		}
		while (x > 0)
		{
			++la;
			a[i][la] = x % 10;
			x /= 10;
		}
		for (int j = la;j >= 1;--j)
			printf("%d",a[i][j]);
		printf("\n");
		if (i == N)
			break;
	}
	for (int i = 1;i <= la;++i)
		ans += a[N][i];
	printf("%d\n",ans);
	return 0;
}
