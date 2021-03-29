##縮短的程式碼

#include <GL/glut.h>
#include <stdio.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///清空矩陣

    glPushMatrix();///備份矩陣
        glRotatef(angle++,0,0,1);///對Z軸旋轉
        glutSolidCube(1);///方塊
    glPopMatrix();///還原矩陣
    glutSwapBuffers();///交換兩倍buffers
}


int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("Week05 drawing");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///Idle很閒的時候，就重複畫面
    glutMainLoop();
}
