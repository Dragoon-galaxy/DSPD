#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue structure for BFS
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Graph structure
struct Graph {
    int vertices;
    int** adjacencyMatrix;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->rear == -1)
        return 1;
    return 0;
}

// Function to enqueue an item to the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1)
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Function to dequeue an item from the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
    }
    return item;
}

// Function to create a graph with n vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = n;

    graph->adjacencyMatrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            graph->adjacencyMatrix[i][j] = 0;
    }

    return graph;
}

// Function to add an edge between two vertices in the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;
}

// Function to perform Breadth First Search
void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};

    struct Queue* queue = createQueue();

    visited[startVertex] = 1;
    printf("Visited vertex: %d\n", startVertex);

    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                printf("Visited vertex: %d\n", i);
                enqueue(queue, i);
            }
        }
    }
}

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Breadth First Traversal (starting from vertex 0):\n");
    BFS(graph, 0);

    return 0;
}
