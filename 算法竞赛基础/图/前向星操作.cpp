#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAXSIZE 100
 
//��ʽǰ���ǵĴ洢�ṹ
struct edge{
    int to;     //ָ���Ǹ�����
    int next;   //ͬ������һ���ߵı��
    int weight; //�ñߵ�Ȩ��
} edges[MAXSIZE];
int head[MAXSIZE];
 
//��head�����ʼ��Ϊ-1
void InitHead(){
    memset(head, -1, sizeof(head));
}
 
int sumE = 0;   //�ߵĲ���ţ���0��ʼ
 
//�ӱ߲���
void addEdge(int st, int ed, int we){
    edges[sumE].to = ed;
    edges[sumE].weight = we;
    edges[sumE].next = head[st];
    head[st] = sumE++;
}
//������ʽǰ���ǽṹ
void Traverse(){
    for(int i=0; i<MAXSIZE; i++){
        if(head[i] != -1){
            printf("head[%d]:", i);
            for(int j=head[i]; j!=-1; j=edges[j].next){
                printf("%d ", edges[j].to);
            }
            printf("\n");
        }
    }
}
 
int visited[MAXSIZE];
 
//������ȱ�������
void DFS(int);
void DFSTraverse(){
    //��ʼ����������
    for(int i=0; i<MAXSIZE; i++){
        visited[i] = 0;
    }
    for(int i=0; i<MAXSIZE; i++){
        if(head[i] != -1 && visited[i] == 0){
            DFS(i);
        }
    }
}
 
void DFS(int n){
    if(visited[n] == 0){
        printf(" %d ", n);
    }
    visited[n] = 1; //��ʾ���ʹ���
    for(int i=head[n]; i!=-1; i=edges[i].next){
        if(!visited[edges[i].to]){
            DFS(edges[i].to);
        }
    }
}
 
 
//�����������
void BFS(int);
void BFSTraverse(){
    //��ʼ����������
    for(int i=0; i<MAXSIZE; i++){
        visited[i] = 0;
    }
    for(int i=0; i<MAXSIZE; i++){
        if(head[i] != -1 && visited[i] == 0){
            BFS(i);
        }
    }
}
 
void BFS(int n){
    queue<int> q;
    q.push(n);
    if(visited[n] == 0)
        printf(" %d ", n);
    visited[n] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=head[v]; i!=-1; i=edges[i].next){
            if(!visited[edges[i].to]){
                printf(" %d ", edges[i].to);
                visited[edges[i].to] = 1;
                q.push(edges[i].to);
            }
        }
    }
}
 
int main(){
    InitHead();
    //��ͼ
    addEdge(1, 2, 1);
    addEdge(1, 3, 1);
    addEdge(1, 4, 1);
    addEdge(2, 4, 1);
    addEdge(2, 5, 1);
    //�����ٴ�һ��
    addEdge(2, 1, 1);
    addEdge(3, 1, 1);
    addEdge(4, 1, 1);
    addEdge(4, 2, 1);
    addEdge(5, 2, 1);
    Traverse();
    printf("DFS: ");
    DFSTraverse();
    printf("\nBFS: ");
    BFSTraverse();
    return 0;
}
