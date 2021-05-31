#include <stdio.h>   ///外掛

int main( int argc, char** argv)
{
    FILE * fout=NULL;  ///檔案指標 file output 變數
    fout=fopen("檔名txt","w+");  ///開啟檔案,檔名txt,模式write+

    printf("Hello World\n");
    fprintf(fout,"Hello World");

}
