#include <GL/glut.h> 
#include <stdlib.h> 
#include<math.h>
#define tx 0.5
#define ty 0.5
#define ang 30
//x1 = 0.25 y1 = 0.25, x2 = 0.75,y2 = 0.25,x3 = 0.75, y3 = 0.95, x4 = 0.25, y4 = 0.95;

GLfloat pontos[3]= {0.15, 0.35, 0.55};

void normal(void);
void translacao(void);
void escala(void);
void rotacao(void);

int main(int argc, char** argv){ 
	//Normal
	glutInit(&argc, argv); 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (300, 300); 
	glutInitWindowPosition (100, 100); 
	glutCreateWindow ("Transformações"); 
	glClearColor(1.0, 1.0, 1.0, 0.0); 
	glShadeModel (GL_FLAT); 
	glOrtho (0, 1, 0, 1, -1 ,1); 
	glutDisplayFunc(normal); 
	
	//Translação
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (300, 300); 
	glutInitWindowPosition (250, 250); 
	glutCreateWindow ("Translação");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(translacao);
	
	//Escala
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (300, 300); 
	glutInitWindowPosition (350, 350); 
	glutCreateWindow ("Escala");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(escala);

	
	//Rotação
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (300, 300); 
	glutInitWindowPosition (450, 450); 
	glutCreateWindow ("ROtação");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(rotacao);
	

	glutMainLoop();	
	
	return 0; 
} 

void rotacao(void){
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f (0.0, 0.0, 0.0); 
	glBegin(GL_POLYGON); 
	glVertex2f(pontos[0] * cos(ang) - pontos[0] * sin(ang), pontos[0] * sin(ang) + pontos[0] * cos(ang)); 
	glVertex2f(pontos[1] * cos(ang) - pontos[0] * sin(ang), pontos[1] * sin(ang) + pontos[0] * cos(ang)); 
	glVertex2f(pontos[1] * cos(ang) - pontos[2] * sin(ang), pontos[1] * sin(ang) + pontos[2] * cos(ang)); 
	glVertex2f(pontos[0] * cos(ang) - pontos[2] * sin(ang), pontos[0] * sin(ang) + pontos[2] * cos(ang)); 
	glEnd(); 
	glFlush();	
	
}

void escala(void){
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f (0.0, 0.0, 0.0); 
	glBegin(GL_POLYGON); 
	glVertex2f(pontos[0] * tx, pontos[0] * ty); 
	glVertex2f(pontos[1] * tx, pontos[0] * ty); 
	glVertex2f(pontos[1] * tx, pontos[2] * ty); 
	glVertex2f(pontos[0] * tx, pontos[2] * ty); 
	glEnd(); 
	glFlush();	
	
}

void translacao(void){
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f (0.0, 0.0, 0.0); 
	glBegin(GL_POLYGON); 
	glVertex2f(pontos[0] + tx, pontos[0] + ty); 
	glVertex2f(pontos[1] + tx, pontos[0] + ty); 
	glVertex2f(pontos[1] + tx, pontos[2] + ty); 
	glVertex2f(pontos[0] + tx, pontos[2] + ty); 
	glEnd(); 
	glFlush();		
}

void normal(void){
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f (0.0, 0.0, 0.0); 
	glBegin(GL_POLYGON); 
	glVertex2f(pontos[0], pontos[0]); 
	glVertex2f(pontos[1], pontos[0]); 
	glVertex2f(pontos[1], pontos[2]); 
	glVertex2f(pontos[0], pontos[2]); 
	glEnd(); 
	glFlush();	
	
}
