#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    int temp;

    if (x0 > x1) {
        temp = x0;
        x0 = x1;
        x1 = temp;

        temp = y0;
        y0 = y1;
        y1 = temp;
    }

    int x = x0;
    int y = y0;

    int a = y1 - y0;
    int b = x0 - x1;

    // octants 1, 5
    if (a > 0 && a <= -b) {
        // printf("(%d, %d) to (%d, %d)\n", x0, y0, x1, y1);
        int d = 2 * a + b;

        a *= 2;
        b *= 2;

        while (x < x1) {
            plot(s, c, x, y);
            if (d > 0) {
                y++;
                d += b;
            }
            x++;
            d += a;
        }
    }

    // octants 2, 6
    else if (a > -b) {

        int d = a + 2 * b;

        a *= 2;
        b *= 2;

        while (y < y1) {
            plot(s, c, x, y);
            if (d < 0) {
                x++;
                d += a;
            }
            y++;
            d += b;
        }
    }

    // octants 3, 7
    else if (a < b) {

        int d = a + -2 * b;

        a *= 2;
        b *= 2;

        while (y > y1) {
            plot(s, c, x, y);
            if (d > 0) {

                x++;
                d += a;
            }
            y--;
            d -= b;
        }
    }

    // octants 4, 8
    else {

        int d = 2 * a - b;

        a *= 2;
        b *= 2;

        while (x < x1) {
            plot(s, c, x, y);
            if (d < 0) {
                y--;
                d -= b;
            }
            x++;
            d += a;
        }
    }
}
