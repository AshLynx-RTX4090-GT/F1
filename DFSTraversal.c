#include <stdio.h>
// Function to perform DFS traversal
void DFS(int vertex, int n, int adjMatrix[n][n], int visited[n]) {
    int i;
	visited[vertex] = 1;
    printf("Visited %d\n", vertex);
    // Explore all adjacent vertices
    for (i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) 
		{
            DFS(i, n, adjMatrix, visited);
        }
    }
}
// Function to create the adjacency matrix for a directed graph
void createAdjMatrix(int n, int adjMatrix[n][n], int edges) {
    int u, v, i, j;

    // Initialize the adjacency matrix with 0
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    // Input edges and update the adjacency matrix
    printf("Enter the edges (u v) where there is a directed edge from u to v (0-based index):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1; 
    }
}
int main() {
    int n,i, edges, startVertex;
    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // Input number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    // Declare adjacency matrix and visited array
    int adjMatrix[n][n], visited[n];
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    // Create the adjacency matrix
    createAdjMatrix(n, adjMatrix, edges);
    // Input the starting vertex for DFS
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    // Call DFS function
    printf("DFS Traversal starting from vertex %d:\n", startVertex);
    DFS(startVertex, n, adjMatrix, visited);
    return 0;
}
