#include <stdio.h>
#include <mysql/mysql.h>

int main()
{
    //MYSQL���
    MYSQL mysql;
    /*��mysql_init��ʼ��MYSQL���Ӿ��*/
    mysql_init(&mysql);
    /*ʹ��mysql_real_connect���ӷ�����*/
    if(!mysql_real_connect(&mysql, "localhost", "root", "1234", "mydb", 0, NULL, 0)) {
        printf("Error:%s\n",mysql_error(&mysql));
    }else {
        printf("Connected Mysql successful!\n");
    }
    /*�ر�����*/
    mysql_close(&mysql);
    return 0;
}
