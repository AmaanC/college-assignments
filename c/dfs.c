#include <stdio.h>

int graphValues[5] = {0, 1, 2, 3, 4};
int graph[5][5] = {0};
int visited[5] = {0}; // Meaning of values: 0 = unvisited, 2 = visited

void dfs(int index) {
    // `index` of the starting value

    int i = 0;
    visited[index] = 2; // Visited
    printf("%d, ", graphValues[index]);

    for (i = 0; i < 5; i++) {
        if (graph[index][i] == 1 && visited[i] == 0) {
            // Recursion FTW!
            dfs(i);
        }
    }
}

int main() {
    // Connect the nodes however you want:
    // I've connected them like this http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/graph_representation12.png
    graph[0][1] = 1;
    graph[0][4] = 1;

    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;

    graph[2][1] = 1;
    graph[2][3] = 1;


    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;

    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[4][3] = 1;
    
    dfs(0);

    return 0;
}