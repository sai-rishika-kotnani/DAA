#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Node {
    int data;
    struct Node* next;
};
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
void topologicalSortUtil(int v, struct Graph* graph, int* visited, struct Node** stack) {
    visited[v] = 1;
    struct Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            topologicalSortUtil(adjVertex, graph, visited, stack);
        }
        temp = temp->next;
    }
    *stack = createNode(v);
    (*stack)->next = graph->adjLists[v];
    graph->adjLists[v] = *stack;
}
void topologicalSort(struct Graph* graph) {
    struct Node* stack = NULL;
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, graph, visited, &stack);
        }
    }
    printf("Topological Sort: ");
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}
int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    struct Graph* graph = createGraph(vertices);
    int i, src, dest;
    for (i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    topologicalSort(graph);
    return 0;
}

