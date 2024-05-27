#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

// Function to draw a line using Bresenham's Line Algorithm
void bresenham(int x1, int y1, int x2, int y2)
{
    int x, y, dx, dy, dx2, dy2, p, i;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    dx2 = 2 * dx;
    dy2 = 2 * dy;


    if (dx > dy)
    {
	p = dy2 - dx;
	x=x1;
	y=y1;
	putpixel(x, y, WHITE);
	for (i = 1; i <= dx; i++)
	{
	    if (p < 0)
	    {
		x ++;
		p = p + dy2;
	    }
	    else
	    {
		x ++;
		y ++;
		p = p + dy2 - dx2;
	    }
	    putpixel(x, y, WHITE);
	}
    }
    else
    {
	p = dx2 - dy;
	x=x1;
	y=y1;
	for (i = 0; i <= dy; i++)
	{
	    if (p < 0)
	    {
		y ++;
		p = p + dx2;
		putpixel(x, y, WHITE);
	    }
	    else
	    {
		x ++;
		y ++;
		p = p + dx2 - dy2;
		putpixel(x, y, WHITE);
	    }

	}
    }
}


// Function to draw a convex polygon


// Flood Fill Algorithm
void floodFill(int x, int y, int oldColor, int newColor) {
    if(getpixel(x,y)==oldColor){

    putpixel(x, y, newColor);

    floodFill(x + 1, y, oldColor, newColor);
    floodFill(x - 1, y, oldColor, newColor);
    floodFill(x, y + 1, oldColor, newColor);
    floodFill(x, y - 1, oldColor, newColor);
    floodFill(x+1,y+1,oldColor,newColor);
    floodFill(x+1,y-1,oldColor,newColor);
    floodFill(x-1,y-1,oldColor,newColor);
    floodFill(x-1,y+1,oldColor,newColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    bresenham(150,150,150,250);
    bresenham(150,150,350,150);
    bresenham(350,150,350,250);
    bresenham(150,250,350,250);

    floodFill(200,200,BLACK,RED);

    getch();
    closegraph();
    return 0;
}
