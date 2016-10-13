/* brighten.c  ���̃v���O�����̖��O */
#include<stdio.h>
#include"pgmlib.h"

/* �摜 No.n �� shift �������邭���� */
void brighten( int n, int shift );

int main(void)
{
    load_image( 0, "" );  /* �t�@�C�� �� �摜No.0 */
    brighten( 0, 100 );   /* �摜No.0 �̖��邳��100�グ�� */
    save_image( 0, "" );  /* �摜No.0 �� �t�@�C�� */
    return 0;
}

void brighten( int n, int shift )
/* �摜 No.n �� shift �������邭���� */
{
    int x,y,brightness;

    for(y=0;y<height[n];y++)
        for(x=0;x<width[n];x++){
            brightness = image[n][x][y] + shift;
            if ( brightness > 255 ) brightness = 255;
            image[n][x][y] = brightness;
        }
}
