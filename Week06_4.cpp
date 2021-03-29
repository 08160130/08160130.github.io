##掛手臂喔!

#include <GL/glut.h>
#include <stdio.h>
float angle=0;
void hand()
{
    glPushMatrix();
        glScalef(0.5,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///清空矩陣

    glPushMatrix();

        glTranslatef(-0.25,0,0);///把正確轉動的手臂掛在肩膀
        glRotatef(angle,0,0,1);///對Z軸旋轉
        glTranslatef(-0.25,0,0);///把旋轉軸放正中心
        hand();///上手臂
    glPushMatrix();

        glTranslatef(-0.25,0,0);///把正確轉動的手臂掛在肩膀
        glRotatef(angle,0,0,1);///對Z軸旋轉
        glTranslatef(-0.25,0,0);///把旋轉軸放正中心
        hand();///下手肘
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
    angle++;
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
