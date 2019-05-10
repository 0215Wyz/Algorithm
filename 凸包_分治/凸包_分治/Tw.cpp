#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <time.h>

using namespace std;

const int N = 1000;//���1000����
int n;

struct point
{
	int x;
	int y;
};

vector<point> v;//��͹���ϵĵ������˳��洢
point p[N];//������¼���е������
point ans[N];//������¼͹���ϵĵ������
int vis[N];//visΪ1�ĵ����͹���ϵĵ�
int mark[N];

//����ֵ����������Χ�ɵ������ε����������
//�����a,b,c��˳��Ϊ˳ʱ�룬��ú����ķ���ֵΪ��
int computersize(point a, point b, point c)
{
	return a.x*b.y + c.x*a.y + b.x*c.y - c.x*b.y - b.x*a.y - a.x*c.y;
}

//�����еĵ㰴�պ������������
bool cmp(point a, point b)
{
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

//�÷��η��������
void Deal(int first, int last)
{
	setlinecolor(BLACK);
	line(p[first].x, p[first].y, p[last].x, p[last].y);
	int maxx = 0, index = -1;
	int i;
	if (first < last)
	{
		for (i = first + 1; i < last; i++)
		{
			int doublesize = computersize(p[first], p[i], p[last]);
			if (doublesize == 0)
				vis[i] = 1;
			if (doublesize > maxx)
			{
				maxx = doublesize;
				index = i;
			}
		}
	}
	else
	{
		for (i = first - 1; i > last; i--)
		{
			int doublesize = computersize(p[first], p[i], p[last]);
			if (doublesize == 0)
				vis[i] = 1;
			if (doublesize > maxx)
			{
				maxx = doublesize;
				index = i;
			}
		}
	}

	if (index != -1)
	{
		Sleep(500);
		setlinecolor(BLACK);
		line(p[first].x, p[first].y, p[index].x, p[index].y);
		line(p[index].x, p[index].y, p[last].x, p[last].y);
		Sleep(500);
		setlinecolor(WHITE);
		line(p[first].x, p[first].y, p[last].x, p[last].y);
		vis[index] = 1;
		Deal(first, index);
		Deal(index, last);
	}
}

int main()
{
	int i;
	cin >> n;
	//��ʼ�����ڴ�С�����ñ�����ɫ
	initgraph(1280, 680);
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(BLACK);

	//��������������
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		p[i].x = rand() % 1000 + 10;
		p[i].y = rand() % 500 + 10;
		fillcircle(p[i].x, p[i].y, 3);
		vis[i] = 0;
	}
	//�����еĵ��������
	sort(p, p + n, cmp);

	//����ߵ��Լ����ұߵĵ㶼��͹���ϵĵ�
	vis[0] = 1;
	vis[n - 1] = 1;

	//������͹��������͹��
	Deal(0, n - 1);
	Deal(n - 1, 0);
	int t = 0;


	setlinecolor(RED);
	for (i = 0; i < n; i++)
	{
		if (vis[i])
		{
			ans[t].x = p[i].x;
			ans[t].y = p[i].y;
			t++;
		}
	}
	//˳ʱ�����
	fill(mark, mark + t, 0);
	mark[0] = mark[t - 1] = 1;
	v.push_back(ans[0]);
	setfillcolor(RED);
	Sleep(500);
	fillcircle(ans[0].x, ans[0].y, 3);
	for (i = 1; i < t - 1; i++)
	{
		int d = computersize(ans[0], ans[t - 1], ans[i]);//��͹���ĵ�
		if (d >= 0)
		{
			v.push_back(ans[i]);
			Sleep(500);
			fillcircle(ans[i].x, ans[i].y, 3);
			mark[i] = 1;
		}
	}
	v.push_back(ans[t - 1]);
	Sleep(500);
	fillcircle(ans[t - 1].x, ans[t - 1].y, 3);
	for (i = t - 2; i >= 1; i--)
	{
		if (!mark[i])
		{
			int d = computersize(ans[0], ans[t - 1], ans[i]);
			if (d <= 0)
			{
				Sleep(500);
				fillcircle(ans[i].x, ans[i].y, 3);
				v.push_back(ans[i]);
			}
		}
	}
	setlinecolor(RED);
	for (i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
		{
			line(v[i].x, v[i].y, v[0].x, v[0].y);
		}
		else
		{
			line(v[i].x, v[i].y, v[i + 1].x, v[i + 1].y);
		}
		Sleep(500);
	}
	settextcolor(BLACK);
	outtextxy(1000, 600, _T("OK"));
	_getch();
	closegraph();
	return 0;
}