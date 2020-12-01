#include <GL/glut.h> 
#include <stdlib.h> 
#include<math.h>

//Translacao
#define tx 1
#define ty 2

//Escala
#define sx 2
#define sy 2

//Angulo
#define ang 45

//Pontos do poligono
GLfloat Px1 = 1,Py1 = 1;
GLfloat Px2 = 1,Py2 = 3;
GLfloat Px3 = 2,Py3 = 3;
GLfloat Px4 = 2,Py4 = 1;

//Assinatura das funcoes
void normal(void);
void translacao(void);
void escala(void);
void rotacao(void);

int main(int argc, char** argv){ 
	//Inicializacao
	glutInit(&argc, argv);
	
	//Desenho normal
	glutInitWindowSize (300, 300); 
	glutInitWindowPosition(50, 200); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);    
	glutCreateWindow("Transformacoes");
	glClearColor(1,1,1,0); //Seta cor de fundo branca
	gluOrtho2D(-5,10,-5,10);//Eixos
	glutDisplayFunc(normal);
	
	//Desenho transladado
	glutInitWindowSize (300, 300); 
	glutInitWindowPosition(375, 200); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);    
	glutCreateWindow("Translacao");
	glClearColor(1,1,1,0); //Seta cor de fundo branca
	gluOrtho2D(-5,10,-5,10);//Eixos
	glutDisplayFunc(translacao);
	
	//Desenho escalado
	glutInitWindowSize (300, 300); 
	glutInitWindowPosition(700, 200); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);    
	glutCreateWindow("Escala");
	glClearColor(1,1,1,0); //Seta cor de fundo branca
	gluOrtho2D(-5,10,-5,10);//Eixos
	glutDisplayFunc(escala);
	
	//Desenho rotacionado
	glutInitWindowSize (300, 300); 
	glutInitWindowPosition(1025, 200); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);    
	glutCreateWindow("Rotacao");
	glClearColor(1,1,1,0); //Seta cor de fundo branca
	gluOrtho2D(-5,10,-5,10);//Eixos
	glutDisplayFunc(rotacao);
	
	glutMainLoop();
	
	return 0; 
} 

void rotacao(void){
	glClear(GL_COLOR_BUFFER_BIT); 
	
	//Eixo x
	glColor3f( 1 , 0 , 0 ); 
	glBegin(GL_LINES); 
	glVertex2f( 0.0 , 0.0 ); 
	glVertex2f( 10 , 0.0 ); 
	glEnd(); 
	
	// eixo y
	glColor3f( 1 , 0 , 0 ); 
	glBegin(GL_LINES); 
	glVertex2f( 0.0 , 0.0 ); 
	glVertex2f( 0.0 , 10); 
	glEnd(); 
	
	//Desenho rotacionado
	glColor3f (0.0, 0.0, 0.0); 
	glBegin(GL_POLYGON); 
	glVertex2f(Px1 * cos(ang) - Py1 * sin(ang), Px1 * sin(ang) + Py1 * cos(ang)); 
	glVertex2f(Px2 * cos(ang) - Py2 * sin(ang), Px2 * sin(ang) + Py2 * cos(ang)); 
	glVertex2f(Px3 * cos(ang) - Py3 * sin(ang), Px3 * sin(ang) + Py3 * cos(ang)); 
	glVertex2f(Px4 * cos(ang) - Py4 * sin(ang), Px4 * sin(ang) + Py4 * cos(ang)); 
	glEnd(); 
	glFlush();	
	
}

void escala(void){
	glClear(GL_COLOR_BUFFER_BIT); 
	
	//Eixo x
	glColor3f( 1 , 0 , 0 ); 
	glBegin(GL_LINES); 
	glVertex2f( 0.0 , 0.0 ); 
	glVertex2f( 10 , 0.0 ); 
	glEnd(); 
	
	// eixo y
	glColor3f( 1 , 0 , 0 ); 
	glBegin(GL_LINES); 
	glVertex2f( 0.0 , 0.0 ); 
	glVertex2f( 0.0 , 10); 
	glEnd(); 
	
	//Desenho escalonado
	glColor3f (0.0, 0.0, 0.0); 
	glBegin(GL_POLYGON); 
	glVertex2f(Px1 * sx, Py1 * sy); 
	glVertex2f(Px2 * sx, Py2 * sy); 
	glVertex2f(Px3 * sx, Py3 * sy); 
	glVertex2f(Px4 * sx, Py4 * sy); 
	glEnd(); 
	glFlush();	
	
}

void translacao(void){
	glClear(GL_COLOR_BUFFER_BIT); 
	
	//Eixo x
	glColor3f( 1 , 0 , 0 ); 
	glBegin(GL_LINES); 
	glVertex2f( 0.0 , 0.0 ); 
	glVertex2f( 10 , 0.0 ); 
	glEnd(); 
	
	// eixo y
	glColor3f( 1 , 0 , 0 ); 
	glBegin(GL_LINES); 
	glVertex2f( 0.0 , 0.0 ); 
	glVertex2f( 0.0 , 10); 
	glEnd(); 
	
	//Desenho transladado
	glColor3f (0.0, 0.0, 0.0); 
	glBegin(GL_POLYGON); 
	glVertex2f(Px1 + tx, Py1 + ty); 
	glVertex2f(Px2 + tx, Py2 + ty); 
	glVertex2f(Px3 + tx, Py3 + ty); 
	glVertex2f(Px4 + tx, Py4 + ty); 
	glEnd(); 
	glFlush();		
}

void normal(void){
	glClear(GL_COLOR_BUFFER_BIT); 
	
	//Eixo x
	glColor3f( 1 , 0 , 0 ); 
	glBegin(GL_LINES); 
	glVertex2f( 0.0 , 0.0 ); 
	glVertex2f( 10 , 0.0 ); 
	glEnd(); 
	
	// eixo y
	glColor3f( 1 , 0 , 0 ); 
	glBegin(GL_LINES); 
	glVertex2f( 0.0 , 0.0 ); 
	glVertex2f( 0.0 , 10); 
	glEnd(); 
	
	//Desenho normal
	glColor3f (0.0, 0.0, 0.0); 
	glBegin(GL_POLYGON); 
	glVertex2f(Px1, Py1); 
	glVertex2f(Px2, Py2); 
	glVertex2f(Px3, Py3); 
	glVertex2f(Px4, Py4); 
	glEnd(); 
	glFlush();	
	
}
