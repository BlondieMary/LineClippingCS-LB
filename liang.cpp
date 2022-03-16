#include<stdio.h>
#include<GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>

double xmin=50, ymin=50, xmax=100,ymax=100; //oria parathurou
double xvmin=200,yvmin=200,xvmax=400, yvmax=400; //oria provolhs
float vx0,vx1,vy0,vy1;

int cliptest(double p,double q,double *t1,double *t2);

void liangbaraskylineclipanddraw(double x0,double y0,double x1,double y1)
{
    double dx= x1-x0,dy=y1-y0, te=0.0,tl=1.0;
      if(cliptest(-dx,x0-xmin,&te,&tl))
    if(cliptest(dx,xmax-x0,&te,&tl))
    if(cliptest(-dy,y0-ymin,&te,&tl))
    if(cliptest(dy,ymax-y0,&te,&tl))
    {
        if(tl<1.0)
        {
            x1=x0+tl*dx;
            y1=y0+tl*dy;
        }
        if(te>0.0)
        {
            x0=x0+te*dx;
            y0=y0+te*dy;
        }
    }
    //window to viewport mappings
    double sx= (xvmax-xvmin)/(xmax-xmin);// scale parameters
            double sy= (yvmax-yvmin)/(ymax-ymin);
            double vx0= xvmin+(x0-xmin)*sx;
            double vy0= yvmin+(y0-ymin)*sy;
            double vx1= xvmin+(x1-xmin)*sx;
            double vy1= yvmin+(y1-ymin)*sy;
// draw a red colored viewport
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(xvmin,yvmin);
        glVertex2f(xvmax,yvmin);
        glVertex2f(xvmax,yvmax);
        glVertex2f(xvmin,yvmax);
        glEnd();
        glColor3f(0.0,0.0,1.0); //draw blue colored clip line
        glBegin(GL_LINES);
        glVertex2d(vx0,vy0);
        glVertex2f(vx1,vy1);
        glEnd();

}
int cliptest(double p,double q,double *t1,double *t2)
{      // p paranomasths diaireshs and q arithmiths                 
// t1 einai h eisodos tou t kai t2 einai h eksodos tou t 
   
    double t=q/p;
    if(p<0.0)        //shmeio eisodou ,ananewsh te
    {    if(t>*t1) *t1=t;
        if(t>*t2) return(0); //to tmhma ths grammhs einai ekswteriko kathws h grammh no 2 t eiserxete
                                       // otan kseperasei to t (feugei)
    }
    else if(p>0.0) //shmeio eksodou ,ananewsh tl
        {
        if(t<*t2) *t2=t;
            if(t<*t1) return(0); //to tmhma ths grammhs einai ekswteriko
        }
        else if(p==0.0)
            { if(q<0.0)
                 return(0);//grammh pararilh me eksw me thn akmh alla ekswterikh
            }
            return(1);
}
void display()
{
    double x0,y0,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
           glColor3f(1,1,1);
	 glLineWidth(2);   //draw a line with red color
    
    srand(time(NULL));
     for(i=0; i<6; i++){
     	
     	x0 = (rand()%150 +1);
     	y0 = (rand()%150 +1);
     	x1 = (rand()%100 +1);
     	y1 = (rand()%100 +1);
		x2 = (rand()%150 +1);
     	y2 = (rand()%150 +1);
     	x3 = (rand()%100 +1);
     	y3 = (rand()%100 +1);
		x4 = (rand()%150 +1);
     	y4 = (rand()%150 +1);
     	x5 = (rand()%100 +1);
     	y5 = (rand()%100 +1);
		
     }
     	glBegin(GL_LINES);
          glVertex2d(x0,y0);
          glVertex2d(x1,y1);
          glVertex2d(x2,y2);
          glVertex2d(x3,y3);
          glVertex2d(x4,y4);
          glVertex2d(x5,y5);
          
    glEnd();
    glColor3f(1,1,1);     
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glEnd();
    
    glColor3f(1,1,1);
	 glBegin(GL_LINE_LOOP);
	 glVertex2f(xmin,ymin);
	 glVertex2f(xmax,ymin);
	 glVertex2f(xmax,ymax);
	 glVertex2f(xmin,ymax);
	 glEnd();
    liangbaraskylineclipanddraw(x0,y0,x1,y1);
    liangbaraskylineclipanddraw(x2,y2,x3,y3);
	liangbaraskylineclipanddraw(x4,y4,x5,y5);
	
    glFlush();
}
void myinit()
{    glClearColor(0,0,0,1);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

int main(int argc, char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("liang barsky line clipping algorithm");
    glutDisplayFunc(display);


    myinit();
    glutMainLoop();
    //return 0;
} 

