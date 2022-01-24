#define true 1 
#define flase 0 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
void main() 
{ 
 char cmdl[80]; 
 char *scwt[]={"exit","dir","time"}; 
 static int cmdnum=3; //可用的命令数
 char cmd[80]; 
 int j , n; 
 while(true) 
 { 
 printf("Please input command: "); 
 gets(cmdl); //取命令行输入
 n=strcspn(cmdl," "); //取命令命令部分
 if (n>0||strlen(cmdl)>0) 
 { strncpy(cmd,cmdl,n); 
 cmd[n]='\0'; 
 for(j=0;j<cmdnum;j++) 
 if (strcmp(cmd,scwt[j])==0) 
 break; 
 if (j==0) //是 exit 命令? 
 exit(0); 
 if (j<cmdnum) //其他合法命令
 { 
 system(cmdl); 
 continue; 
 } 
 printf("Bad command!\n"); //命令错
 } 
 } 
}
