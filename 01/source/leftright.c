/* leftright.c  このプログラムの名前 */
#include<stdio.h>
#include"pgmlib.h"

/* 画像 No.1 を左右反転させて画像 No.n2 へ */
void lr_reverse( int n1, int n2 );

int main(void)
{
    load_image( 0, "" );  /* ファイル → 画像No.0 */
    lr_reverse( 0, 1 );   /* No.0 を左右反転して No.1 へ */
    save_image( 1, "" );  /* 画像No.1 → ファイル */
    return 0;
}

void lr_reverse( int n1, int n2 )
/* 画像 No.n1 を左右反転させて画像 No.n2 へ */
{
    int x,y;

    width[n2]=width[n1];  height[n2]=height[n1];
    /* 左右反転 */
    for(y=0;y<height[n1];y++)
        for(x=0;x<width[n1];x++)
            image[n2][x][y] = image[n1][width[n1]-1-x][y];
}
