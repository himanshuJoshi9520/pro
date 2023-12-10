
/*
NAME: HARSHIT UPRETI
SECTION: A
ROLL NO: 198
UNIVERSITY ROLL NO: 2262011 
*/
#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int destination;
    int weight;
    struct Edge* next;
};

void createGraph(int vertices, int edges, struct Edge* graph[]) {
    int i, source, dest, weight;
    for (i = 0; i < vertices; ++i) {
        graph[i] = NULL;
    }
    for (i = 0; i < edges; ++i) {
        printf("Enter source, destination, and weight for edge %d (space-separated): ", i + 1);
        scanf("%d %d %d", &source, &dest, &weight);

        struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
        newEdge->destination = dest;
        newEdge->weight = weight;
        newEdge->next = graph[source];
        graph[source] = newEdge;
    }
}

void displayGraph(int vertices, struct Edge* graph[]) {
    int i;
    for (i = 0; i < vertices; ++i) {
        struct Edge* current = graph[i];
        printf("Edges from vertex %d: ", i);
        while (current != NULL) {
            printf("(%d, %d) ", current->destination, current->weight);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    struct Edge* graph[vertices];
    createGraph(vertices, edges, graph);
    displayGraph(vertices, graph);
    return 0;
}
/*Output:
Enter the number of vertices in the graph: 4
Enter the number of edges in the graph: 5
Enter source, destination, and weight for edge 1 (space-separated): 0 1 2
Enter source, destination, and weight for edge 2 (space-separated): 0 2 4
Enter source, destination, and weight for edge 3 (space-separated): 1 3 5
Enter source, destination, and weight for edge 4 (space-separated): 2 3 7
Enter source, destination, and weight for edge 5 (space-separated): 3 0 1
Edges from vertex 0: (2, 1) (4, 2)
Edges from vertex 1: (3, 5)
Edges from vertex 2: (3, 7)
Edges from vertex 3: (0, 1)


*/
