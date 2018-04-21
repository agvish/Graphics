/*Program to draw circle using "Midpoint Approach".*/

#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#define fx(x)(getmaxx() / 2 + x)
#define fy(y)(getmaxy() / 2 - y)

void drawCircle(int,int);                                               //Function declaration to plot pixels in each octant
int main()
{
    int radius,x,y,decsParam;
    printf("\nEnter the length of radius of circle. : ");
    scanf("%d",&radius);
    initwindow(640,480);
    x = 0;
    y = radius;
    decsParam = 1 - radius;                                             //Initial decision parameter.
    while(x<y)
    {
        drawCircle(x,y);                                                //Function call to plot pixel
        if(decsParam < 0)                                               //Eastern Pixel is chosen
            decsParam = decsParam + (2 * x) + 3  ;
        else                                                            //South Eastern pixel is chosen
        {
            y = (y - 1);
            decsParam = decsParam + (2 * x) - (2 * y) + 5;
        }
        x = x + 1;
        delay(20);
    }
    drawCircle(x,y);                                                    //Function call to plot last pixel
    getch();
    return 0;
}
    void drawCircle(int x,int y)                                        //Function definition to plot pixel in each octant
    {
        putpixel(fx(x),fy(y),11);
        putpixel(fx(y),fy(x),12);
        putpixel(fx(x),fy(-y),9);
        putpixel(fx(y),fy(-x),10);
        putpixel(fx(-x),fy(y),13);
        putpixel(fx(-y),fy(x),14);
        putpixel(fx(-x),fy(-y),12);
        putpixel(fx(-y),fy(-x),11);
    }
