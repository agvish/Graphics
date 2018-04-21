/*Program to draw an ellipse through mid point method and to decrease its size gradually.. The length of major and minor axis is given by user.*/

#include<stdio.h>
#include<graphics.h>
#include<math.h>

#define fx(x) (getmaxx()/2+x)
#define fy(y) (getmaxy()/2-y)


#define R(x) ((int)(x+0.5))

void ellipseMidPoint(int,int);                                          //Function declaration to generate coordinates of first quadrant to draw ellipse
void drawEllipse(int,int);                                              //Function declaration to plot pixel in each coordinate to draw ellipse

int main(void)
{
    int major,minor,a,b,i;
    printf("\nEnter the length of major axis : ");
    scanf("%d",&major);
    printf("\nEnter the length of minor axis : ");
    scanf("%d",&minor);

    if(major < 0 || minor < 0)
    {
        printf("\nLength can't be neagtive.");
        exit(1);
    }

    a = major;
    b = minor;
    i = 1;

    initwindow(1200,600);
    while(i < 100)
    {
        ellipseMidPoint(major,minor);                                   //Function call to draw ellipse
        major -= (i * 2);                                               //decreasing the length of major axis to decrease the size of ellipse
        minor -= (i * 2);                                               //decreasing the length of minor axis to decrease the size of ellipse
        if(major < 0 || minor < 0)                                      //Re-draw the ellipse of original health
        {
            major = a;
            minor = b;
            i = 1;
        }
        delay(600);
        cleardevice();                                                  //clear the screen
        i++;
    }

    getch();
    return 0;
}

void ellipseMidPoint(int a,int b)                                       //Function definition to generate coordinates of first quadrant to draw ellipse
{
     int x,y,d;
     x=0;                                                               //Initial x position
     y=b;                                                               //Initial y position
     d=R((b*b)-(a*a*b)+(0.25*a*a));                                     //Initial decision parameter
     while(R(((a*a)*(y-0.5)))>((b*b)*(x+1)))                            //Loop to generate coordinates in Region 1
     {
                drawEllipse(x,y);
                if(d<0)
                       d=d+((b*b)*((2*x)+3));
                else
                {
                    d=d+((b*b)*(2*x+3))+((a*a)*((-2*y)+3));
                    y=y-1;
                }
                x=x+1;
     }
     d=R((((b*b)*((x+0.5)*(x+0.5)))+((a*a)*((y-1)*(y-1)))-((a*a)*(b*b))));
     while(y>0)                                                         //Loop to generate coordinates in Region 2
     {
               drawEllipse(x,y);
               if(d<0)
               {
                      d=d+((b*b)*(2*x+2))+((a*a)*(((-2)*y)+3));
                      x=x+1;
               }
               else
                   d=d+((a*a)*(((-2)*y)+3));
               y=y-1;
     }

    drawEllipse(x,y);
    setfillstyle(SOLID_FILL,RED);                                       //set fill style to solid red
    floodfill(fx(0),fy(0),11);                                          //fills the ellipse
}

void drawEllipse(int x,int y)                                           //Function definition to plot pixel in each coordinate to draw ellipse
{
     putpixel(fx(x),fy(y),11);                                          //Plot pixel in 1st quadrant
     putpixel(fx(-x),fy(y),11);                                         //Plot pixel in 2nd quadrant
     putpixel(fx(-x),fy(-y),11);                                        //Plot pixel in 3rd quadrant
     putpixel(fx(x),fy(-y),11);                                         //Plot pixel in 4th quadrant
}
