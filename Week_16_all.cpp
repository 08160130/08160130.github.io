#include <GL/glut.h>

float angle[20]={},diff=2;   ///angle 都是 0的陣列
int angleID=0;   ///計算現在是第幾個angle

///timer 先休息
/*void timer(int t)
{
    glutTimerFunc(30,timer,t+1);
    angle[angleID] += diff;
    if(angle[angleID]>90) diff = -2;
    if(angle[angleID]<0) diff = +2;
    glutPostRedisplay();   ///有空就redisplay
}*/

#include <stdio.h>
FILE * fout = NULL;
FILE * fin = NULL;   ///準備讀檔
void keyboard(unsigned char key,int x,int y)
{
    if( key=='0' ) angleID=0;   ///timer 會改變關節angle[0]
    if( key=='1' ) angleID=1;   ///timer 會改變關節angle[1]
    if( key=='2' ) angleID=2;   ///timer 會改變關節angle[2]
    if( key=='3' ) angleID=3;   ///timer 會改變關節angle[3]
    if( key=='s' )   ///按s 會存檔
        {
            if( fout == NULL) fout = fopen("angle.txt","w+");   ///如果NULL 就fopen
            ///會存在小黑
            for( int i=0; i<20; i++)   printf("%.2f ", angle[i]);
            printf("\n");
            ///會存在txt檔
            for( int i=0; i<20; i++)   fprintf(fout,"%.2f ", angle[i]);
            fprintf(fout,"\n");
        }
    ///必須關閉fout 或程式關閉 才會更新angle.txt
    if( key=='r') ///讀進來
    {
        if( fin == NULL )fin = fopen("angle.txt","r");
        for( int i=0; i<20; i++)   fscanf(fin,"%f", &angle[i]);
            glutPostRedisplay();
    }
}

int oldX=0 ,oldY=0;
///mouse按下去會記得位置
void mouse( int button, int state , int x, int y)

{
    oldX = x;
    oldY = y;
}

void motion(int x,int y)
{
    angle[angleID] += x - oldX;
    oldX = x;
    glutPostRedisplay();   ///display

    ///邊motion邊存檔
    if( fout == NULL) fout = fopen("angle.txt","w+");   ///如果NULL 就fopen
            ///會存在小黑
            for( int i=0; i<20; i++)   printf("%.2f", angle[i]);
            printf("\n");
            ///會存在txt檔
            for( int i=0; i<20; i++)   fprintf(fout,"%.2f", angle[i]);
            fprintf(fout,"\n");
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glutSolidTeapot(0.3);   ///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle[0],0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot(0.3);   ///左手臂
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotatef(angle[1],0,0,1);
                glTranslatef(-0.3,0,0);
                glutSolidTeapot(0.3);   ///左手肘
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(+0.3,0,0);
            glRotatef(-angle[2],0,0,1);
            glTranslatef(+0.3,0,0);
            glutSolidTeapot(0.3);   ///右手臂
            glPushMatrix();
                glTranslatef(+0.3,0,0);
                glRotatef(-angle[3],0,0,1);
                glTranslatef(+0.3,0,0);
                glutSolidTeapot(0.3);   ///右手肘
            glPopMatrix();
        glPopMatrix();
    glutSwapBuffers();
}

int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week16_08160130");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    ///glutTimerFunc(0,timer,0);
    glutMainLoop();

}
