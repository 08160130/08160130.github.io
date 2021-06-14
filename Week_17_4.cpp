float angle[20]={};   ///先都設成0
int angleID=0;   ///現在要動的關節是誰?

void keyboard(unsigned char key, int x, int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
    if(key=='5') angleID=5;
    if(key=='6') angleID=6;
}   
