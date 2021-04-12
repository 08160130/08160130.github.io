##用GLUT專案製作貼圖

#include <opencv/highgui.h>
int main()
{
    IplImage * img = cvLoadImage("puipui.jpg");
    cvShowImage("Week08_2讀圖秀圖",img);
    cvWaitKey(0);
}
