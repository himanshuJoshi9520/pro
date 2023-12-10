
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjacencyList;
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    for (int i = 0; i < numVertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int source, int destination) {
    struct Node* newNode = createNode(destination);
    newNode->next = graph->adjacencyList[source];
    graph->adjacencyList[source] = newNode;

    newNode = createNode(source);
    newNode->next = graph->adjacencyList[destination];
    graph->adjacencyList[destination] = newNode;
}

void bfs(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0;
    }

    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = -1, rear = -1;

    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjacencyList[currentVertex];
        while (temp != NULL) {
            int adjacentVertex = temp->vertex;
            if (!visited[adjacentVertex]) {
                queue[++rear] = adjacentVertex;
                visited[adjacentVertex] = 1;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}

int main() {
    int numVertices, numEdges, source, destination;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    struct Graph* graph = createGraph(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        printf("Enter source and destination for edge %d (space-separated): ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(graph, source, destination);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &source);

    printf("BFS traversal starting from vertex %d: ", source);
    bfs(graph, source);

    return 0;
}
/*Output:
Enter the number of vertices in the graph: 4
Enter the number of edges in the graph: 5
Enter source and destination for edge 1 (space-separated): 0 1
Enter source and destination for edge 2 (space-separated): 0 2
Enter source and destination for edge 3 (space-separated): 1 3
Enter source and destination for edge 4 (space-separated): 2 3
Enter source and destination for edge 5 (space-separated): 3 0
Enter the starting vertex for BFS: 0
BFS traversal starting from vertex 0: 0 1 2 3
*/
