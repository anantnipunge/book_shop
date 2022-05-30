#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
void symmetry(double xc, double yc, double x, double y)
{
 glBegin(GL_POINTS);
 glVertex2i(xc+x, yc+y);
 glVertex2i(xc+x, yc-y);
 glVertex2i(xc+y, yc+x);
 glVertex2i(xc+y, yc-x);
 glVertex2i(xc-x, yc-y);
 glVertex2i(xc-y, yc-x);
 glVertex2i(xc-x, yc+y);
 glVertex2i(xc-y, yc+x);
 glEnd();
}
void circle(double x1, double y2, double r)
{
 int x=0, y=r;
 float pk=(5.0/4.0)-r;
 //Plot the points
 symmetry(x1, y2, x, y); // Plot first point
 int k;
 while (x<y) //Find the vertices till x=y
 {
 x=x+1;
 if(pk<0)
 pk=pk+4*x+6;
 else
 {
 y=y-1;
 pk=pk+4*(x-y)+10;
 }
 symmetry(x1, y2, x, y);
 }
 glFlush();
}
void display()
 {
 circle(200, 200, 120);
 }
 
 void Init(void)
{
 glClearColor(1.0, 1.0, 1.0, 0.0);
 glColor3f(1, 1, 1);
 glPointSize(2.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
int main(int argc, char**argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(640, 480);
 glutInitWindowPosition(100, 150);
 glutCreateWindow("Circle");
 glutDisplayFunc(display);
 Init();
 glutMainLoop();
 return 0;
 }