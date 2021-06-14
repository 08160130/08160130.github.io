float oldX=0;
void mouse(int button, int state, int x, int y){
    oldX = x;
}

void motoin( int x, int y ){
    angle += x-oldX;
    oldX = x;//小心,不要漏掉了
    glutPostRedisplay();///重畫畫面
}
