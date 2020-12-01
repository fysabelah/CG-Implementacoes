#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

void init()
{
	gluOrtho2D(0, 300, 0, 300);
}

typedef struct ponto{
	int x;
	int y;
} Ponto;

void desenharPixel(Ponto p){
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2i(p.x, p.y);
	glEnd();
	glFlush();
}

Ponto obterPontoInicial(int *x0, int *y0, int *x1, int *y1){
	Ponto p;
	
	if (*x0 > *x1){
		p.x = *x1;
		p.y = *y1;
		x1 = x0;
	}
	else{
		p.x = *x0;
		p.y = *y0;
	}
	
	return p;
}

void linhaBresenham(int x0, int y0, int x1, int y1){
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int duasVezesDy = 2 * dy;
	int duasVezesDyMenosDx = 2 * (dy - dx);
	int p = 2 * dy - dx;
	
	Ponto ponto = obterPontoInicial(&x0, &y0, &x1, &y1);

	desenharPixel(ponto);

	while (ponto.x < x1){
		ponto.x = ponto.x + 1;
		
		//E
		if (p < 0){	
			p += duasVezesDy;
		}

		//NE
		else{
			ponto.y = ponto.y + 1;
			p += duasVezesDyMenosDx;
		}

		desenharPixel(ponto);
	}
}


void Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	linhaBresenham(0, 0, 200, 200);
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Algoritmo de reta otimizada");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
