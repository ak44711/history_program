#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct Edge{
	int from;
	int next;//edge[i].next
	int to;//edge[i].to表示第i条边的终点
	int w;//这条边的权重位w 
}edge[100];
int head[100];
int cnt;
int n, vs;
/*head[i]表示以i为起点的第一条边存储的位置,
实际上你会发现这里的第一条边存储的位置其实
在以i为起点的所有边的最后输入的那个编号*/
bool visited[100] = {false};
/*
void DFS(int v) {
	traveled[v] = true;
	for(int j = head[v]; j != -1; j = edge[j].next){
		if(traveled[edge[j].to] == false){
			printf("%d - %d - %d \n", edge[j].from, edge[j].w, edge[j].to);
			DFS(edge[j].to);
		}
	}
	traveled[v] = false;
} */
void DFS(int n){
    if(visited[n] == 0){
        printf(" %d ", n);
    }
    visited[n] = 1; //表示访问过了
    for(int i=head[n]; i!=-1; i=edge[i].next){
        if(!visited[edge[i].to]){
            DFS(edge[i].to);
        }
    }
}
void DFSTraverse(){
    //初始化访问数组
    for(int i=0; i<vs; i++){
        visited[i] = 0;
    }
    for(int i=0; i<vs; i++){
        if(head[i] != -1 && visited[i] == 0){
            DFS(i);
        }
    }
}
 
void BFS(int v, queue<int>& neibour){
	visited[v] = true;
	for(int j = head[v]; j != -1; j = edge[j].next){
		if(visited[edge[j].to] == false){
			printf("%d - %d - %d \n", edge[j].from, edge[j].w, edge[j].to);
			neibour.push(edge[j].to); 
		}
	}
	visited[v] = false;
}
void bfs(int v);
void add(int u, int v, int w) {
	edge[cnt].from = u;
	edge[cnt].w = w;
	edge[cnt].to = v;//u-v
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void Traverse() {
	for(int i = 1; i <= cnt; i++) {
		if(head[i] == -1) continue;
		printf("head[%d]: ", i);
		for(int j = head[i]; j != -1; j = edge[j].next) {
			printf(", %d - %d", edge[j].from, edge[j].to);
		}
		printf("\n");
	}
}
int main() {
	memset(head, -1, sizeof(head));
	cnt = 1;
	cin >> n >> vs;
	int a,b,c;
	for(int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		add(a,b,c);
		add(b,a,c);
	}
	//Traverse();
	//DFS(1);
	DFSTraverse();
	return 0;
}
/*
6 5
1 2 3
2 3 5
3 4 6
1 3 8
4 1 9
1 5 9
1
*/ 
