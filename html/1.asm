
data SEGMENT ;定义一个数据段存放Hello World!
    hello  DB 'Hello World!$' ;注意要以$结束;DB 指令以表达式的值的字节形式初始化代码空间。

data ENDS


code SEGMENT ;定义一个代码段存放程序指令
    ASSUME CS:CODE,DS:DATA ;告诉汇编程序，DS指向数据段，CS指向代码段
start:
    MOV AX,data  ;将data段首地址赋值给AX，MOV 是数据传输指令             
    MOV DS,AX    ;将AX赋值给DS，使DS指向data段
    LEA DX,hello ;使DX指向hello首地址，LEA取地址
    MOV AH,09h   ;给AH设置参数09H，AH是AX高8位，AL是AX低8位，其它类似
    INT 21h      ;执行DOS中断输出DS指向的DX指向的字符串hello
    MOV AX,4C00h ;给AH设置参数4C00h
    INT 21h      ;调用4C00h号功能，结束程序
code ENDS


END start


GDT_START:
    knull_dsc: dq 0
    ;第一个段描述符CPU硬件规定必须为0
    kcode_dsc: dq 0x00cf9e000000ffff
    ;段基地址=0，段长度=0xfffff
    ;G=1,D/B=1,L=0,AVL=0 
    ;P=1,DPL=0,S=1
    ;T=1,C=1,R=1,A=0
    kdata_dsc: dq 0x00cf92000000ffff
    ;段基地址=0，段长度=0xfffff
    ;G=1,D/B=1,L=0,AVL=0 
    ;P=1,DPL=0,S=1
    ;T=0,C=0,R=1,A=0
GDT_END:

GDT_PTR:
GDTLEN  dw GDT_END-GDT_START-1
GDTBASE  dd GDT_START