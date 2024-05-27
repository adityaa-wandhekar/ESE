#include <graphics.h>
#include <conio.h>
#include <stdio.h>

typedef struct {
    int x, y;
} Point;

void drawLine(Point p1, Point p2) {
    int x, y, dx, dy, s1, s2, swap, temp, p, i;
    x = p1.x;
    y = p1.y;
    dx = abs(p2.x - p1.x);
    dy = abs(p2.y - p1.y);
    s1 = (p2.x > p1.x) ? 1 : -1;
    s2 = (p2.y > p1.y) ? 1 : -1;
    swap = 0;
    
    if(dy > dx) {
        temp = dx;
        dx = dy;
        dy = temp;
        swap = 1;
    }
    
    p = 2 * dy - dx;
    
    for(i = 0; i <= dx; i++) {
        putpixel(x, y, WHITE);
        while(p >= 0) {
            p = p - 2 * dx;
            if(swap)
                x += s1;
            else
                y += s2;
        }
        p = p + 2 * dy;
        if(swap)
            y += s2;
        else
            x += s1;
    }
}

void scanlineFill(Point p[], int n) {
    int i, j, k, y, temp, x_intersect[20];
    int ymax = 0, ymin = 480; // Assuming screen height is 480
    
    for(i = 0; i < n; i++) {
        if(p[i].y > ymax)
            ymax = p[i].y;
        if(p[i].y < ymin)
            ymin = p[i].y;
    }
    
    for(y = ymin; y <= ymax; y++) {
        k = 0;
        for(i = 0; i < n; i++) {
            j = (i + 1) % n;
            if((p[i].y < y && p[j].y >= y) || (p[j].y < y && p[i].y >= y)) {
                x_intersect[k] = p[i].x + (y - p[i].y) * (p[j].x - p[i].x) / (p[j].y - p[i].y);
                k++;
            }
        }
        
        for(i = 0; i < k - 1; i++) {
            for(j = 0; j < k - 1 - i; j++) {
                if(x_intersect[j] > x_intersect[j + 1]) {
                    temp = x_intersect[j];
                    x_intersect[j] = x_intersect[j + 1];
                    x_intersect[j + 1] = temp;
                }
            }
        }
        
        for(i = 0; i < k; i += 2) {
            for(j = x_intersect[i]; j <= x_intersect[i + 1]; j++) {
                putpixel(j, y, WHITE);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    Point polygon[] = {{150, 100}, {200, 50}, {250, 100}, {300, 150}, {250, 200}, {150, 200}};
    int n = sizeof(polygon) / sizeof(polygon[0]);
    
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    for(int i = 0; i < n; i++) {
        drawLine(polygon[i], polygon[(i + 1) % n]);
    }
    
    scanlineFill(polygon, n);
    
    getch();
    closegraph();
    return 0;
}