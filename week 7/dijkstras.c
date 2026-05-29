#include <stdio.h>
#define MAX 10
#define INF 9999
int main() {
    int cost[MAX][MAX], distance[MAX];
    int visited[MAX];
    int n, i, j, source, min, nextnode;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &source);
    for(i = 0; i < n; i++) {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }
    distance[source] = 0;
    visited[source] = 1;
    for(i = 1; i < n - 1; i++) {
        min = INF;
        for(j = 0; j < n; j++) {
            if(distance[j] < min && !visited[j]) {
                min = distance[j];
                nextnode = j;
            }
        }
        visited[nextnode] = 1;
        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                if(min + cost[nextnode][j] < distance[j]) {
                    distance[j] =
                        min + cost[nextnode][j];
                }
            }
        }
    }
    printf("\nShortest distances from vertex %d:\n", source);
    for(i = 0; i < n; i++) {
        if(i != source) {
            printf("%d -> %d = %d\n",
                   source, i, distance[i]);
        }
    }
    return 0;
}
