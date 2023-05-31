#include <stdio.h>
#include <stdlib.h>

// Graph node
struct Node {
    int value;
    struct Node* next;
};

// Graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// DFS traversal
void dfs(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->value;
        if (!visited[connectedVertex]) {
            dfs(graph, connectedVertex, visited);
        }
        adjList = adjList->next;
    }
}

int main() {
    // Create a graph
    int numVertices = 4;
    struct Graph* graph = createGraph(numVertices);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    // Perform DFS traversal
    int visited[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    printf("DFS traversal starting from node 2:\n");
    dfs(graph, 2, visited);

    return 0;
}
