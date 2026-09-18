#include <stdio.h>

#define V 4

void printAdjacencyMatrix(int adjMatrix[V][V]) {
    char vertices[] = {'A', 'B', 'C', 'D'};
    
    printf("   ");
    for (int i = 0; i < V; i++) {
        printf("%c  ", vertices[i]);
    }
    printf("\n");

    for (int i = 0; i < V; i++) {
        printf("%c  ", vertices[i]);
        for (int j = 0; j < V; j++) {
            printf("%d  ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printDegrees(int adjMatrix[V][V]) {
    char vertices[] = {'A', 'B', 'C', 'D'};
    
    printf("\nVertex Degrees:\n");
    for (int i = 0; i < V; i++) {
        int degree = 0;
        for (int j = 0; j < V; j++) {
            degree += adjMatrix[i][j];
        }
        printf("Vertex %c -> In = %d, Out = %d\n", vertices[i], degree, degree);
    }
}

int main() {
    int adjMatrix[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };

    printf("Adjacency Matrix:\n");
    printAdjacencyMatrix(adjMatrix);

    printDegrees(adjMatrix);

    return 0;
}
