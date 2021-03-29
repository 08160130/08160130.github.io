#include <GL/glut.h>
#include <stdio.h>
float angle=0;
int N=0,vx[3000],vy[3000];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///清空矩陣

    glPushMatrix();///備份矩陣
        glRotatef(angle,0,0,1);///對Z軸旋轉
        glScalef(0.5,0.1,0.1);///調成細長的
        glColor3f(0.3,0.3,1.0);///藍色！
        glutSolidCube(1);///方塊

    glPopMatrix();///還原矩陣
    glutSwapBuffers();///交換兩倍buffers
}

void mouse(int buttin,int state,int x,int y)
{

}

void keyboard( unsigned char key,int x,int y)
{

}

void motion(int x,int y)
{
    angle++;///只要mouse在motion時，角度會增加
    display();///增加後，重畫畫面
}

int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("Week05 drawing");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
