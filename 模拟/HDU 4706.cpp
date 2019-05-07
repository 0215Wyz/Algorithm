#include <iostream>

using namespace std;

char map[60][60];
char a[] = "abcdefghijklmnopqrstuvwxyz";

int main()
{
	int i, j, k;
	for (i = 0; i < 60; i++)
	{
		for (j = 0; j < 60; j++)
		{
			map[i][j] = ' ';
		}
	}
	int x = 1;//第一个下标
	int y = 1;//第二个下标
	int index = 0;
	int deadline = 3;
	for (i = 3; i <= 10; i++)
	{
		while (x < deadline)
		{
			map[x++][y] = a[(index++) % 26];
		}
		while (y < i)
		{
			map[x--][y++] = a[(index++) % 26];
		}
		while (x <= deadline)
		{
			map[x++][y] = a[(index++) % 26];
		}
		y = 1;
		deadline += (i + 1);
	}
	int col = 3;
	int cnt = 0;
	for (i = 1; i <= 52; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
		cnt++;
		if (cnt == col)
		{
			col++;
			cnt = 0;
		}
	}
	return 0;
}
