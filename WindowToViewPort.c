#include<stdio.h>

#include<graphics.h>
#include<stdlib.h>
void main()
{
    float xwmin,xwmax,ywmax,ywmin;
    float xvmin,xvmax,yvmax,yvmin;
    float x[10],y[10],yv,xv,sx,sy;
    int gd=DETECT,gm,i;
    
    printf("\n*****WINDOW TO VIEW PORT MAPPING*****\n\n");
    printf("\n Enter Window port coordinates:\n(xwmin,ywmin) :");
    scanf("%f%f",&xwmin,&ywmin);
    printf("\n(xwmax,ywmax): ");
    scanf("%f%f",&xwmax,&ywmax);
    printf("\n enter view port coordinates:\n\n(xvmin,yvmin) :");
    scanf("%f%f",&xvmin,&yvmin);
    printf("\n(xvmax,yvmax): ");
    scanf("%f%f",&xvmax,&yvmax);
    printf("\n Enter vertices for a triangle : ");
    for(i=0;i < 3;i++)
    {
    	printf("\n (x%d,y%d):",i,i);
	scanf("%f%f",&x[i],&y[i]);
    }
    sx=((xvmax-xvmin)/(xwmax-xwmin));
    sy=((yvmax-yvmin)/(ywmax-xwmin));

    initgraph(&gd,&gm," ");
    setbkcolor(WHITE);
    setcolor(BLACK);
    outtextxy(80,30,"window port");
    rectangle(xwmin,ywmin,xwmax,ywmax);
    for(i=0;i <2;i++)
    {
    	line(x[i],y[i],x[i+1],y[i+1]);
    }
    line(x[2],y[2],x[0],y[0]);
    
    delay(2000);
    for(i=0;i <3;i++)
    {
    	x[i]=xvmin+((x[i]-xwmin)*sx);
    	y[i]=yvmin+((y[i]-ywmin)*sy);
    }
    outtextxy(xvmin,yvmin-15,"view port");
    rectangle(xvmin,yvmin,xvmax,yvmax);
    for(i=0;i <2;i++)
    {
    	line(x[i],y[i],x[i+1],y[i+1]);
    }
    line(x[2],y[2],x[0],y[0]);
    getch();
}
