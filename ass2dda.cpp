#include<iostream>
#include<GL/glut.h>
using namespace std;
int a,b,c,d;
void plotpixel(int a,int b){
   glBegin(GL_POINTS);
   glVertex2i(a,b);
   glEnd();
   glFlush();
}

void abc(){
   int dy=abs(d-b);
   int dx=abs(c-a);
   int m=dy/dx;

   while(a<c or b<d){
      if(m<1){
          a++;
          b=b+m;
      }
      else{
       b++;
        a=a+(1/m);
      }
      plotpixel(a,b);
   }

}

int main(int argc,char**argv){
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500,500);
   glutInitWindowPosition(100,100);

   glutCreateWindow("abc");

   gluOrtho2D(0,200,0,200);

   glClearColor(0.0,0.0,0.0,0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,0.0);

   cout<<"enter inpuuts";
   cin>>a>>b>>c>>d;

  glutDisplayFunc(abc);
  glutMainLoop();

}
