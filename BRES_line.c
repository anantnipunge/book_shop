#include <GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
int sign(float arg)
{
if(arg<0)return -1;
else if(arg==0)return 0;
else return 1;
}
void Bre(int X1,int Y1,int X2,int Y2)
{
float dx=abs(X2-X1);
float dy=abs(Y2-Y1);
int s1,s2,exc,y,x,i;
float g,temp;

x=X1;
y=Y1;
s1=sign(X2-X1);
s2=sign(Y2-Y1);

glBegin(GL_POINTS);
if(dy>dx)
{
temp=dx;
dx=dy;
dy=temp;
exc=1;
}
else
{
exc=0;
}
g=2*dy-dx;
i=1;

while(i<=dx)
{
glVertex2d(x,y);
while(g>=0)
{
if(exc==1)
x=x+s1;
else
y=y+s2;
g=g-2*dx;
}
if(exc==1)
y=y+s2;
else
x=x+s1;
g=g+2*dy;
i++;
}
glEnd();
glFlush();
}

void display()
{

Bre(100,200,800,900);

}
void Init(void)
{ 
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(1,1,1);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,480.0);
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,150);
glutCreateWindow("Bresenham Line ");
glutDisplayFunc(display);
Init();
glutMainLoop();
return 0;
}