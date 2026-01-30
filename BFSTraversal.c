#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void enqueue(int queue[], int *rear, int value);
int dequeue(int queue[], int *front, int *rear);
void createAdjMatrix(int n, int adjMatrix[n][n], int edges);
void BFS(int startVertex, int n, int adjMatrix[n][n], int visited[n]);

// Function to perform BFS traversal
void BFS(int startVertex, int n, int adjMatrix[n][n], int visited[n]) {
    int queue[n], front = 0, rear = 0, i; // Create a queue

    enqueue(queue, &rear, startVertex); // Enqueue the starting vertex
    visited[startVertex] = 1;

    while (front < rear) {
        int currentVertex = dequeue(queue, &front, &rear);
        printf("Visited %d\n", currentVertex);

        // Explore all adjacent vertices of the current vertex
        for (i = 0; i < n; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(queue, &rear, i);
                visited[i] = 1;
            }
        }
    }
}

// Function to create the adjacency matrix for a directed graph
void createAdjMatrix(int n, int adjMatrix[n][n], int edges) {
    int u, v, i, j;

    // Initialize adjacency matrix with 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter the edges (u v) where there is a directed edge from u to v (0-based index):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1; // Directed edge from u to v
    }
}

// Function to enqueue an element into the queue
void enqueue(int queue[], int *rear, int value) {
    queue[*rear] = value;
    (*rear)++;
}

// Function to dequeue an element from the queue
int dequeue(int queue[], int *front, int *rear) {
    int dequeuedValue = queue[*front];
    (*front)++;
    return dequeuedValue;
}

// Main function
int main() {
    int n, edges, startVertex, i;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Declare adjacency matrix and visited array
    int adjMatrix[n][n], visited[n];

    // Initialize visited array to 0
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Create adjacency matrix
    createAdjMatrix(n, adjMatrix, edges);

    // Input starting vertex
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Perform BFS
    printf("\nBFS Traversal starting from vertex %d:\n", startVertex);
    BFS(startVertex, n, adjMatrix, visited);
    return 0;
}
