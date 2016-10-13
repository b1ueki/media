/* double.c  このプログラムの名前 */
#include<stdio.h>
#include"pgmlib.h"

/* 画像 No.n1 を４倍して画像 No.n2 へ */
void double_image( int n1, int n2 );

int main(void)
{
    load_image( 0, "" );   /* ファイル → 画像No.0     */
    double_image( 0, 1 );  /* No.0 を拡大して No.1 へ  */
    save_image( 1, "" );   /* 画像No.1 → ファイル     */
    return 0;
}

void double_image( int n1, int n2 )
/* 画像 No.n1 を４倍して画像 No.n2 へ */
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
