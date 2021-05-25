#include "glm.h"   ///glm.cpp 的外掛
GLMmodel* pmodel = NULL;   ///pmodel 的指標

void drawmodel(void)
{
    if (!pmodel)
    {
		pmodel = glmReadOBJ("data/al.obj");
		if (!pmodel) exit(0);
		glmUnitize(pmodel);
		glmFacetNormals(pmodel);
		glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawmodel();
	glutSwapBuffers();
}

///打光的陣列
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[ ]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[ ]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[ ]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[ ] = { 100.0f };

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
	glutCreateWindow("Week11_08160130");

    ///打光的設定
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glutDisplayFunc(display);
	glutMainLoop();
}
