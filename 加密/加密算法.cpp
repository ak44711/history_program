#include <stdio.h>
#include <mysql/mysql.h>

int main()
{
    //MYSQL句柄
    MYSQL mysql;
    /*用mysql_init初始化MYSQL连接句柄*/
    mysql_init(&mysql);
    /*使用mysql_real_connect连接服务器*/
    if(!mysql_real_connect(&mysql, "localhost", "root", "1234", "mydb", 0, NULL, 0)) {
        printf("Error:%s\n",mysql_error(&mysql));
    }else {
        printf("Connected Mysql successful!\n");
    }
    /*关闭连接*/
    mysql_close(&mysql);
    return 0;
}
