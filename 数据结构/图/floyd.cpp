#include<iostream>
using namespace std;

const int N = 300;
const int INF = 0x3f3f3f3f;
int G[N][N], n, m;
void Floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}
int main() { 
    int a, b, w, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) G[i][j] = 0;
            else G[i][j] = INF;
        }
    }
    
    while(m--) {
        scanf("%d%d%d", &a, &b, &w);
        G[a][b] = min(w, G[a][b]);
    }
    
    Floyd();
    while(k--) {
        scanf("%d%d", &a, &b);
        if(G[a][b] >= INF / 2) {
            printf("impossible\n");
        }else{
            printf("%d\n", G[a][b]);
        }
    }
    return 0;
}
