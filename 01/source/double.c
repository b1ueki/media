/* double.c  ���̃v���O�����̖��O */
#include<stdio.h>
#include"pgmlib.h"

/* �摜 No.n1 ���S�{���ĉ摜 No.n2 �� */
void double_image( int n1, int n2 );

int main(void)
{
    load_image( 0, "" );   /* �t�@�C�� �� �摜No.0     */
    double_image( 0, 1 );  /* No.0 ���g�債�� No.1 ��  */
    save_image( 1, "" );   /* �摜No.1 �� �t�@�C��     */
    return 0;
}

void double_image( int n1, int n2 )
/* �摜 No.n1 ���S�{���ĉ摜 No.n2 �� */
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
