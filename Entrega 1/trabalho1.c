#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

void rotaciona(GLdouble theta,GLfloat x, GLfloat y, GLfloat z){

GLfloat coss,seno,normal;
float m[15];

coss = cos(theta);
seno = sin(theta);

normal = sqrt(pow(x,x)+pow(y,y)+pow(z,z));

if (normal < 1.0e-4) {
	x /= normal;
	z /= normal;
	y /= normal;
}

m[0]= pow(x,x)*(1-coss) + coss;
m[1] = (x*y)*(1-coss) - (z * seno);
m[2] = (x*z)*(1-coss) + (y * seno);
m[3] = 0;

m[4] = (y*x)*(1-coss) + (z * seno);
m[5] = pow(y,y)*(1-coss) + coss;
m[6] = (y*z)*(1-coss) - (x * seno);
m[7] = 0;

m[8] = (x*z)*(1-coss) - (y * seno);
m[9] = (y*z)*(1-coss) + (x * seno);
m[10] = pow(z,z)*(1-coss) + coss;
m[11] = 0;

m[12] = 0;
m[13] = 0;
m[14] = 0;
m[15] = 1;

glMultMatrixf(m);
}

void translacao(){
glPopMatrix();
}

void escala(){
glPopMatrix();
}


void init(){
glClearColor(0,0,0,0);
gluOrtho2D(-5,5,-5,5);
}

void display(){
GLdouble theta = 90;
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();

glColor3f(1,0,0);
glBegin(GL_POLYGON);
glVertex2f(-2,2);
glColor3f(0,1,0);
glVertex2f(-1,3);
glColor3f(0,0,1);
glVertex2f(0,2);
glColor3f(1,0,1);
glVertex2f(-0.5,0);
glColor3f(1,1,0);
glVertex2f(-1.5,0);


glEnd();

rotaciona(theta,0,0,1);
translacao();
escala();

glPopMatrix();
glFlush();
}

int main(int argc, char ** argv){
glutInit(&argc, argv);
glutInitWindowSize(600,400);
glutInitWindowPosition(10,50);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);    
glutCreateWindow("Transformacoes");
init();
glutDisplayFunc(display);
glutMainLoop();
}

