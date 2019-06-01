#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <string>
#include <stack>
#include <cstdio>

using namespace std;

int n, m;//n�У�m��
int k;//�ϰ��������
int flag;//��ǣ����Ƿ�dfs���յ�
int xx[4] = { 1,0,-1,0 };
int yy[4] = { 0,1,0,-1 };

const int maxn = 65;

struct point
{
	int x;
	int y;
	int flag;//�˱���жϸ������ǲ����ϰ���
	point()
	{
		x = 0;
		y = 0;
		flag = 0;
	}
};

point map[maxn][maxn];
int vis[maxn][maxn];

void init()
{
	int i;

	printf("��Ϊ��Ļ��С���ޣ�����<=30������<=60\n");
	
	printf("�������Թ���������");
	scanf("%d", &n);

	printf("�������Թ���������");
	scanf("%d", &m);

	printf("�������Թ����ϰ���ĸ�����");
	scanf("%d", &k);
	srand((unsigned)time(NULL));
	for (i = 0; i < k; i++)
	{
		int x, y;
		x = rand() % n + 1;
		y = rand() % m + 1;
		while ((x == 1 && y == 1) || (x == n && y == m))
		{
			x = rand() % n + 1;
			y = rand() % m + 1;
		}
		map[x][y].flag = 1;
	}
}


void init_draw()
{
	int i, j;

	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	//y�����£�x������
	//n�У�   m��
	settextcolor(BLACK);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			map[i][j].x = 20 + 20 * j;
			map[i][j].y = 20 + 20 * i;
			rectangle(map[i][j].x - 10, map[i][j].y - 10, map[i][j].x + 10, map[i][j].y + 10);
			if (map[i][j].flag)
			{
				line(map[i][j].x - 10, map[i][j].y - 10, map[i][j].x + 10, map[i][j].y + 10);
				line(map[i][j].x + 10, map[i][j].y - 10, map[i][j].x - 10, map[i][j].y + 10);
			}
		}
	}
	outtextxy(map[1][1].x - 20, map[1][1].y - 30, "start");
	outtextxy(map[n][m].x, map[n][m].y + 15, "end");
}

void dfs(int x,int y)
{
	setlinecolor(BLACK);
	vis[x][y] = 1;
	printf("%d %d\n", x, y);
	if (flag == 1)
		return;
	if (x > n || x<1 || y>m || y < 1)
		return;
	if (map[x][y].flag)
		return;
	if (x == n && y == m)
	{
		Sleep(100);
		setfillcolor(BLUE);
		fillrectangle(map[x][y].x - 10, map[x][y].y - 10, map[x][y].x + 10, map[x][y].y + 10);
		flag = 1;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + xx[i];
		int next_y = y + yy[i];
		if (!vis[next_x][next_y])
		{
			Sleep(100);
			setfillcolor(BLUE);
			fillrectangle(map[x][y].x - 10, map[x][y].y - 10, map[x][y].x + 10, map[x][y].y + 10);
			dfs(next_x, next_y);
			if (flag == 0)
			{
				setfillcolor(WHITE);
				fillrectangle(map[x][y].x - 10, map[x][y].y - 10, map[x][y].x + 10, map[x][y].y + 10);
			}
		}
	}
}

int main()
{
	clock_t start, finish;
	double totaltime;
	init();
	initgraph(1280, 680);
	init_draw();
	flag = 0;
	memset(vis, 0, sizeof(vis));
	start = clock();
	dfs(1,1);
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	//�ر�
	if (flag == 0)
	{
		outtextxy(map[n][m].x, map[n][m].y + 30, "no way");
	}
	else
	{
		char s[30];
		sprintf(s,"����ʱ��Ϊ%.3lf��",totaltime);
		outtextxy(map[n][m].x - 100, map[n][m].y + 30, s);
	}
	_getch();
	closegraph();
	return 0;
}

