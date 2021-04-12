##直接用codeblocks開啟貼圖
##記得先上網找圖

#include <opencv/highgui.h>
int main()
{
    IplImage * img = cvLoadImage("puipui.jpg");
    cvShowImage("Week08_1讀圖秀圖",img);
    cvWaitKey(0);
}
