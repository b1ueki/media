/* leftright.c  ���̃v���O�����̖��O */
#include<stdio.h>
#include"pgmlib.h"

/* �摜 No.1 �����E���]�����ĉ摜 No.n2 �� */
void lr_reverse( int n1, int n2 );

int main(void)
{
    load_image( 0, "" );  /* �t�@�C�� �� �摜No.0 */
    lr_reverse( 0, 1 );   /* No.0 �����E���]���� No.1 �� */
    save_image( 1, "" );  /* �摜No.1 �� �t�@�C�� */
    return 0;
}

void lr_reverse( int n1, int n2 )
/* �摜 No.n1 �����E���]�����ĉ摜 No.n2 �� */
{
    int x,y;

    width[n2]=width[n1];  height[n2]=height[n1];
    /* ���E���] */
    for(y=0;y<height[n1];y++)
        for(x=0;x<width[n1];x++)
            image[n2][x][y] = image[n1][width[n1]-1-x][y];
}
