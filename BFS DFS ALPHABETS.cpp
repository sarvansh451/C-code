#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 26

// Function to perform Breadth-First Search (BFS)
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int start, int vertices) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    printf("BFS Traversal: ");

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%c ", 'A' + currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

// Function to perform Depth-First Search (DFS)
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int start, int vertices, bool visited[MAX_VERTICES]) {
    printf("%c ", 'A' + start);
    visited[start] = true;

    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] && !visited[i]) {
            DFS(graph, i, vertices, visited);
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        char v1, v2;
        scanf(" %c %c", &v1, &v2);
        graph[v1 - 'A'][v2 - 'A'] = 1;
        graph[v2 - 'A'][v1 - 'A'] = 1; // Assuming the graph is undirected
    }

    int startVertex;
    printf("Enter the starting vertex (A, B, C, ...): ");
    char startVertexChar;
    scanf(" %c", &startVertexChar);
    startVertex = startVertexChar - 'A';

    // Perform BFS
    BFS(graph, startVertex, vertices);

    // Reset visited array for DFS
    bool visited[MAX_VERTICES] = {false};

    // Perform DFS
    printf("DFS Traversal: ");
    DFS(graph, startVertex, vertices, visited);
    printf("\n");

    return 0;
}

