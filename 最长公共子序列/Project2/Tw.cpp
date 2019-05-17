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
using namespace std;

const int maxn = 100;//序列的最大长度为100

stack<char> st;
int la, lb;
string a, b;
int cnt;

struct node
{
	int x;
	int y;
	int dpdata;
};

node dp[maxn][maxn];


int main()
{
	int i, j;
	char a[1000];
	char b[1000];
	cin >> a >> b;
	la = strlen(a);
	lb = strlen(b);
	initgraph(1280, 680);
	memset(dp, 0, sizeof(dp));
	//填表
	for (i = 1; i <= la; i++)
	{
		for (j = 1; j <= lb; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j].dpdata = max(dp[i][j].dpdata, dp[i - 1][j - 1].dpdata + 1);
			}
			else
			{
				dp[i][j].dpdata = max(dp[i - 1][j].dpdata, dp[i][j - 1].dpdata);
			}
			dp[i][j].y = 100 + 50 * i;//向下
			dp[i][j].x = 300 + 50 * j;//向右
			rectangle(dp[i][j].x - 25, dp[i][j].y - 25, dp[i][j].x + 25, dp[i][j].y + 25);

		}
	}
	//填字符串a

	for (i = 1; i <= la; i++)
	{
		if (i == 1)
		{
			outtextxy(dp[1][1].x - 70, dp[i][1].y, "la");
		}
		outtextxy(dp[i][1].x - 50, dp[i][1].y, a[i - 1]);
	}
	//填字符串b
	for (i = 1; i <= lb; i++)
	{
		Sleep(100);
		if (i == 1)
		{
			outtextxy(dp[1][1].x, dp[i][1].y - 70, "lb");
		}
		outtextxy(dp[1][i].x, dp[1][i].y - 50, b[i - 1]);
	}
	for (i = 1; i <= la; i++)
	{
		for (j = 1; j <= lb; j++)
		{
			Sleep(100);
			char str[10];
			sprintf_s(str, "%d", dp[i][j].dpdata);
			outtextxy(dp[i][j].x, dp[i][j].y, str);
		}
	}
	//输出最长子序列的长度
	setlinecolor(GREEN);
	setbkcolor(WHITE);
	settextcolor(RED);
	i = la;
	j = lb;
	char ans[100];
	int num = 0;
	while (i >= 1 && j >= 1)
	{
		if (a[i - 1] == b[j - 1])
		{
			Sleep(100);
			fillrectangle(dp[i][j].x - 25, dp[i][j].y - 25, dp[i][j].x + 25, dp[i][j].y + 25);
			rectangle(dp[i][j].x - 25, dp[i][j].y - 25, dp[i][j].x + 25, dp[i][j].y + 25);
			char str[10];
			sprintf_s(str, "%d", dp[i][j].dpdata);
			outtextxy(dp[i][j].x, dp[i][j].y, str);
			ans[num++] = a[i - 1];
			i--;
			j--;
			
		}
		else
		{
			Sleep(100);
			if (dp[i - 1][j].dpdata >= dp[i][j - 1].dpdata)//相同的时候选上方的那一个
			{
				i--;
			}
			else
			{
				j--;
			}
		}
		if (i != 0 && j != 0)
		{
			rectangle(dp[i][j].x - 25, dp[i][j].y - 25, dp[i][j].x + 25, dp[i][j].y + 25);
		}
	}
	_getch();
	closegraph();

	return 0;
}