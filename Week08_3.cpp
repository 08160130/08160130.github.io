#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
void init()
{
  IplImage * img = cvLoadImage("puipui.jpg");    ///OpenCV讀圖
  cvCvtColor(img,img, CV_BGR2RGB);    ///OpenCV轉色彩 (需要cv.h)
  glEnable(GL_TEXTURE_2D);    ///1. 開啟貼圖功能
  GLuint id;    ///準備一個 unsigned int 整數, 叫 貼圖ID
  glGenTextures(1, &id);    /// 產生Generate 貼圖ID
  glBindTexture(GL_TEXTURE_2D, id);    ///綁定bind 貼圖ID
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
    /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
    /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
    /// 貼圖參數, 放大時的內插, 用最近點
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
    /// 貼圖參數, 縮小時的內插, 用最近點
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
}   ///最後一行最難/最重要, 所貼圖影像的資料都設定好
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glutSolidTeapot(0.3);
  glutSwapBuffers();
}
int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("Week08_2");
    
  init();
    
  glutDisplayFunc(display);
  glutMainLoop(;)
}
