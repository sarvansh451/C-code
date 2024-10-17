#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Number of vertices in the graph
int numVertices;
Node** adjacencyList;

// Function to initialize the adjacency list
void initializeGraph(int vertices) {
    numVertices = vertices;
    adjacencyList = (Node**)malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        adjacencyList[i] = NULL;
    }
}

// Function to add edge
void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    // As it's an undirected graph, add edge from dest to src
    newNode = createNode(src);
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

// Function to print the adjacency list
void printGraph() {
    for (int v = 0; v < numVertices; v++) {
        Node* temp = adjacencyList[v];
        printf("Vertex %d:", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    initializeGraph(5);
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    printGraph();
    return 0;
}
