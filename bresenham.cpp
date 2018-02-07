/*Program to implement Bresenham's Line Drawing Algorithm*/

#include<stdio.h>
#include<graphics.h>
#include<math.h>

typedef struct{
    int x;
    int y;
}P;
void bresenGentle(P,P,int,int,int);                                     /*Function prototype for drawing line*/
int main(void)
{
    P p1,p2;
    int dely = 0 , delx = 0 , delt , change = 0;

    printf("\nEnter the starting point of line.(x1,y1) : \n");
    scanf("%d%d",&p1.x,&p1.y);
    printf("Enter the ending point of line,(x2,y2) : \n");
    scanf("%d%d",&p2.x,&p2.y);

    initwindow(1366,768);
    circle(p1.x,p1.y,3);                                                /*Marking the starting and ending point*/
    circle(p2.x,p2.y,3);

    if((p1.x == p2.x) && (p1.y == p2.y))                                /*If the start and end points are same*/
         putpixel(p1.x,p1.y,15);
    else
    {
        dely = abs(p2.y - p1.y);                                        /*Absolute difference between the 'y' coordinates*/
        delx = abs(p2.x - p1.x);                                        /*Absolute difference between the 'x' coordinates*/
        if(dely > delx)                                                 /*If the slope is sharp we interchange the (x,y) coordinates as (y,x)*/
        {
            delt = dely;
            dely = delx;
            delx = delt;
            change = 1;
        }
        bresenGentle(p1,p2,dely,delx,change);                           /*Function call to draw a line*/
    }

    getch();
    closegraph();
}
void bresenGentle(P p1,P p2,int dely,int delx , int change)
{
    int x , y , xinc , yinc , par = 0 , steps = delx , xst = 0;
    x = p1.x;                                                           /*Marking the starting point*/
    y = p1.y;

    if(p1.x < p2.x)                                                     /*Changing the increment counter of x,y on the basis of start and end point*/
        xinc = 1;
    if(p1.y < p2.y)
        yinc = 1;
    if(p1.x > p2.x)
        xinc = -1;
    if(p1.y > p2.y)
        yinc = -1;

    par = 2*dely - delx;                                                /*Setting the initial decision parameter*/
    putpixel(x,y,15);                                                   /*Plotting the first point*/
    while(xst != steps)
    {
        if(par <= 0)
        {
            if(change == 0)                                             /*Check for sharp or gentle slope*/
                x = x+xinc;
            else
                y = y+yinc;
            putpixel(x,y,15);
            par = par + 2*dely;
            delay(10);                                                  /*For animation, wait of 10ms*/
        }
        else
        {
            x = x + xinc;
            y = y + yinc;
            putpixel(x,y,15);
            par = par + 2*dely - 2*delx;
            delay(10);
        }
        xst++;                                                         /*Increasing the steps counter*/
    }
    putpixel(x,y,15);                                                  /*Plotting the final point*/
}
