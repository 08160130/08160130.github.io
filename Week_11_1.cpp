#include "glm.h"   ///glm.cpp 的外掛
GLMmodel* pmodel = NULL;   ///pmodel 的指標

void drawmodel(void)
{
    if (!pmodel)
    {
		pmodel = glmReadOBJ("data/porsche.obj");
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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
	glutCreateWindow("Week11_08160130");

	glutDisplayFunc(display);
	glutMainLoop();
}
