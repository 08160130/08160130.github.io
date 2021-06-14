float angle=90;
void display(){
    glClearColor( 1,0,0,0);///用來Clear的Color 用紅色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f( 1,1,0 );
        glutSolidTeapot( 0.3 );///身體先註解掉身體,只看手臂
        glPushMatrix();
            glTranslatef(-.3, 0, 0);///(3)再把轉動中的手臂,掛到肩上
            glRotatef(angle, 0,0,1);///(2)再轉動它
            glTranslatef(-.3, .1, 0);///(1)移動旋轉中心,放正中心
            glutSolidTeapot(0.3);///左手臂
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
