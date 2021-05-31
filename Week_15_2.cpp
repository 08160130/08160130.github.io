#include <stdio.h>   ///外掛

int main( int argc, char** argv)
{
    /*
    FILE * fout=NULL;  ///檔案指標 file output 變數
    fout=fopen("檔名txt","w+");  ///開啟檔案,檔名txt,模式write+
    printf("Hello World\n");
    fprintf(fout,"Hello World");
    */

    FILE * fin = NULL;
    fin = fopen("檔名txt","r"); ///開啟檔案,r 讀檔案
    char line[100];   ///宣告字串
    fscanf(fin,"%s",line);   ///讀一個字串
    printf("現在讀到的是 %s \n",line);   ///印出

    fscanf(fin,"%s",line);   ///讀一個字串
    printf("現在讀到的是 %s \n",line);   ///印出
}
