#include <stdio.h>

#define NDEBUG//����д��assertǰ�棬������NDEBUG֮��assert()��ʧЧ 
#include <assert.h> 
#include <stdlib.h>
int main( void )
{
       FILE *fp;
    
       fp = fopen( "test.txt", "w" );//�Կ�д�ķ�ʽ��һ���ļ�����������ھʹ���һ��ͬ���ļ�
       assert( fp );                           //�������ﲻ�����
       fclose( fp );
    
       fp = fopen( "noexitfile.txt", "r" );//��ֻ���ķ�ʽ��һ���ļ�����������ھʹ��ļ�ʧ��
       assert( fp );                           //�����������
       fclose( fp );                           //������Զ��ִ�в���������
       return 0;
}
