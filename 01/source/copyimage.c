/* copyimage.c  このプログラムの名前 */
#include<stdio.h>
#include"pgmlib.h"  /* 階調画像用ライブラリのインクルード */

int main(void)
{
    load_image( 0, "" ); /* 画像No.0にファイルから画像を読み込む */
    save_image( 0, "" ); /* 画像No.0の画像をファイルに出力する   */
    return 0;
}
