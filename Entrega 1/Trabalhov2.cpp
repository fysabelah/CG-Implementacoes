#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include <iostream>

using namespace std;

typedef GLfloat Matrix3x3[3][3];
Matrix3x3 CachedTransformationMatrix;

//Essa função define seta a matriz do paramêtro para ser a matrix identidade
void SetIdMatrix(Matrix3x3 MatrixToSet)
{
	for(int i = 0;i < 3;i ++)
		for(int j = 0;j < 3;j ++)
			MatrixToSet[i][j] = (i == j) ? 1 : 0;
}

//Ao criar o vertice, pegamos o vértice final a partir da matriz de transformações(CachedTransformationMatrix)
//Temos:
/*
VerticesFinais        CachedMatrix 	     VerticesPassados
|realVerX|			|- - -|     			|verX|
|realVerY|  =		|- - -|  	x  			|verY|
|z|					|- - -|     			|  1 |
*/
void CriarVertice(GLfloat verX, GLfloat verY)
{
	GLfloat realVerX, realVerY;//Vértices que iremos aplicar no glVertex3f();
	
	//Pelo esquema acima(multiplicação de matrizes):
	realVerX = CachedTransformationMatrix[0][0] * verX + CachedTransformationMatrix[0][1] * verY + CachedTransformationMatrix[0][2] * 1;
	realVerY = CachedTransformationMatrix[1][0] * verX + CachedTransformationMatrix[1][1] * verY + CachedTransformationMatrix[1][2] * 1;
	
	//Criando o vértice
	glVertex3f(realVerX,realVerY,0);
}

/*
Na função de translação setamos a "CachedTransformationMatrix" para ser:
	|1 0 dx|
	|0 1 dy|
	|0 0 1 |
*/
void Transladar2D(GLfloat dx, GLfloat dy)
{
	SetIdMatrix(CachedTransformationMatrix);//Settando/resetando a matriz para ser identidade

	//Construindo a matriz de transformação da translação
	CachedTransformationMatrix[0][2] = dx; 
	CachedTransformationMatrix[1][2] = dy; 
}

/*
Na função de escala setamos a "CachedTransformationMatrix" para ser:
	|sx 0 0|
	|0 sy 0|
	|0 0  1|
*/
void Escalar2D(GLfloat sx, GLfloat sy)
{
	SetIdMatrix(CachedTransformationMatrix);//Settando/resetando a matriz para ser identidade

	//Construindo a matriz de transformação da escala
	CachedTransformationMatrix[0][0] = sx; 
	CachedTransformationMatrix[1][1] = sy; 
}

/*
Na função de rotação setamos a "CachedTransformationMatrix" para ser:
	|cos(theta) -sin(theta) 0|
	|sin(theta) cos(theta) 0|
	|0 0  1|
*/
void Rotacionar2D(GLfloat Theta)
{
	SetIdMatrix(CachedTransformationMatrix);//Settando/resetando a matriz para ser identidade

	//Construindo a matriz de transformação da rotação
	CachedTransformationMatrix [0][0] = cos(Theta); 
	CachedTransformationMatrix [0][1] = -sin(Theta); 
	CachedTransformationMatrix [0][2] = 0; 
	CachedTransformationMatrix [1][0] = sin(Theta); 
	CachedTransformationMatrix [1][1] = cos(Theta); 
	CachedTransformationMatrix [1][2] = 0;
}

//Função init
void init(){
	glClearColor(0,0,0,0); //Seta cor de fundo preta
	gluOrtho2D(-5,5,-5,5);
}

//================================================FUNÇÕES DE TESTE===============================================
void TestaTranslacao(){
	//Triangulo sem translação
	glBegin(GL_TRIANGLES);
	
	glColor3f(0,1,0);
	CriarVertice(-2,2);
	
	glColor3f(0,0,1);
	CriarVertice(-1,3);

	glColor3f(1,0,1);
	CriarVertice(0,2);
	
	glEnd();
	
	
	//Triangulo transladado
	glBegin(GL_TRIANGLES);
	
	Transladar2D(2,2);//Chamando translação
	
	glColor3f(0,1,0);
	CriarVertice(-2,2);
	
	glColor3f(0,0,1);
	CriarVertice(-1,3);

	glColor3f(1,0,1);
	CriarVertice(0,2);
	
	glEnd();


	glFlush();
}

void TestaEscala(){
	//Triangulo sem escala
	glBegin(GL_TRIANGLES);
	
	glColor3f(0,1,0);
	CriarVertice(-2,2);
	
	glColor3f(0,0,1);
	CriarVertice(-1,3);

	glColor3f(1,0,1);
	CriarVertice(0,2);
	
	glEnd();
	
	
	//Triangulo escalado
	glBegin(GL_TRIANGLES);
	
	Escalar2D(2,2);//Chamando escala
	
	glColor3f(0,1,0);
	CriarVertice(-2,2);
	
	glColor3f(0,0,1);
	CriarVertice(-1,3);

	glColor3f(1,0,1);
	CriarVertice(0,2);
	
	glEnd();


	glFlush();
}

void TestaRotacao(){
	GLdouble theta = 90; //Declaração de theta(O ângulo que queremos rotacionar)
	
	//Triangulo sem rotação
	glBegin(GL_TRIANGLES);
	
	glColor3f(0,1,0);
	CriarVertice(-2,2);
	
	glColor3f(0,0,1);
	CriarVertice(-1,3);

	glColor3f(1,0,1);
	CriarVertice(0,2);
	
	glEnd();
	
	
	//Triangulo rotacionado
	glBegin(GL_TRIANGLES);
	
	Rotacionar2D(theta);//Chamando rotação
	
	glColor3f(0,1,0);
	CriarVertice(-2,2);
	
	glColor3f(0,0,1);
	CriarVertice(-1,3);

	glColor3f(1,0,1);
	CriarVertice(0,2);
	
	glEnd();


	glFlush();
}

//================================================FIM FUNÇÕES DE TESTE==============================================

//DISPLAY
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	SetIdMatrix(CachedTransformationMatrix);//Seta a matriz para ser identidade(Não podemos usar ela com todos valores = 0)
	
	//Eixo x
	glColor3f( 1 , 0 , 0 ); 
	glBegin(GL_LINES); 
	glVertex2f( 0.0 , 0.0 ); 
	glVertex2f( 5 , 0.0 ); 
	glEnd(); 
	
	// eixo y
	glColor3f( 1 , 0 , 0 ); 
	glBegin(GL_LINES); 
	glVertex2f( 0.0 , 0.0 ); 
	glVertex2f( 0.0 , 5); 
	glEnd(); 
	
	//==DESCOMENTAR AQUI PARA TESTAR AS TRANSFORMAÇÕES==
	TestaTranslacao();
	//TestaEscala();
	//TestaRotacao();
}

int main(int argc, char ** argv){
	glutInit(&argc, argv);//Inicialização
	glutInitWindowSize(600,400);//Define tamanho da janela
	glutInitWindowPosition(10,50);//Define posição da janela
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Define o buffer e cores RGB
	glutCreateWindow("Transformacoes"); //Define o nome da janela
	init();
	glutDisplayFunc(display);//Definindo a função callback para o display
	glutMainLoop();//Execução
}
