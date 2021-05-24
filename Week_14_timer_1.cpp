#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(0.3,30,30);   ///實心的圓球(半徑,縱切,橫切)
    glutSwapBuffers();
}

int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week14_08160130");

    glutDisplayFunc(display);

    glutMainLoop();

}
