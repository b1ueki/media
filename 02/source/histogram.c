/* histogram.c  ���̃v���O�����̖��O */
#include<stdio.h>
#include"pgmlib.h"
long int hist[256]; /* �q�X�g�O�����p�P�����z�� */
void make_histogram( int n );
void make_histogram_image( int h, int n );

int main(void)
{
    load_image( 0, "" );   /* �t�@�C�� �� �摜No.0 */
    make_histogram( 0 );    /* �摜No.0�̃q�X�g�O�����̍쐬 */
    /* �q�X�g�O�����̉摜������ĉ摜No.1�ɕۑ� */
    make_histogram_image( 256, 1 );
    save_image( 1, "" );   /* �摜No.1 �� �t�@�C�� */
    return 0;
}

void make_histogram( int n )
/* �摜No.n �����Ƀq�X�g�O��������� */
{
    int i,x,y;
    
    /* �q�X�g�O�����̏����� */
    for(i=0;i<256;i++) hist[i] = 0;
    /* �摜�����X�^�X�L�������ăO���t����� */
    for(y=0;y<height[n];y++)
        for(x=0;x<width[n];x++)
            hist[ image[n][x][y] ]++; /* �ݐς��P���� */
}

void make_histogram_image( int h, int n )
/* �q�X�g�O�������摜��(��256�~�ch��f)���� */
/* �摜No.n�ɋL�^���� */
{
    int i,x,y;
    long int max; /* �ő�p�x */
    int takasa;   /* �e�K���l�̕p�x�̍��� */
    
    /* �摜�̏c�E���̒l�̓��� */
    width[n]=256;  height[n]=h;
    /* �q�X�g�O�����̍ő�p�xmax�����߂� */
    max=0;
    for(i=0;i<256;i++)
        if ( hist[i] > max ) max = hist[i];
    /* �c����h��f�ɐ��K�����Ȃ���摜�ɒl���� */
    for(x=0;x<width[n];x++){
        takasa = (int)( h / (double)max * hist[x] );
        if ( takasa > h ) takasa = h;
        for(y=0;y<h;y++)
            if ( y < takasa ) image[n][x][h-1-y] = 0;
            else image[n][x][h-1-y] = 255;
    }
}

