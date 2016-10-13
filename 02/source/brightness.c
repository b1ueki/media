/* brightness.c  ���̃v���O�����̖��O */
#include<stdio.h>
#include"pgmlib.h"

int trans_table[256];  /* �ϊ��\�i�O���t�j*/

void trans( int n );
/* �摜No.n�̉摜��ϊ��O���t�ŕϊ����� */

int main(void)
{
    load_image( 0, "" );   /* �t�@�C�� �� �摜No.0 */
    trans( 0 );            /* �摜No.0�摜��Z�x�ϊ� */
    save_image( 0, "" );   /* �摜No.0 �� �t�@�C�� */
    return 0;
}

void trans( int n )
/* �摜No.n�̉摜��ϊ��O���t�ŕϊ����� */
{
    int f;
    int x,y;
    int sft;  /* �V�t�g�� */

    do{
        printf("�V�t�g�� [-128, 128] ����͂��ĉ������F");
        scanf("%d",&sft);
    } while( sft<-128 || sft >128);    
    /* �ϊ��\�i�O���t�j�̐ݒ� */
    for(f=0;f<256;f++){
        trans_table[f] = f + sft;
        if (trans_table[f] > 255) trans_table[f]=255;
        else if (trans_table[f] < 0) trans_table[f]=0;
    }
    /* �e��f�̊K���l��ϊ��\�ɏ]���ĕϊ� */
    for(y=0;y<height[n];y++){
        for(x=0;x<width[n];x++){
            image[n][x][y] = trans_table[ image[n][x][y] ];
        }
    }
}
