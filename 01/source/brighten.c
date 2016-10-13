/* brighten.c  このプログラムの名前 */
#include<stdio.h>
#include"pgmlib.h"

/* 画像 No.n を shift だけ明るくする */
void brighten( int n, int shift );

int main(void)
{
    load_image( 0, "" );  /* ファイル → 画像No.0 */
    brighten( 0, 100 );   /* 画像No.0 の明るさを100上げる */
    save_image( 0, "" );  /* 画像No.0 → ファイル */
    return 0;
}

void brighten( int n, int shift )
/* 画像 No.n を shift だけ明るくする */
{
    int x,y,brightness;

    for(y=0;y<height[n];y++)
        for(x=0;x<width[n];x++){
            brightness = image[n][x][y] + shift;
            if ( brightness > 255 ) brightness = 255;
            image[n][x][y] = brightness;
        }
}
