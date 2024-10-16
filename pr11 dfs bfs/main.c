#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int adjMatrix[MAX][MAX];  // Adjacency matrix
int visited[MAX];         // Visited array to keep track of visited nodes
int queue[MAX], front = -1, rear = -1;  // Queue for BFS

// Function to add an edge to the adjacency matrix
void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;  // Directed edge from u to v
}

// BFS implementation
void BFS(int startVertex, int numVertices) {
    int i;
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0;  // Initialize visited array
    }

    front = rear = 0;
    queue[rear] = startVertex;
    visited[startVertex] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Traverse adjacent vertices
        int i;
        for (i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS implementation (Recursive)
void DFS(int vertex, int numVertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    int i;
    for (i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, numVertices);
        }
    }
}
int main() {
    int numVertices, numEdges, u, v, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Initialize adjacency matrix
    int i;
    for (i = 0; i < numVertices; i++) {
        int j;
        for (j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Input edges
    for (i = 0; i < numEdges; i++) {
        printf("Enter the edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter the start vertex for BFS and DFS: ");
    scanf("%d", &startVertex);
    // Perform BFS
    BFS(startVertex, numVertices);

    // Initialize visited array for DFS
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0;  // Reset visited array for DFS
    }

    // Perform DFS
    printf("DFS Traversal: ");
    DFS(startVertex, numVertices);
    printf("\n");

    return 0;
}
