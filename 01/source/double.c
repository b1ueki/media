/* double.c  ±ÌvOÌ¼O */
#include<stdio.h>
#include"pgmlib.h"

/* æ No.n1 ðS{µÄæ No.n2 Ö */
void double_image( int n1, int n2 );

int main(void)
{
    load_image( 0, "" );   /* t@C ¨ æNo.0     */
    double_image( 0, 1 );  /* No.0 ðgåµÄ No.1 Ö  */
    save_image( 1, "" );   /* æNo.1 ¨ t@C     */
    return 0;
}

void double_image( int n1, int n2 )
/* æ No.n1 ðS{µÄæ No.n2 Ö */
{
    int x,y,i,j;

    width[n2]  = 2 * width[n1];
    height[n2] = 2 * height[n1];
    for(y=0;y<height[n1];y++){
        for(x=0;x<width[n1];x++){
            for(i=0;i<2;i++){
                for(j=0;j<2;j++){
                    image[n2][2*x+j][2*y+i] = image[n1][x][y];
                }
            }
        }
    }
}
