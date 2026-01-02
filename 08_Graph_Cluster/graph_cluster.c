#include <stdio.h>

#define N 7   // Düğüm sayısı
 
int graph[N][N] = {
    {0,1,1,0,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,0,0,0,0},
    {0,0,0,0,1,0,0},
    {0,0,0,1,0,0,0},
    {0,0,0,0,0,0,1},
    {0,0,0,0,0,1,0}
};

int visited[N] = {0};
 
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < N; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int cluster = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cluster++;
            printf("\nCluster %d: ", cluster);
            dfs(i);
        }
    }

    return 0;
}
