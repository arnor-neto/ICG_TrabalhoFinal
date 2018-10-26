#include <GL/gl.h>
#include <GL/glut.h>
#include <OBJ_Loader.h>
#include <butterfly.h>
#include <flower.h>

GLfloat angle = 45.0f;
GLfloat rotation = 0.0;
GLfloat translate = 0.0;

void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluPerspective(angle, 1, 0.1, 1000);
	gluLookAt(0.0f, 10.0f, -15.0f, 0.0f, 0.0f, 30.0f, 0.0f, 1.0f, 0.0f);

	glPushMatrix();

	glColor3f(0.0f, 0.0f, 0.5f);

	//plano de fundo
       
        glBegin (GL_QUADS);

            //glTexCoord2d(0.0f ,0.0f);
            glNormal3f(0.0f, 0.0f, 1.0f);
            glVertex3f(-150, -10, 100);

            //glTexCoord2d(1.0f ,0.0f);
            glNormal3f(0.0f, 0.0f, 1.0f);
            glVertex3f(-150, 100, 100);

            //glTexCoord2d(1.0f ,0.5f);
            glNormal3f(0.0f, 0.0f, 1.0f);
            glVertex3f(150, 100,100);

            //glTexCoord2d(0.0f ,1.0f);
            glNormal3f(0.0f, 0.0f, 1.0f);
            glVertex3f(150, -10, 100);
        glEnd();

    glPopMatrix();

	glColor3f(1.0f, 1.0f, 1.0f);

	//pista

	glBegin(GL_QUADS);
	glVertex3f(6.0f, 0.0f, -5.0f);
	glVertex3f(-6.0f, 0.0f, -5.0f);
	glVertex3f(-6.f, 0.0f, 100.0f);
	glVertex3f(6.0f, 0.0f, 100.0f);
	glEnd();

	glPushMatrix();

	glColor3f(0.0f, 0.5f, 0.0f);

	//grama

	glBegin(GL_QUADS);
	glVertex3f(60.0f, -0.1f, -5.0f);
	glVertex3f(-60.0f, -0.1f, -5.0f);
	glVertex3f(-60.f, -0.1f, 100.0f);
	glVertex3f(60.0f, -0.1f, 100.0f);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	desenhaFlor();

	glPopMatrix();

	glTranslatef(translate, 0.0f, 0.0f);

	glPushMatrix();

	desenhaBorboleta();

	glPopMatrix();

	/*
	//Lado multicolorido - Frente
	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 5.0); // P1 é vermelho
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, 1.0, 5.0); // P2 é verde
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, 1.0, 5.0); // P3 é azul
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-0.5, 0.0, 5.0); // P4 é roxo

	glEnd();

	// Lado branco - TRASEIRA
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.5, 0.0, 6.0);
	glVertex3f(0.5, 1.0, 6.0);
	glVertex3f(-0.5, 1.0, 6.0);
	glVertex3f(-0.5, 0.0, 6.0);
	glEnd();

	// Lado roxo - DIREITA
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, 0.0, 5.0);
	glVertex3f(0.5, 1.0, 5.0);
	glVertex3f(0.5, 1.0, 6.0);
	glVertex3f(0.5, 0.0, 6.0);
	glEnd();

	// Lado verde - ESQUERDA
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.0, 6.0);
	glVertex3f(-0.5, 1.0, 6.0);
	glVertex3f(-0.5, 1.0, 5.0);
	glVertex3f(-0.5, 0.0, 5.0);
	glEnd();

	// Lado azul - TOPO
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 1.0, 6.0);
	glVertex3f(0.5, 1.0, 5.0);
	glVertex3f(-0.5, 1.0, 5.0);
	glVertex3f(-0.5, 1.0, 6.0);
	glEnd();

	// Lado vermelho - BASE
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 5.0);
	glVertex3f(0.5, 0.0, 6.0);
	glVertex3f(-0.5, 0.0, 6.0);
	glVertex3f(-0.5, 0.0, 5.0);
	glEnd();*/

	glutPostRedisplay();

	glutSwapBuffers();
}

void EspecificaParametrosVisualizacao()
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	//gluLookAt(0.0f, 5.0f, 5.0f, 0.0f, 0.0f ,-20.0f , 0.0f ,1.0f ,0.0f);
}

void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN)
		{ // Zoom-in
			if (angle >= 10)
				angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN)
		{ // Zoom-out
			if (angle <= 130)
				angle += 5;
		}
	//EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void setasTeclado(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: // muda a cor corrente para vermelho
		if (translate < 4.5)
			translate += 0.1;
		break;
	case GLUT_KEY_RIGHT: // muda a cor corrente para verde
		if (translate > -4.5)
			translate -= 0.1;
		break;
	case GLUT_KEY_UP: // muda a cor corrente para vermelho
		rotation += 2.0;
		break;
	case GLUT_KEY_DOWN: // muda a cor corrente para verde
		rotation -= 2.0;
		break;
	}
	//EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{

	GLfloat luzAmbiente[4] = {0.4, 0.4, 0.4, 1.0};
	GLfloat luzDifusa[4] = {0.6, 0.6, 0.6, 1.0};	// "cor"
	GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0}; // "brilho"
	GLfloat posicaoLuz[4] = {0.0, 20.0, 0.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4] = {1.0, 1.0, 1.0, 1.0};
	GLint especMaterial = 80;

	// Especifica que a cor de fundo da janela será preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_NORMALIZE);

	//EspecificaParametrosVisualizacao();
}

// Programa Principal
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	EspecificaParametrosVisualizacao();

	glutCreateWindow("Testes openGL");
	glutDisplayFunc(Desenha);
	glutIdleFunc(Desenha);
	glutSpecialFunc(setasTeclado);
	glutMouseFunc(GerenciaMouse);
	Inicializa();
	glutMainLoop();
}