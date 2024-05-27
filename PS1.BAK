#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int x, y, x0, y0, x1, y1, dx, dy, k = 1, xinc, yinc, i, x2, y2;
float m, p, step;
void dda(int x0, int y0, int x1, int y1)
{
    dx = x1 - x0;
    dy = y1 - y0;
    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xinc = dx / step;
    yinc = dy / step;
    x = x0;
    y = y0;

    for (i = 0; i <= step; i++)
    {
	putpixel(x, y, WHITE);
	x = x + xinc;
	y = y + yinc;
    }
}


int main()
{
    int gdriver = DETECT, gmode;
    int ch;
    clrscr();
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
	printf("Enter the x0 coordinate:");
	scanf("%d", &x0);
	printf("Enter the y0 coordinate:");
	scanf("%d", &y0);
	printf("Enter the x1 coordinate:");
	scanf("%d", &x1);
	printf("Enter the y1 coordinate:");
	scanf("%d", &y1);
	dda(x0, y0, x1, y1);
    getch();
    closegraph();
    return 0;
}