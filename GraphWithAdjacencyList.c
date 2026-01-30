#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10
// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};
// Structure for the graph
struct Graph {
    int numVertices;
    struct Node* adjacencyList[MAX_VERTICES];
};
// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
// Function to create a graph
struct Graph* createGraph(int vertices) {
    int i;
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}
// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to display the adjacency list of the graph
void displayGraph(struct Graph* graph) {
    int v;
	for (v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjacencyList[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
// Function to display the adjacency matrix of the graph
void displayAdjacencyMatrix(struct Graph* graph) {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0}, i, j;

    // Fill the adjacency matrix
    for (i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjacencyList[i];
        while (temp) {
            adjacencyMatrix[i][temp->vertex] = 1;
            temp = temp->next;
        }
    }

    // Print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < graph->numVertices; i++) {
        for (j = 0; j < graph->numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}
// Main function
int main() {
    int vertices, edges, src, dest, i;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nAdjacency List of the Graph:\n");
    displayGraph(graph);
    displayAdjacencyMatrix(graph);
    return 0;
}
