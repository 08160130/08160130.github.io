#include <GL/glut.h>
int angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidCube(0.3);
    glPopMatrix();
    glutSwapBuffers();
}

void timer(int t)   ///鬧鐘響後timer叫了
{
    glutTimerFunc(30,timer,t+1);   ///再設下一個鬧鐘
    angle++;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week14_08160130");

    glutDisplayFunc(display);
    glutTimerFunc(5000,timer,0);   ///(要等多久,叫誰,參數) 第一個鬧鐘

    glutMainLoop();

}
