/* copyimage.c  ���̃v���O�����̖��O */
#include<stdio.h>
#include"pgmlib.h"  /* �K���摜�p���C�u�����̃C���N���[�h */

int main(void)
{
    load_image( 0, "" ); /* �摜No.0�Ƀt�@�C������摜��ǂݍ��� */
    save_image( 0, "" ); /* �摜No.0�̉摜���t�@�C���ɏo�͂���   */
    return 0;
}
