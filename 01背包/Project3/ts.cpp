#pragma warning(disable:4996)

#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>


typedef long long ll;
using namespace std;

const int maxn = 1000;
int a[maxn];//dfs的下标数组，二进制表示
int weight[maxn];//每一个物品的重量
int value[maxn];//每一个物品的价值
int n, full;//n表示物品的数量
int two[] = { 1,2,4,8,16,32,64,128 };//在画二叉树的时候使用

struct node
{
	int x;//在画布上的横坐标
	int y;//在画布上的纵坐标
	int i;//画图使用
};

node circleaddress[maxn * 2];

int flag_value; //flag_value 用来记录最大价值量
int flag_index; //flag_index 用来记录最大价值量的下标

int tot;
int num = 0;//数组地址的下标
int total_weight[maxn];//每一种选法的总重量
int total_value[maxn];//每一种选法的总价值

void draw(int i)
{
	setlinecolor(WHITE);
	circle(circleaddress[i].x, circleaddress[i].y, 5);
	if (circleaddress[i].i != 0)
	{
		outtextxy(circleaddress[i].x, circleaddress[i].y - 25, circleaddress[i].i + 48);
	}
	if (circleaddress[i].i != n)
	{
		line(circleaddress[i].x - 5, circleaddress[i].y + 5, circleaddress[2 * i + 1].x + 5, circleaddress[2 * i + 1].y - 5);
		outtextxy((circleaddress[i].x + circleaddress[2 * i + 1].x) / 2 - 15, (circleaddress[i].y + circleaddress[2 * i + 1].y) / 2 - 15, "YES");
		line(circleaddress[i].x + 5, circleaddress[i].y + 5, circleaddress[2 * i + 2].x - 5, circleaddress[2 * i + 2].y - 5);
		outtextxy((circleaddress[i].x + circleaddress[2 * i + 2].x) / 2 - 10, (circleaddress[i].y + circleaddress[2 * i + 2].y) / 2 - 10, "NO");
	}
}

int flag = 0;

void dfs(int index, int pos)
{
	int i;
	if (index >= 63)
	{
		return;
	}
	if (circleaddress[index].i == n)
	{
		for (i = 0; i < n; i++)
		{
			total_weight[tot] += (a[i] * weight[i]);
			total_value[tot] += (a[i] * value[i]);
		}
		char total_value1[30];
		char total_weight1[30];
		if (flag == 0)
		{
			outtextxy(circleaddress[index].x-66, circleaddress[index].y + 30, "Value");
			outtextxy(circleaddress[index].x-65, circleaddress[index].y + 60, "Weight");
			flag = 1;
		}
		sprintf(total_value1, "%d", total_value[tot]);
		sprintf(total_weight1, "%d", total_weight[tot]);
		outtextxy(circleaddress[index].x, circleaddress[index].y + 30, total_value1);
		outtextxy(circleaddress[index].x, circleaddress[index].y + 60, total_weight1);
		if (total_weight[tot] > full)
		{
			outtextxy(circleaddress[index].x, circleaddress[index].y + 90, "超重");
		}
		else
		{
			if (total_value[tot] > flag_value)
			{
				flag_value = total_value[tot];
				flag_index = index;
			}
		}
		tot++;

		return;

	}
	else
	{
		setlinecolor(YELLOW);
		Sleep(1000);
		line(circleaddress[index].x - 5, circleaddress[index].y + 5, circleaddress[2 * index + 1].x + 5, circleaddress[2 * index + 1].y - 5);
		index = 2 * index + 1;
		a[pos] = 1;
		dfs(index, pos + 1);
		index = (index - 1) / 2;
		Sleep(1000);
		setlinecolor(WHITE);
		line(circleaddress[index].x - 5, circleaddress[index].y + 5, circleaddress[2 * index + 1].x + 5, circleaddress[2 * index + 1].y - 5);
		Sleep(1000);
		setlinecolor(YELLOW);
		line(circleaddress[index].x + 5, circleaddress[index].y + 5, circleaddress[2 * index + 2].x - 5, circleaddress[2 * index + 2].y - 5);
		index = 2 * index + 2;
		a[pos] = 0;
		dfs(index, pos + 1);
		setlinecolor(WHITE);
		index = (index - 2) / 2;
		Sleep(1000);
		line(circleaddress[index].x + 5, circleaddress[index].y + 5, circleaddress[2 * index + 2].x - 5, circleaddress[2 * index + 2].y - 5);
	}
}

int main()
{
	cin.sync();
	int i, j, x;

	fill(total_value, total_value + maxn, 0);
	fill(total_weight, total_weight + maxn, 0);

	//输入物品的总数
	scanf("%d", &n);

	//输入背包的总承受量
	scanf("%d", &full);

	//输入每个物品的重量，价值
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &weight[i], &value[i]);
	}
	for (i = 0; i <= n; i++)
	{
		x = two[i] + 1;
		for (j = 1; j <= two[i]; j++)
		{
			circleaddress[num].x = 1280 * j / x;
			circleaddress[num].y = 80 * (i + 1);
			circleaddress[num].i = i;
			num++;
		}
	}

	//窗口大小
	initgraph(1280, 960);
	outtextxy(640, 60, "起始");
	outtextxy(30, 60, "因为窗口大小的原因，输入5（包括5）以上的影响显示效果");
	outtextxy(30, 80, "物品个数：");
	char N[30];
	sprintf(N, "%d", n);
	outtextxy(150, 80, N);
	outtextxy(30, 100, "背包总承受量：");
	sprintf(N, "%d", full);
	outtextxy(150, 100, N);
	//画树型图
	for (i = 0; i < num; i++)
	{
		draw(i);
	}

	tot = 0;
	flag_index = -1;
	flag_value = -1;
	dfs(0, 0);
	outtextxy(circleaddress[flag_index].x, circleaddress[flag_index].y + 120, "√");
	outtextxy(circleaddress[flag_index].x, circleaddress[flag_index].y + 150, "运行结束");
	_getch();
	closegraph();

	return 0;
}