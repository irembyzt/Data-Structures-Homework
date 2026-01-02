#include <stdio.h>

#define N 6

int graph[N][N] = {
    {0,1,1,0,0,0},
    {1,0,0,1,0,0},
    {1,0,0,0,1,0},
    {0,1,0,0,0,1},
    {0,0,1,0,0,1},
    {0,0,0,1,1,0}
};

int visited[N];
 
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < N; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}
 
void bfs(int start) {
    int queue[N], front = 0, rear = 0;
    for (int i = 0; i < N; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < N; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {

    for (int i = 0; i < N; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(0);

    printf("\nBFS Traversal: ");
    bfs(0);

    return 0;
}
