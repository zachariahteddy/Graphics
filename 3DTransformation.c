#include<stdio.h>
#include<graphics.h> 
#include<math.h> 
int maxx,maxy,midx,midy,gd,gm;
int xd0,yd0,xd1,yd1,side,nxd0,nyd0,nxd1,nyd1,tx,ty,r;
float sc,width,nwidth,rd;
int x,y,z,rx1,ry1,rx2,ry2,c,no;
void display()
{
	initgraph(&gd,&gm,"../bgi");
	setbkcolor(WHITE);
	setcolor(BLACK);
	maxx=getmaxx(); 
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;
	bar3d(midx+xd0,midy-yd0,midx+xd0+side,midy-(yd0-side),width,10); 
	if(c==2)	
		bar3d(nxd0,nyd0,nxd1,nyd1,nwidth,10);
	else
		bar3d(nxd0,nyd0,nxd1,nyd1,width,10);			
        line(midx,0,midx,maxy);
        line(0,midy,maxx,midy); 
        delay(3000);
	closegraph();
           
}
void translation()
{
	 printf("\nEnter the Translation factor :\n(tx,ty) :"); 
         scanf("%d%d",&tx,&ty);
	 nxd0=midx+(xd0+tx);
	 nyd0=midy-(yd0+ty);
	 nxd1=midx+(xd0+side+tx);
	 nyd1=midy-((yd0-side)+ty);
	 display();
}
void scaling()
{
	printf("\nEnter the Scaling Factor :");
	scanf("%f",&sc);
	nxd0=midx+xd0+side+(xd0*sc);
	nyd0=midy-(yd0*sc);
	nxd1=midx+xd0+side+((xd0+side)*sc);
	nyd1=midy-((yd0-side)*sc);
	nwidth=width*sc;
	display();
}
void rotation()
{
	printf("Enter the Rotating angle :");
        scanf("%d",&r);
	rd=3.14*r/180;
	rx1=xd0*cos(rd)+yd0*sin(rd); 
        ry1=xd0*cos(rd)-yd0*sin(rd);
	rx2=(xd0+side)*sin(rd)-(yd0-side)*cos(rd);
	ry2=(xd0+side)*sin(rd)+(yd0-side)*cos(rd);

	/*printf("\n\nRotation about x-axis :\n\n");
	nxd0=midx+xd0;
	nyd0=midy-rx1;
	nxd1=midx+xd0+side;
	nyd1=midy-rx2;
	display();*/
	
	printf("\n\nRotation about y-axis :\n\n");
	nxd0=midx+rx1;
	nyd0=midy-yd0;
	nxd1=midx+rx2;
	nyd1=midy-(yd0-side);
	display();
		
	/*printf("\n\nRotation about z-axis :\n\n");
	nxd0=midx+rx1;
	nyd0=midy-ry1;
	nxd1=midx+rx2;
	nyd1=midy-ry2;
	display();*/
}

main()
{
	printf("\n\n*****3D-TRANSFORMATION*****\n");
	printf("\nEnter the Starting Cordinates and side of a Cube (w.r.t origin of Coordinate system): \n");
	printf("(x0,y0) :");
	scanf("%d%d",&xd0,&yd0);
	printf("\nSide :");
	scanf("%d",&side);
	width=side*.6;
	printf("\n\nOriginal Image:\n\n");
	initgraph(&gd,&gm,"../bgi");
	setbkcolor(WHITE);
	setcolor(BLACK);
	maxx=getmaxx(); 
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;
	outtextxy(50,50,"Original Figure");
	bar3d(midx+xd0,midy-yd0,midx+xd0+side,midy-(yd0-side),width,10); 	
	 
        line(midx,0,midx,maxy);
        line(0,midy,maxx,midy); 
	delay(2000);
	closegraph();
	do
	{ 
		printf("-----MENU-----");
	        printf("\n 1.TRANSLATION \n 2.SCALING \n 3.ROTATION \n 4.EXIT");
        	printf("\nEnter your choice :");
         	scanf("%d",&c);
         	switch(c)
         	{ 
                        case 1: 
			      translation();
			      break;
		        case 2: 
                	      scaling();
			      break;
                        case 3: 
			      rotation();
			      break;
                        case 4:
			      exit(0);      
      		}
      		printf("\n\nIf u want to continue enter 1 & to EXIT press 0:"); 
        	scanf("%d",&no); 
        }while(no==1);
         getch(); 
         closegraph(); 
}
